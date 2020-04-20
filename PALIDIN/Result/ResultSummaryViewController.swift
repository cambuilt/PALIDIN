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
import XLPagerTabStrip

class ResultSummaryViewController: UIViewController, IndicatorInfoProvider {
    
    var tabName: String?
    var documentAuthenticationResponse: DocumentAuthenticationResponse?
    
    @IBOutlet weak var resultTextField: UILabel!
    @IBOutlet weak var resultImage: UIImageView!
    @IBOutlet weak var resultComplexView: UIView!
    
    @IBOutlet weak var facialMatchField: UILabel!
    @IBOutlet weak var facialMatchValue: UILabel!
    @IBOutlet weak var facialMatchScoreField: UILabel!
    @IBOutlet weak var facialMatchScoreValue: UILabel!
    @IBOutlet weak var documentReaderMatchField: UILabel!
    @IBOutlet weak var documentReaderMatchValue: UILabel!
    @IBOutlet weak var issuingStateCode: UILabel!
    @IBOutlet weak var issuingStateCodeBarcode: UILabel!
    @IBOutlet weak var documentNumber: UILabel!
    @IBOutlet weak var documentNumberBarcode: UILabel!
    @IBOutlet weak var documentNumberVisual: UILabel!
    @IBOutlet weak var dateOfExpiry: UILabel!
    @IBOutlet weak var dateOfExpiryBarcode: UILabel!
    @IBOutlet weak var dateOfExpiryVisual: UILabel!
    
    func indicatorInfo(for pagerTabStripController: PagerTabStripViewController) -> IndicatorInfo {
        return IndicatorInfo(title: tabName)
    }

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
                facialMatchValue.text = facialMatch == "OK" ? "✅" : "❌"
            }
            if let facialMatchScore = response.biometricsAuthenticationResult?.matchScore {
                facialMatchScoreValue.text = "\(facialMatchScore)"
            }
            if let documentMatch = response.documentAuthenticationResult?.overallResult {
                documentReaderMatchValue.text = documentMatch == "OK" ? "✅" : "❌"
            }
            if let isc = response.documentAuthenticationResult?.fieldType?[0] {
                issuingStateCode.text = isc.name
                issuingStateCodeBarcode.text = isc.fieldResult?.barcode
            }
            if let dn = response.documentAuthenticationResult?.fieldType?[1] {
                documentNumber.text = dn.name
                documentNumberBarcode.text = dn.fieldResult?.barcode
                documentNumberVisual.text = dn.fieldResult?.visual
            }
            if let doe = response.documentAuthenticationResult?.fieldType?[2] {
                dateOfExpiry.text = doe.name
                dateOfExpiryBarcode.text = doe.fieldResult?.barcode
                dateOfExpiryVisual.text = doe.fieldResult?.visual
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
