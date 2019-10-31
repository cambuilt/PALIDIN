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
import AVFoundation
import PassiveFaceLivenessSDK

public class DocReaderDispatchViewController: UIViewController {

    var docAndBiometricsCapturedMessage = DocAndBiometricsCapturedMessage()
    var isCaptureJustStarted = true
    public typealias DocProofCaptureCallback = (_ success: Bool, _ message: String?, _ docAndBiometricsCapturedMessage: DocAndBiometricsCapturedMessage?) -> Void
    var docProofCaptureCallback: DocProofCaptureCallback? = {_,_,_ in }
    public func setDocumentProofCaptureCallback(callback: @escaping DocProofCaptureCallback) {
        self.docProofCaptureCallback = callback
    }
    
    override public func viewWillAppear(_ animated: Bool) {
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.portrait, andRotateTo: UIInterfaceOrientation.portrait)
        super.viewWillAppear(animated)
        
        if isCaptureJustStarted {
            self.isCaptureJustStarted = false
            startDocumentCapture()
        } else {
            self.dismiss(animated: true, completion: nil)
        }
    }
    
    public override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.all)
    }
    
    private func startDocumentCapture() {
        let docReaderViewController = DocReaderViewController(nibName: "DocReaderViewController", bundle: Bundle(for: DocReaderViewController.self))
        docReaderViewController.setCompleteCallback(callback: { [unowned self] (success, message, buffer) in
            if success, let documentBuffer = buffer {
               self.docAndBiometricsCapturedMessage.documentBuffer = documentBuffer
               self.displayDocConfirm()
//                 self.startFaceLivenessCapture()
            }
            else {
                var errorMessage: String?
                if let message = message {
                    errorMessage = message
                }
                self.dismiss(animated: true, completion: {
                    self.docProofCaptureCallback!(false, errorMessage, nil)
                })
            }
        })
        self.present(docReaderViewController, animated: true, completion: nil)
    }
  
    private func displayDocConfirm() {
      self.docAndBiometricsCapturedMessage.faceBuffer = self.docAndBiometricsCapturedMessage.documentBuffer![0]
      if let docAuthenticationRequest = CommonUtils.convertDocProofCapturedMsgToDocAuthRequest(docAndBiometricsCapturedMessage: self.docAndBiometricsCapturedMessage) {
        if let docConfirmViewController = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "DocConfirmViewController") as? DocConfirmViewController {
          if let frontImage = docAuthenticationRequest.documentsInfo!.documentImage![0].image, let backImage = docAuthenticationRequest.documentsInfo!.documentImage![1].image {
            docConfirmViewController.frontSideImageString = frontImage
            docConfirmViewController.backSideImageString = backImage
            docConfirmViewController.setCallback(callback: { [unowned self] (error) in
              if !error {
                self.dismiss(animated: true, completion: {
                  self.docProofCaptureCallback!(true, nil, self.docAndBiometricsCapturedMessage)
                })
              }
            })
            self.present(docConfirmViewController, animated: true, completion: nil)
          }
        }
      }
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
  
    func showAlert(status: String, error: Bool) {
      var title: String = "Status"
      if error {
        title = "Error"
      }
      let alert = UIAlertController(title: title,
                                    message: status,
                                    preferredStyle: UIAlertController.Style.alert)
      alert.addAction(UIAlertAction(title: "Ok", style: UIAlertAction.Style.default, handler: nil))
      self.present(alert, animated:true, completion: nil)
    }
  
    private func displayResultViewController(documentAuthenticationResponse: DocumentAuthenticationResponse) {
      let resultContainerViewController = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "ResultContainerViewController") as! ResultContainerViewController
      resultContainerViewController.documentAuthenticationResponse = documentAuthenticationResponse
      resultContainerViewController.navigationItem.rightBarButtonItem = nil
      self.navigationController?.pushViewController(resultContainerViewController, animated: true)
    }
}
