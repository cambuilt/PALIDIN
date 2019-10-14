/*
 *  © 2017-2019 Aware, Inc.  All Rights Reserved.
 *
 *  NOTICE:  All information contained herein is, and remains the property of Aware, Inc.
 *  and its suppliers, if any.  The intellectual and technical concepts contained herein
 *  are proprietary to Aware, Inc. and its suppliers and may be covered by U.S. and
 *  Foreign Patents, patents in process, and are protected by trade secret or copyright law.
 *  Dissemination of this information or reproduction of this materials strictly forbidden
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
    var alertController: UIAlertController?
    var spinnerIndicator: UIActivityIndicatorView?
    
    private func initWaitingAlert(message: String){
        alertController = UIAlertController(title: nil, message: message + "..\n\n", preferredStyle: .alert)
        spinnerIndicator = UIActivityIndicatorView(style: .whiteLarge)
        spinnerIndicator!.center = CGPoint(x:135.0, y: 65.5)
        spinnerIndicator!.color = UIColor.black
        spinnerIndicator!.startAnimating()
        alertController!.view.backgroundColor = #colorLiteral(red: 0.137254902, green: 0.1215686275, blue: 0.1254901961, alpha: 1)
        alertController!.view.addSubview(spinnerIndicator!)
    }
    
    public typealias DocReaderCompleteCallback = (_ success: Bool, _ message: String?, _ documentBuffer: [[UInt8]]?) -> Void
    var docReaderCompleteCallback: DocReaderCompleteCallback? = {_,_,_ in }
    func setCompleteCallback(callback: @escaping DocReaderCompleteCallback) {
        docReaderCompleteCallback = callback
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        view!.backgroundColor = #colorLiteral(red: 0.137254902, green: 0.1215686275, blue: 0.1254901961, alpha: 1)
        if isCaptureJustStarted {
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
            
            RGLDocReader.shared().initializeReader(withLicense: licenseData) { (successfull, error) in
                DispatchQueue.main.async {
                    if successfull {
                    
                        RGLDocReader.shared().processParams.scenario = "Locate"
                        RGLDocReader.shared().processParams.multipageProcessing = true
                    
                        RGLDocReader.shared().customization.cameraFrameShapeType = RGLCameraFrameShapeType.corners
                        RGLDocReader.shared().customization.cameraFrameLineLength = 100
                        RGLDocReader.shared().customization.statusPositionMultiplier = 0.5
                    
                        RGLDocReader.shared().customization.cameraFrameBorderWidth = 5
                        RGLDocReader.shared().customization.showStatusMessages = false
                    
                        RGLDocReader.shared().functionality.orientation = UIInterfaceOrientationMask.landscape
                        RGLDocReader.shared().functionality.videoCaptureMotionControl = false
                        RGLDocReader.shared().functionality.showTorchButton = false
                        RGLDocReader.shared().functionality.showSkipNextPageButton = false

                        /*
                        // help image before capturing
                        RGLDocReader.shared().customization.showHelpAnimation = true
                        RGLDocReader.shared().customization.helpAnimationImage = UIImage(named: "aware_logo_c.png")
                        */
                        
                        // multipage animation image
                        RGLDocReader.shared().customization.multipageAnimationFrontImage = UIImage(named: "Rotate_Document")
                        RGLDocReader.shared().customization.multipageAnimationBackImage = UIImage(named: "Rotate_Document")
                        
                        // setting up rotation images;
                        /*
                         Regula added the following APIs:
                         `helpAnimationImageContentMode`, `multipageAnimationFrontImageContentMode`, `multipageAnimationBackImageContentMode`, `borderBackgroundImageContentMode`
                         */
                        RGLDocReader.shared().customization.multipageAnimationFrontImageContentMode = .center
                        
                        let apiVersion = RGLDocReader.shared().version?.api
                        let coreVersion = RGLDocReader.shared().version?.core
                        print("apiVersion: \(apiVersion)")
                        print("coreVersion: \(coreVersion)")
                        
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

        }
    }
    
    private func startDocumentCapture() {
        RGLDocReader.shared().showScanner(fromPresenter: self) { (action, result, error) in
            switch action {
            case .cancel:
                print("Cancelled by user")
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
    
    func handleResult(result: RGLDocumentReaderResults?) {
        guard let result = result else {
            self.dismiss(animated: true) {
                self.docReaderCompleteCallback!(false, nil, nil)
            }
            return
        }
        var documentBuffer = [[UInt8]]()
        
        if let frontImageRaw: UIImage = result.getGraphicFieldImage(by: .documentFront, source: .rawImage), let data = frontImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
            documentBuffer.append([UInt8](data))
        }
        if let backImageRaw: UIImage = result.getGraphicFieldImage(by: .documentRear, source: .rawImage), let data = backImageRaw.jpegData(compressionQuality: CGFloat(1.0)) {
            documentBuffer.append([UInt8](data))
        }
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
