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

class DocReaderMainViewController: UIViewController {

    var alertController: UIAlertController?
    var spinnerIndicator: UIActivityIndicatorView?
    @IBOutlet weak var labelTitle: UILabel!
    @IBOutlet weak var buttonID: UIButton!
  
    override func viewWillAppear(_ animated: Bool) {
        self.navigationController?.setNavigationBarHidden(true, animated: true)
        super.viewWillAppear(animated)
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.portrait, andRotateTo: UIInterfaceOrientation.portrait)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        self.navigationController?.setNavigationBarHidden(false, animated: true)
        super.viewWillDisappear(true)
        AppDelegate.AppUtility.lockOrientation(UIInterfaceOrientationMask.all)
    }

    @IBAction func startCameraCaptureBtnPressed(_ sender: UIButton) {

        let dispatchViewController = self.storyboard?.instantiateViewController(withIdentifier: "DispatchViewController") as! DocReaderDispatchViewController

        dispatchViewController.setDocumentProofCaptureCallback { (success, message, docProofCapturedMessage) in
            if success {
                if let docProofCapturedMessage = docProofCapturedMessage {
                    if let docAuthenticationRequest = CommonUtils.convertDocProofCapturedMsgToDocAuthRequest(docAndBiometricsCapturedMessage: docProofCapturedMessage) {
                        self.initWaitingAlert(message: "Waiting for result")
                        DispatchQueue.main.async {
                            self.present(self.alertController!, animated: true, completion: {
                                DocAuthHandler.sendAuthenticationRequest(docAuthenticationRequest: docAuthenticationRequest) {
                                    (success: Bool, response: DocumentAuthenticationResponse?, errorMessage: String?) in
                                    DispatchQueue.main.async {
                                        self.alertController?.dismiss(animated: true, completion: {
                                            if success, let documentAuthenticationResponse = response {
                                                DispatchQueue.main.async {
                                                    self.displayResultViewController(documentAuthenticationResponse: documentAuthenticationResponse)
                                                }
                                            }
                                            else {
                                                self.showAlert(status: errorMessage!, error: true)
                                            }
                                        })
                                    }
                                }
                            })
                        }
                    }
                    
                }
            }
            else {
                // TODO: change success/message to code, which will combine them together
                if let errorMessage = message, errorMessage == "Cancel" {
                    // user canceled, do nothing
                    print("Capture canceled by user")
                }
                else{
                    self.showAlert(status: "Document Capture Failed", error: true)
                }
            }
        }
        self.present(dispatchViewController, animated: true, completion: nil)
    }

    private func displayResultViewController(documentAuthenticationResponse: DocumentAuthenticationResponse) {
        let resultContainerViewController = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "ResultContainerViewController") as! ResultContainerViewController
        resultContainerViewController.documentAuthenticationResponse = documentAuthenticationResponse
        resultContainerViewController.navigationItem.rightBarButtonItem = nil
        self.navigationController?.pushViewController(resultContainerViewController, animated: false)
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
    
    private func initWaitingAlert(message: String){
        alertController = UIAlertController(title: nil, message: message + "..\n\n", preferredStyle: .alert)
        spinnerIndicator = UIActivityIndicatorView(style: .whiteLarge)
        spinnerIndicator!.center = CGPoint(x:135.0, y: 65.5)
        spinnerIndicator!.color = UIColor.black
        spinnerIndicator!.startAnimating()
        alertController!.view.addSubview(spinnerIndicator!)
    }
}

