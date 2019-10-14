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

import Foundation
import UIKit

class CommonUtils {

    static func convertDocProofCapturedMsgToDocAuthRequest(docAndBiometricsCapturedMessage: DocAndBiometricsCapturedMessage?) -> DocumentAuthenticationRequest? {
        if let docProofMsg = docAndBiometricsCapturedMessage,
            let faceBuffer = docProofMsg.faceBuffer,
            let documentBuffer = docProofMsg.documentBuffer,
            documentBuffer.count > 0 {
            
            var documentAuthenticationRequest = DocumentAuthenticationRequest()
            
            // documents
            var documentsInfo = DocumentsInfo()
            var documentImage = [DocumentImage]()
            for docBuffer in documentBuffer {
                var docImage = DocumentImage()
                docImage.format = ".jpg"
                docImage.lightingScheme = 6
                guard let docImageBase64String = CommonUtils.convertBytesArrayToBase64String(bytesArray: docBuffer) else {return nil}
                docImage.image = docImageBase64String
                documentImage.append(docImage)
            }
            documentsInfo.documentImage = documentImage
            
            // facial
            let biometricsInfo = BiometricsInfo()
            var facialImage = FacialImage()
            guard let facialImageBase64String = CommonUtils.convertBytesArrayToBase64String(bytesArray: faceBuffer) else {return nil}
            facialImage.image = facialImageBase64String
            biometricsInfo.facialImage = facialImage
            
            // form request
            documentAuthenticationRequest.documentsInfo = documentsInfo
            documentAuthenticationRequest.biometricsInfo = biometricsInfo
            return documentAuthenticationRequest
        }
        return nil
    }
    
    static func convertBytesArrayToBase64String(bytesArray: [UInt8]) -> String? {
        let originalData = NSData(bytes: bytesArray, length: bytesArray.count)
        let base64Data = originalData.base64EncodedData(options: NSData.Base64EncodingOptions.endLineWithLineFeed)
        let base64String = String(data: base64Data, encoding: String.Encoding.utf8)
        return base64String
    }
    
    //
    // Convert UIImage to a base64 representation
    //
    class func convertImageToBase64(image: UIImage) -> String {
        let imageData = image.pngData()!
        return imageData.base64EncodedString(options: Data.Base64EncodingOptions.lineLength64Characters)
    }
    
    //
    // Convert a base64 representation to a UIImage
    //
    class func convertBase64ToImage(imageString: String) -> UIImage {
        let imageData = Data(base64Encoded: imageString, options: Data.Base64DecodingOptions.ignoreUnknownCharacters)!
        return UIImage(data: imageData)!
    }
}
