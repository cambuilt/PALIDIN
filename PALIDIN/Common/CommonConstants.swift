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

class CommonConstants {

    static let BASE_SERVER_HOST = "https://auth.aware.com:8443/BioSP/rest"
    static let serviceUsername = "knomi"
    static let servicePassword = "NVU!497#"
    
    static let DOC_AUTH_SERVICE_BASE = BASE_SERVER_HOST + "/documentAuthenticationService"
    static let VERIFY_DOCUMENTS_AND_BIOMETRICS_URL = DOC_AUTH_SERVICE_BASE + "/verifyDocumentsAndBiometrics"
    
    static let LIVENESS_CHECK_SERVICE_BASE = BASE_SERVER_HOST + "/livenessAnalyzerService"
    static let ANALYZE_VIDEO_URL = LIVENESS_CHECK_SERVICE_BASE + "/analyze_video"
    
    static let defaultDisplayMode: String = "standard"
    static let defaultWorkflow: String = "Charlie4"
    static let defaultVideoLivenessThreshold: Double = 50.0
}
