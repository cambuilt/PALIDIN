//
//  DocumentConfirmViewController.swift
//  PALIDIN
//
//  Created by Cameron Conway on 10/30/19.
//  Copyright © 2019 aware. All rights reserved.
//

import UIKit

class DocConfirmViewController: UIViewController {
  @IBOutlet weak var frontSideImage: UIImageView!
  @IBOutlet weak var backSideImage: UIImageView!
  public typealias DocProofCaptureCallback = (_ success: Bool, _ message: String?, _ docAndBiometricsCapturedMessage: DocAndBiometricsCapturedMessage?) -> Void
  var docProofCaptureCallback: DocProofCaptureCallback? = {_,_,_ in }
  var docAndBiometricsCapturedMessage = DocAndBiometricsCapturedMessage()
  var frontSideImageString: String?
  var backSideImageString: String?
  var alertController: UIAlertController?
  var spinnerIndicator: UIActivityIndicatorView?
  var isCaptureJustStarted = true
  
  override func viewDidLoad() {
    super.viewDidLoad()
    frontSideImage.image = CommonUtils.convertBase64ToImage(imageString: frontSideImageString!)
    backSideImage.image = CommonUtils.convertBase64ToImage(imageString: backSideImageString!)
  }
  
  
  @IBAction func didTabSelfie(_ sender: Any) {
    startFaceLivenessCapture()
  }
  
  private func startFaceLivenessCapture() {
    initWaitingAlert(message: "Initializing Face Capture")
    self.present(alertController!, animated: true) {
      let faceLivenessCaptureViewController = self.storyboard?.instantiateViewController(withIdentifier: "PassiveFaceLivenessManagerViewController") as! PassiveFaceLivenessManagerViewController
      self.isCaptureJustStarted = false
      faceLivenessCaptureViewController.setCallback(callback: { [unowned self] (error, faceBuffer) in
        if !error, let capturedImage = faceBuffer {
          let dataBeforeCompress = NSData(bytes: capturedImage, length: capturedImage.count)
          let uiimageBeforeCompress = UIImage(data: dataBeforeCompress as Data)!
          let jpgDataAfterCompress = uiimageBeforeCompress.jpegData(compressionQuality: CGFloat(0.7))
          self.docAndBiometricsCapturedMessage.faceBuffer = [UInt8](jpgDataAfterCompress!)
          self.dismiss(animated: true, completion: {
            self.docProofCaptureCallback!(true, nil, self.docAndBiometricsCapturedMessage)
          })
        }
        else {
          self.dismiss(animated: true, completion: {
            self.docProofCaptureCallback!(false, nil, nil)
          })
        }
      })
      self.alertController!.dismiss(animated: true, completion: {
        self.present(faceLivenessCaptureViewController, animated: true, completion: nil)
      })
    }
  }
 
  private func initWaitingAlert(message: String){
    alertController = UIAlertController(title: nil, message: message + "..\n\n", preferredStyle: .alert)
    spinnerIndicator = UIActivityIndicatorView(style: .whiteLarge)
    spinnerIndicator!.center = CGPoint(x:135.0, y: 65.5)
    spinnerIndicator!.color = UIColor.black
    spinnerIndicator!.startAnimating()
    alertController!.view.addSubview(spinnerIndicator!)
  }

}
