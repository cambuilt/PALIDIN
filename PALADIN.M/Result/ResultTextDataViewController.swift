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

class ResultTextDataViewController: UIViewController, IndicatorInfoProvider,  UITableViewDelegate, UITableViewDataSource {
    
    var tabName: String?
    var documentAuthenticationResponse: DocumentAuthenticationResponse? {
        didSet {
            self.fieldTypes = documentAuthenticationResponse?.documentAuthenticationResult?.fieldType
        }
    }
    var fieldTypes: [FieldType]?
    
    @IBOutlet weak var fieldTypeNameTitleLabel: UILabel!
    @IBOutlet weak var barcodeTitleLabel: UILabel!
    @IBOutlet weak var ocrTitleLabel: UILabel!
    @IBOutlet weak var barcodeOCRMatchingTitleLabel: UILabel!
    @IBOutlet weak var isValidTitleLabel: UILabel!
    @IBOutlet weak var tableView: UITableView!
    
    func indicatorInfo(for pagerTabStripController: PagerTabStripViewController) -> IndicatorInfo {
        return IndicatorInfo(title: tabName)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.dataSource = self
        self.tableView.delegate = self
        
        fieldTypeNameTitleLabel.text = "Field type"
        barcodeTitleLabel.text = "Barcode"
        ocrTitleLabel.text = "Visual\nOCR"
        barcodeOCRMatchingTitleLabel.text = "Barcode-Visual"
        isValidTitleLabel.text = "Result"
        self.tableView.estimatedRowHeight = 60
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (fieldTypes?.count)!
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "fieldTypeCell", for: indexPath) as! DocumentFieldTypeCellTableViewCell
        let fieldType = self.fieldTypes![indexPath.row]
        cell.fieldTypeNameLabel.text = fieldType.name!
        cell.barcodeLabel.text = fieldType.fieldResult?.barcode != nil ? fieldType.fieldResult?.barcode! : ""
        cell.barcodeLabel.textColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
        cell.ocrLabel.text = fieldType.fieldResult?.visual != nil ? fieldType.fieldResult?.visual! : ""
        cell.ocrLabel.textColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
        cell.barcodeOCRMatchingLabel.text = (fieldType.fieldResult?.visualBarcodeCompareValid == FieldComparisonResult.COMPARE_TRUE.rawValue) ? "✅" : (fieldType.fieldResult?.visualBarcodeCompareValid == FieldComparisonResult.COMPARE_FALSE.rawValue) ? "❌" : "❔"
        cell.barcodeLabel.textColor = (fieldType.fieldResult?.isBarcodeStatusValid == FieldValidationResult.VALIDATE_FALSE.rawValue) ? UIColor.red : UIColor.black
        cell.barcodeLabel.textColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
        cell.ocrLabel.textColor = (fieldType.fieldResult?.isVisualStatusValid == FieldValidationResult.VALIDATE_FALSE.rawValue) ? UIColor.red : UIColor.black
        cell.ocrLabel.textColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
        cell.isValidLabel.text = (fieldType.overallResult == AuthenticationResult.OK.rawValue) ? "✅" : (fieldType.overallResult == AuthenticationResult.FAILED.rawValue) ? "❌" : "❔"
        cell.isValidLabel.textColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
        
        cell.indexPath = indexPath
        return cell
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableView.automaticDimension
    }
}
