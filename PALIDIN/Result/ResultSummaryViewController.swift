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
import XLPagerTabStrip

class ResultSummaryViewController: UIViewController, IndicatorInfoProvider {
  
  var tabName: String?
  var documentAuthenticationResponse: DocumentAuthenticationResponse?
  
  @IBOutlet weak var resultTextField: UILabel!
  @IBOutlet weak var resultImage: UIImageView!
  @IBOutlet weak var resultComplexView: UIView!
  
  @IBOutlet weak var facialMatchField: UILabel!
  @IBOutlet weak var facialMatchScoreField: UILabel!
  @IBOutlet weak var documentReaderMatchField: UILabel!
  
  func indicatorInfo(for pagerTabStripController: PagerTabStripViewController) -> IndicatorInfo {
    return IndicatorInfo(title: tabName)
  }
  
  //    required init?(coder aDecoder: NSCoder) {
  //        fatalError("init(coder:) has not been implemented")
  //    }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    self.resultComplexView.layer.borderWidth = 3
    self.resultComplexView.layer.borderColor = UIColor.black.cgColor
    
    if let response = documentAuthenticationResponse {
      
      switch  response.overallAuthenticationResult! {
      case AuthenticationResult.OK.rawValue:
        setResultSuccess()
      case AuthenticationResult.FAILED.rawValue:
        setResultFail()
      default:
        setResultFail()
      }
      
      if let facialMatch = response.biometricsAuthenticationResult?.matchResult {
        facialMatchField.text = "Facial Match: \(facialMatch)"
      }
      if let facialMatchScore = response.biometricsAuthenticationResult?.matchScore {
        facialMatchScoreField.text = "Facial Match Score: \(facialMatchScore)"
      }
      if let documentMatch = response.documentAuthenticationResult?.overallResult {
        documentReaderMatchField.text = "Document Reader Match: \(documentMatch)"
      }
    }
  }
  
  private func setResultFail() {
    resultTextField.text = "Document\nVerification\nFailed"
    resultTextField.textColor = UIColor.red
    resultImage.image = UIImage(named: "verifyFailed")
  }
  
  private func setResultSuccess() {
    resultTextField.text = "Document\nVerification\nSuccess"
    resultTextField.textColor = UIColor.green
    resultImage.image = UIImage(named: "verifySuccess")
  }
}
