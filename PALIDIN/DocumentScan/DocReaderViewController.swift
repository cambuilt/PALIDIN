/*
 *  © 2017-2019 Aware, Inc.  All Rights Reserved.
 *
 *  NOTICE:  All information contained herein is, and remains the property of Aware, Inc.
 *  and its suppliers, if any.  The intellectual and technical concepts contained herein
 *  are proprietary to Aware, Inc. and its suppliers and may be covered by U.S. and
 *  Foreign Patents, patents in process, and are protected by trade secret or copyright law.
 *  Dissemination of this information or reproduction of this material is strictly forbidden
 *  unless prior written permission is obtained from Aware, Inc.
 */

import UIKit
import DocumentReader
extension UIImage {
  func pixelData() -> [UInt8]? {
    let size = self.size
    let dataSize = size.width * size.height * 4
    var pixelData = [UInt8](repeating: 0, count: Int(dataSize))
    let colorSpace = CGColorSpaceCreateDeviceRGB()
    let context = CGContext(data: &pixelData,
                            width: Int(size.width),
                            height: Int(size.height),
                            bitsPerComponent: 8,
                            bytesPerRow: 4 * Int(size.width),
                            space: colorSpace,
                            bitmapInfo: CGImageAlphaInfo.noneSkipLast.rawValue)
    guard let cgImage = self.cgImage else { return nil }
    context?.draw(cgImage, in: CGRect(x: 0, y: 0, width: size.width, height: size.height))
    
    return pixelData
  }
}

class DocReaderViewController: UIViewController {
  
  //    var docReader: DocReader?
  var isCaptureJustStarted = true
  var closedByUser = false
  var alertController: UIAlertController?
  var spinnerIndicator: UIActivityIndicatorView?
  
  private func initWaitingAlert(message: String){
    alertController = UIAlertController(title: nil, message: message + "..\n\n", preferredStyle: .alert)
    spinnerIndicator = UIActivityIndicatorView(style: .whiteLarge)
    spinnerIndicator!.center = CGPoint(x:135.0, y: 65.5)
    spinnerIndicator!.color = UIColor.black
    spinnerIndicator!.startAnimating()
    alertController!.view.addSubview(spinnerIndicator!)
  }
  
  public typealias DocReaderCompleteCallback = (_ success: Bool, _ message: String?, _ documentBuffer: [[UInt8]]?) -> Void
  var docReaderCompleteCallback: DocReaderCompleteCallback? = {_,_,_ in }
  func setCompleteCallback(callback: @escaping DocReaderCompleteCallback) {
    docReaderCompleteCallback = callback
  }
  
  override func viewWillAppear(_ animated: Bool) {
    super.viewWillAppear(animated)
    if isCaptureJustStarted && closedByUser == false {
      initWaitingAlert(message: "Initializing Document Reader")
      self.present(self.alertController!, animated: true) {
        self.initializationReader()
      }
    }
  }
  
  func initializationReader() {
    //initialize license
    guard let dataPath = Bundle.main.path(forResource: "regula.license", ofType: nil) else { return }
    guard let licenseData = try? Data(contentsOf: URL(fileURLWithPath: dataPath)) else { return }
    
    DispatchQueue.global().async {
      
      DocReader.shared.prepareDatabase(databaseID: "Full", progressHandler: { (progress) in
        let progressValue = String(format: "%.1f", progress.fractionCompleted * 100)
        print("Downloading database: \(progressValue)%")
      }, completion: { (successfull, error) in
        DocReader.shared.initializeReader(license: licenseData) { (successfull, error) in
          DispatchQueue.main.async {
            if successfull {
              
              DocReader.shared.processParams.scenario = "Locate"
              DocReader.shared.processParams.multipageProcessing = true
              
              DocReader.shared.customization.cameraFrameShapeType = CameraFrameShapeType.corners
              DocReader.shared.customization.cameraFrameLineLength = 100
              DocReader.shared.customization.statusPositionMultiplier = 0.5
              
              DocReader.shared.customization.cameraFrameBorderWidth = 5
              DocReader.shared.customization.showStatusMessages = false
              
              DocReader.shared.functionality.orientation = UIInterfaceOrientationMask.landscape
              DocReader.shared.functionality.videoCaptureMotionControl = false
              DocReader.shared.functionality.showTorchButton = false
              DocReader.shared.functionality.showSkipNextPageButton = false
              
              /*
               // help image before capturing
               RGLDocReader.shared().customization.showHelpAnimation = true
               RGLDocReader.shared().customization.helpAnimationImage = UIImage(named: "aware_logo_c.png")
               */
              
              // multipage animation image
              DocReader.shared.customization.multipageAnimationFrontImage = UIImage(named: "Rotate_Document")
              DocReader.shared.customization.multipageAnimationBackImage = UIImage(named: "Rotate_Document")
              
              // setting up rotation images;
              /*
               Regula added the following APIs:
               `helpAnimationImageContentMode`, `multipageAnimationFrontImageContentMode`, `multipageAnimationBackImageContentMode`, `borderBackgroundImageContentMode`
               */
              DocReader.shared.customization.multipageAnimationFrontImageContentMode = .center
              
              let apiVersion = DocReader.shared.version?.api
              let coreVersion = DocReader.shared.version?.core
              print("apiVersion: \(apiVersion ?? "")")
              print("coreVersion: \(coreVersion ?? "")")
              
              if self.alertController != nil {
                self.alertController!.dismiss(animated: true, completion: {
                  self.startDocumentCapture()
                })
              }
              else {
                self.startDocumentCapture()
              }
              
            } else {
              let licenseError = error ?? "Unknown error"
              print(licenseError)
            }
          }
        }
      })
    }
  }
  
  private func startDocumentCapture() {
    DocReader.shared.showScanner(self) { (action, result, error) in
      switch action {
      case .cancel:
        print("Cancelled by user")
        self.closedByUser = true
        self.docReaderCompleteCallback!(true, "Cancel", nil)
      case .complete:
        print("Completed")
        self.handleResult(result: result)
      case .error:
        print("Error")
        guard let error = error else { return }
        print("Error string: \(error)")
        self.docReaderCompleteCallback!(true, error, nil)
      case .process:
        guard let result = result else { return }
        print("Scaning not finished. Result: \(result)")
      case .morePagesAvailable:
        print("morePagesAvailable")
      }
    }
  }
  
  func handleResult(result: DocumentReaderResults?) {
    guard let result = result else {
      self.dismiss(animated: true) {
        self.docReaderCompleteCallback!(false, nil, nil)
      }
      return
    }
    var documentBuffer = [[UInt8]]()
    
    
    if let frontImageRaw: UIImage = result.getGraphicFieldImageByType(fieldType: .gf_DocumentImage, source: .rawImage, pageIndex: 0),  let data = frontImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
      documentBuffer.append([UInt8](data))
    }
    
    if let backImageRaw: UIImage = result.getGraphicFieldImageByType(fieldType: .gf_DocumentImage, source: .rawImage, pageIndex: 1),  let data = backImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
      documentBuffer.append([UInt8](data))
    }
    
    //        if let frontImageRaw: UIImage = result.getGraphicFieldImage(by: .documentFront, source: .rawImage), let data = frontImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
    //            documentBuffer.append([UInt8](data))
    //        }
    //        if let backImageRaw: UIImage = result.getGraphicFieldImage(by: .documentRear, source: .rawImage), let data = backImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
    //            documentBuffer.append([UInt8](data))
    //        }
    self.dismiss(animated: true) {
      if documentBuffer.count > 0 {
        self.docReaderCompleteCallback!(true, nil, documentBuffer)
      }
      else {
        self.docReaderCompleteCallback!(false, nil, nil)
      }
    }
  }
}
