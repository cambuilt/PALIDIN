/*
 *  © 2017-2020 Aware, Inc.  All Rights Reserved.
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
import AwDocumentCapture

public class DocReaderDispatchViewController: UIViewController {

    var docAndBiometricsCapturedMessage = DocAndBiometricsCapturedMessage()
    var isCaptureJustStarted = true
    public typealias DocProofCaptureCallback = (_ success: Bool, _ message: String?, _ docAndBiometricsCapturedMessage: DocAndBiometricsCapturedMessage?) -> Void
    var docProofCaptureCallback: DocProofCaptureCallback? = {_,_,_ in }
    public func setDocumentProofCaptureCallback(callback: @escaping DocProofCaptureCallback) {
        self.docProofCaptureCallback = callback
    }
    
    override public func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if isCaptureJustStarted {
            self.isCaptureJustStarted = false
            startAwDocumentCapture()
        } else {
            self.dismiss(animated: true, completion: nil)
        }
    }
    
    public override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.all)
    }
    
    private func startAwDocumentCapture() {
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.landscapeRight, andRotateTo: UIInterfaceOrientation.landscapeRight)
        let scannerViewController = UIStoryboard(name: "AwDocumentCapture", bundle: Bundle.init(identifier: "com.aware.auth.AwDocumentCapture")).instantiateViewController(withIdentifier: "ImageScannerViewController") as! ImageScannerViewController
        
        /* OPTIONAL */
        scannerViewController.setCornerImageScale(scale: 0.8)
        scannerViewController.setFlipImageScale(scale: 0.5)
        scannerViewController.enableCaptureResultView(enable: true)
        scannerViewController.setDisplayHelpContent(content: "Place Document Here")
        
        /*
        scannerViewController.setCornerImageWhileDetecting(image: <#T##UIImage#>)
        scannerViewController.setCornerImageOnDetection(image: <#T##UIImage#>)
        scannerViewController.setFlipImage(image: <#T##UIImage#>)
                
        // Set only if you want to use BioSP server to validate document type during capture. If not set, a local faster validator will be used
        scannerViewController.setDocumentTypeValidationType(useBioSP: true, docValidationURL: CommonConstants.DOC_TYPE_VALIDATION_URL, username: CommonConstants.serviceUsername, password: CommonConstants.servicePassword)
        */
        
        /* REQUIRED */
        scannerViewController.setCompleteCallback { (success: Bool, captureResult: AwDocumentCaptureResult?, errorMessage: String?) in
            if success, let result = captureResult {
                
                self.docAndBiometricsCapturedMessage.documentBuffer = result.images
                self.startFaceLivenessCapture()
                
            }
            else {
                var message: String?
                if let errorMsg = errorMessage {
                    message = errorMsg
                }
                self.dismiss(animated: true, completion: {
                    self.docProofCaptureCallback!(false, message, nil)
                })
            }
        }
        scannerViewController.modalPresentationStyle = .fullScreen
        present(scannerViewController, animated: true)
    }
    
    private func startFaceLivenessCapture() {
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.portrait, andRotateTo: UIInterfaceOrientation.portrait)
        initWaitingAlert(message: "Initializing Face Capture")
        self.present(alertController!, animated: true) {
            let faceLivenessCaptureViewController = self.storyboard?.instantiateViewController(withIdentifier: "PassiveFaceLivenessManagerViewController") as! PassiveFaceLivenessManagerViewController
            faceLivenessCaptureViewController.modalPresentationStyle = .fullScreen
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
}
