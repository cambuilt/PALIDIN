#import <Foundation/Foundation.h>

typedef enum {
    RGLRfidNotificationCodesError                        = 0x00010000,
    RGLRfidNotificationCodesDocumentReady                = 0x00010001,
    
    RGLRfidNotificationCodesReadProtocol4                = 0x00010003,
    RGLRfidNotificationCodesReadProtocol3                = 0x0001000A,
    RGLRfidNotificationCodesProgress                     = 0x0001000B,
    
    RGLRfidNotificationCodesPaRequest                    = 0x00013000,  //val = (long)(TPassiveAuthenticationData *)
    
    RGLRfidNotificationCodesTaStep                       = 0x0001000E,  //val = (long)(TTerminalAuthenticationData *)
    
    RGLRfidNotificationCodesSmRequired                   = 0x0001000F,
    RGLRfidNotificationCodesSmEtablished                 = 0x0001400F,
    
    RGLRfidNotificationCodesISOError                     = 0x00011000,
    RGLRfidNotificationCodesPCSCReaderDisconnected       = 0x00020000,
    RGLRfidNotificationCodesPCSCReaderListChanged        = 0x00020001,
    RGLRfidNotificationCodesPCSCReaderListChanging       = 0x00020008,
    
    RGLRfidNotificationCodesPCSCBytesReceived            = 0x00020002,
    RGLRfidNotificationCodesPCSCTotalReadingTime         = 0x00020003,  //ms
    RGLRfidNotificationCodesPCSCDataReceived             = 0x00020004,
    RGLRfidNotificationCodesPCSCBytesSent                = 0x00020005,
    RGLRfidNotificationCodesPCSCTotalReadingSpeed        = 0x00020006,  //val = (int)((float)speed * 1000)  kB/s
    RGLRfidNotificationCodesPCSCTotalProcessTime         = 0x00020007,  //ms
    
    RGLRfidNotificationCodesPCSCExtLengthSupport         = 0x00020010,
    
    RGLRfidNotificationCodesPaCertificateChain           = 0x00020011,  //val = false(start), true(end)
    RGLRfidNotificationCodesPaCertificateChainItem       = 0x00020012,  //val = eRFID_CertificateType
    
    RGLRfidNotificationCodesScenario                     = 0x00020020,  //val - VARIANT * с XML-строкой шага сценария чтения
    //при возврате помещается модифицированная XML-строка с
    //выбранными верхним приложением параметрами шага сценария чтения
    
    //составные коды нотификаций
    RGLRfidNotificationCodesPCSCReadingDatagroup         = 0x00030000,  // + eRFID_DataFile_Type, val = false(start), true(end)
    RGLRfidNotificationCodesPCSCFileNotFound             = 0x00040000,  // + eRFID_DataFile_Type
    RGLRfidNotificationCodesPCSCEndOfFile                = 0x00050000,  // + eRFID_DataFile_Type
    RGLRfidNotificationCodesPCSCFileAccessDenied         = 0x00060000,  // + eRFID_DataFile_Type
    RGLRfidNotificationCodesPCSCApplicationSelected      = 0x00070000,  // + eRFID_Application_Type, val = result
    RGLRfidNotificationCodesACProcedureStart             = 0x00080000,  // + eRFID_AccessControl_ProcedureType
    RGLRfidNotificationCodesACProcedureFinish            = 0x00090000,  // + eRFID_AccessControl_ProcedureType, val = result
    RGLRfidNotificationCodesPASecurityObjectCheck        = 0x000A0000,  // + eRFID_DataFile_Type, val = (RFID_Error_NotPerformed, RFID_Error_NoError, RFID_Error_Failed)
    RGLRfidNotificationCodesPAFileCheck                  = 0x000B0000,  // + eRFID_DataFile_Type, val = result
    RGLRfidNotificationCodesPCSCUpdatingDatagroup        = 0x000C0000,  // + eRFID_DataFile_Type
    RGLRfidNotificationCodesAuxiliaryDataValidation      = 0x000D0000,  // + eRFID_AuxiliaryDataType, val = (RFID_Error_NoError, RFID_Error_Failed)
    
    RGLRfidNotificationCodesRISectorID                   = 0x000E0000,  // + eRFID_SectorKeyType
    // val = (long)(TRF_FT_BYTES *) - ссылка на соответствующий
    // TRFID_AccessControlInfo.SpecificData текущего объекта сессии
    // при возврате из callback-функции в поле SectorID->nType
    // необходимо поместить true, если чип отозван
    // в этом случае для TRFID_AccessControlInfo будет сформирован правильный
    // код статуса при возврате из RFID_ExecuteCommand(RFID_Command_Session_AccessControlProc)
    // по умолчанию же чип не считается отозванным (SectorID->nType==0)
    
    RGLRfidNotificationCodesBiometricsEmptyPlaceholder   = 0x000F0000  // + eRFID_DataFile_Type
    // DG3-4, использован пустой шаблон (0x53)
    // Supplement to Doc9303, R7-p1_v2_sIII_0057 и R7-p3_v2_sIII_0011
} RGLRfidNotificationCodes;

typedef NS_ENUM(NSInteger, RGLRfidDataFileType) {
    RGLRfidDataFileTypeUnspecified                 = 0,
    RGLRfidDataFileTypePassportDG1                 = 1,
    RGLRfidDataFileTypePassportDG2                 = 2,
    RGLRfidDataFileTypePassportDG3                 = 3,
    RGLRfidDataFileTypePassportDG4                 = 4,
    RGLRfidDataFileTypePassportDG5                 = 5,
    RGLRfidDataFileTypePassportDG6                 = 6,
    RGLRfidDataFileTypePassportDG7                 = 7,
    RGLRfidDataFileTypePassportDG8                 = 8,
    RGLRfidDataFileTypePassportDG9                 = 9,
    RGLRfidDataFileTypePassportDG10                = 10,
    RGLRfidDataFileTypePassportDG11                = 11,
    RGLRfidDataFileTypePassportDG12                = 12,
    RGLRfidDataFileTypePassportDG13                = 13,
    RGLRfidDataFileTypePassportDG14                = 14,
    RGLRfidDataFileTypePassportDG15                = 15,
    RGLRfidDataFileTypePassportDG16                = 16,
    RGLRfidDataFileTypePassportDG17                = 17,
    RGLRfidDataFileTypePassportDG18                = 18,
    RGLRfidDataFileTypePassportDG19                = 19,
    RGLRfidDataFileTypePassportDG20                = 20,
    RGLRfidDataFileTypePassportSOD                 = 21,
    RGLRfidDataFileTypePassportCVCA                = 22,
    RGLRfidDataFileTypePassportCOM                 = 23,
    RGLRfidDataFileTypeIDDG1                       = 101,
    RGLRfidDataFileTypeIDDG2                       = 102,
    RGLRfidDataFileTypeIDDG3                       = 103,
    RGLRfidDataFileTypeIDDG4                       = 104,
    RGLRfidDataFileTypeIDDG5                       = 105,
    RGLRfidDataFileTypeIDDG6                       = 106,
    RGLRfidDataFileTypeIDDG7                       = 107,
    RGLRfidDataFileTypeIDDG8                       = 108,
    RGLRfidDataFileTypeIDDG9                       = 109,
    RGLRfidDataFileTypeIDDG10                      = 110,
    RGLRfidDataFileTypeIDDG11                      = 111,
    RGLRfidDataFileTypeIDDG12                      = 112,
    RGLRfidDataFileTypeIDDG13                      = 113,
    RGLRfidDataFileTypeIDDG14                      = 114,
    RGLRfidDataFileTypeIDDG15                      = 115,
    RGLRfidDataFileTypeIDDG16                      = 116,
    RGLRfidDataFileTypeIDDG17                      = 117,
    RGLRfidDataFileTypeIDDG18                      = 118,
    RGLRfidDataFileTypeIDDG19                      = 119,
    RGLRfidDataFileTypeIDDG20                      = 120,
    RGLRfidDataFileTypeIDDG21                      = 121,
    RGLRfidDataFileTypeDLCOM                       = 150,
    RGLRfidDataFileTypeDLDG1                       = 151,
    RGLRfidDataFileTypeDLDG2                       = 152,
    RGLRfidDataFileTypeDLDG3                       = 153,
    RGLRfidDataFileTypeDLDG4                       = 154,
    RGLRfidDataFileTypeDLDG5                       = 155,
    RGLRfidDataFileTypeDLDG6                       = 156,
    RGLRfidDataFileTypeDLDG7                       = 157,
    RGLRfidDataFileTypeDLDG8                       = 158,
    RGLRfidDataFileTypeDLDG9                       = 159,
    RGLRfidDataFileTypeDLDG10                      = 160,
    RGLRfidDataFileTypeDLDG11                      = 161,
    RGLRfidDataFileTypeDLDG12                      = 162,
    RGLRfidDataFileTypeDLDG13                      = 163,
    RGLRfidDataFileTypeDLDG14                      = 164,
    RGLRfidDataFileTypeDLSOD                       = 165,
    RGLRfidDataFileTypeDLCE                        = 166,
    RGLRfidDataFileTypeDLCVCA                      = 167,
    RGLRfidDataFileTypePACECardAccess              = 200,
    RGLRfidDataFileTypePACECardSecurity            = 201,
    RGLRfidDataFileTypePACEChipSecurity            = 202,
    RGLRfidDataFileTypeMIFAREData                  = 300,
    RGLRfidDataFileTypeMIFAREValidity              = 301,
    RGLRfidDataFileTypeAuthenticityV2              = 302,
    RGLRfidDataFileTypeATR                         = 400,
    RGLRfidDataFileTypeESignPK                     = 500,
    RGLRfidDataFileTypeESignSignedData             = 501,
    RGLRfidDataFileTypeCertificate                 = 600,
    RGLRfidDataFileTypeMasterList                  = 601,
    RGLRfidDataFileTypeDefectList                  = 602,
    RGLRfidDataFileTypeDeviationList               = 603,
    RGLRfidDataFileTypeAppDirectory                = 700,
    RGLRfidDataFileTypeSession                     = 701,
    RGLRfidDataFileTypeLogData                     = 702,
    RGLRfidDataFileTypeChipProperties              = 703,
    RGLRfidDataFileTypeUserDefined                 = 1000
};

typedef enum {
    RGLRfidErrorCodesNoError                          = 0x00000001,
    RGLRfidErrorCodesAlreadyDone                      = 0x00000002,
    
    RGLRfidErrorCodesFailed                           = 0xffffffff,
    
    //  RFID_Error_GraphManager                     = 0x80010000,
    RGLRfidErrorCodesNoChipDetected                   = 0x80010001,
    RGLRfidErrorCodesNotAvailable                     = 0x80010002,
    
    RGLRfidErrorCodesInvalidParameter                 = 0x80010004,
    RGLRfidErrorCodesNotInitialized                   = 0x80010005,
    RGLRfidErrorCodesNotEnoughMemory                  = 0x80010006,
    RGLRfidErrorCodesInvalidDirectory                 = 0x80010008,
    RGLRfidErrorCodesUnknownCommand                   = 0x80010009,
    RGLRfidErrorCodesFileIOError                      = 0x8001000A,
    RGLRfidErrorCodesBusy                             = 0x8001000B,
    RGLRfidErrorCodesOldFirmware                      = 0x8001000C,
    
    RGLRfidErrorCodesPCSCFailed                      = 0x80020000,
    RGLRfidErrorCodesPCSCReaderNotAvailable          = 0x80020001,
    RGLRfidErrorCodesPCSCCantConnectCard             = 0x80020002,
    RGLRfidErrorCodesPCSCCardIsNotConnected          = 0x80020003,
    RGLRfidErrorCodesPCSCOperationCancelled          = 0x80020004,
    RGLRfidErrorCodesPCSCCardIsBusy                  = 0x80020005,
    RGLRfidErrorCodesPCSCFailedSCard                 = 0x80020006,
    RGLRfidErrorCodesPCSCExtLeFailed                 = 0x80020010,  //ошибка операции чтения с исп-ем команд расширенной длины
    
    //необходима активация Secure Messaging
    RGLRfidErrorCodesLayer6SecurityManager              = 0x86000000,
    
    //"Application not found"
    RGLRfidErrorCodesLayer6AppSelectionFailure          = 0x86000001,   // ISO7816_A_03 "Application selection failure"
    
    //"BAC authentication failure"
    RGLRfidErrorCodesLayer6MutualAuthMacFail            = 0x86000100,   // ISO7816_B_01 "Mutual authentication MAC failure"
    RGLRfidErrorCodesLayer6MutualAuthEncFail            = 0x86000101,   // ISO7816_B_02 "Mutual authentication encryption failure"
    RGLRfidErrorCodesLayer6MutualAuthFailure            = 0x86000102,   // ISO7816_B_03 "Mutual authentication failure"
    RGLRfidErrorCodesLayer6MutualAuthFailureData        = 0x86000103,
    
    //"Secure messaging failure"
    RGLRfidErrorCodesLayer6SmDo8eMissing                 = 0x86000200,   // "SM failure – MAC missing"
    RGLRfidErrorCodesLayer6SmDo87Missing                 = 0x86000201,   // "SM failure – cryptogram missing"
    RGLRfidErrorCodesLayer6SmDo99Missing                 = 0x86000202,   // "SM failure – secured status bytes missing"
    RGLRfidErrorCodesLayer6SmMacIncorrect                = 0x86000203,   // "SM failure – incorrect MAC"
    RGLRfidErrorCodesLayer6SmDo87Incorrect               = 0x86000204,   // "SM failure – incorrect cryptogram"
    //RFID_LAYER6_SM_DO85_TLV_INCORRECT           = 0x8600000A,   // неправильный формат DO85 (не TLV)
    
    //ошибки выполнения отдельных APDU
    RGLRfidErrorCodesLayer6NonTlvResponseData           = 0x86000300,   // данные от чипа на команду чтения B1 не обернуты в тэги 0x53 или 0х73
    RGLRfidErrorCodesLayer6WrongRndIccLength            = 0x86000301,   // неверная длина данных от чипа на команду APDU_INS_GET_CHALLENGE
    RGLRfidErrorCodesLayer6IntAuthFailure               = 0x86000302,   // ошибка команды APDU_INS_INTERNAL_AUTHENTICATE
    RGLRfidErrorCodesLayer6MseSetKatFailure             = 0x86000303,   // ошибка команды MSE:Set KAT (Key Agreement Template)
    RGLRfidErrorCodesLayer6MseSetDstFailure             = 0x86000304,   // ошибка команды MSE:Set DST (выбор ключа проверки подписи TA сертификата)
    RGLRfidErrorCodesLayer6PsoCertificateFailure        = 0x86000305,   // ошибка команды проверки сертификата
    RGLRfidErrorCodesLayer6MseSetAtFailure              = 0x86000306,   // ошибка команды MSE:Set AT
    RGLRfidErrorCodesLayer6GetChallengeFailure          = 0x86000307,   // ошибка команды GET CHALLENGE
    RGLRfidErrorCodesLayer6ExtAuthFailure               = 0x86000308,   // ошибка команды APDU_INS_INTERNAL_AUTHENTICATE (External Authentication)
    
    RGLRfidErrorCodesLayer6GeneralAuthFailure           = 0x86000309,   // ошибка команды APDU_INS_INTERNAL_AUTHENTICATE (External Authentication)
    
    //общие ошибки чтения файлов
    RGLRfidErrorCodesLayer6FileNotFound                 = 0x80006A82,   // "File selection failure", "File not found"
    RGLRfidErrorCodesLayer6FileEof1                     = 0x80006282,   // "Reading beyond EOF",     "Unexpected EOF”
    RGLRfidErrorCodesLayer6FileEof2                     = 0x80006B00,   // "Reading beyond EOF",     "Unexpected EOF”
    
    //детали базовых ошибок RFID_LAYER6_MSE_SET_AT_FAILURE и RFID_LAYER6_GENERAL_AUTH_FAILURE
    RGLRfidErrorCodesLayer6IncorrectParams              = 0x80006A80,   // терминал не поддерживает исп-е указанного типа пароля
    // указанный алгоритм не поддерживается
    // ошибка инициализации
    RGLRfidErrorCodesLayer6NoReferenceData              = 0x80006A88,   //
    
    RGLRfidErrorCodesLayer6PwdSuspend                   = 0x800063C1,   // PACE
    RGLRfidErrorCodesLayer6PwdBlocked                   = 0x800063C0,   // PACE
    RGLRfidErrorCodesLayer6PwdDeactivated               = 0x80006283,   // PACE
    
    RGLRfidErrorCodesLayer6PwdBlocked2                  = 0x80006983,   // PACE (ответ General Authenticate), eSign операции
    RGLRfidErrorCodesLayer6PwdDeactivated2              = 0x80006984,   // PACE (ответ General Authenticate),
    // eSign операции :
    //  - eSign-PIN terminated (при RFID_Command_Session_eSign_ChangePIN)
    //  - private key is not terminated (при RFID_Command_Session_eSign_CreatePIN)
    RGLRfidErrorCodesLayer6PwdSuspend2                  = 0x80006985,   // PACE (ответ General Authenticate), eSign операции
    
    RGLRfidErrorCodesLayer6PwdFailed                    = 0x801063C0,   // + N (оставшееся к-во попыток, >1)
    
    
    //**********************************************************************************************************
    // SDK 3.0
    //**********************************************************************************************************
    //-----------------------------------------------------------------------------
    // ошибки команд сессионной работы
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesNotPerformed                          = 0x83000000, //операция не проводилась (в контексте)
    RGLRfidErrorCodesSessionIsClosed                       = 0x83000001, //сессия закрыта, операция невозможна
    RGLRfidErrorCodesSessionTerminalUnsupportedOperation   = 0x83000002, //операция не поддерживается текущим типом терминала
    
    //-----------------------------------------------------------------------------
    // тип терминала
    //-----------------------------------------------------------------------------
    //ошибки команды RFID_Command_Session_SetTerminalType
    RGLRfidErrorCodesSessionTerminalTypeUnknown            = 0x83000010, //неизвестный тип терминала
    RGLRfidErrorCodesSessionTerminalTypeBadCertificate     = 0x83000011, //ошибка чтения/разбора данных сертификата терминала
    
    //ошибки команд работы с открытой сессией
    RGLRfidErrorCodesSessionTerminalTypeNotSet             = 0x83000012, //тип терминала не был установлен для текущей сессии
    
    //-----------------------------------------------------------------------------
    // тип процедуры проверки подлинности
    //-----------------------------------------------------------------------------
    //ошибки команды RFID_Command_Session_SetProcedureType
    RGLRfidErrorCodesSessionProcedureTypeUnknown           = 0x83000013, //неизвестный тип процедуры проверки подлинности
    RGLRfidErrorCodesessionProcedureTypeUnsupported        = 0x83000014, //терминал установленного типа не поддерживает данный тип процедуры
    
    //ошибки команд работы с открытой сессией
    RGLRfidErrorCodesSessionProcedureTypeNotSet            = 0x83000015, //тип процедуры проверки подлинности не был установлен
    
    //-----------------------------------------------------------------------------
    // ключ доступа к данным
    //-----------------------------------------------------------------------------
    //ошибки команды RFID_Command_Session_SetAccessKey
    RGLRfidErrorCodesSessionAccessKeyUnknownType           = 0x83000016, //неизвестный тип ключа доступа
    RGLRfidErrorCodesSessionAccessKeyUnsupportedSMType     = 0x83000017, //неподдерживаемый тип процедуры доступа (базовый SM)
    RGLRfidErrorCodesSessionAccessKeyIncorrectSMType       = 0x83000018, //процедура доступа не допускает исп-е указанного типа ключа
    RGLRfidErrorCodesSession_AccessKey_Restricted          = 0x83000019, //тип ключа не поддерживается указанным ранее типом терминала
    //либо недостаточные права на его использование
    RGLRfidErrorCodesSessionAccessKeyIncorrectData         = 0x8300001A, //некорректные данные самого ключа (пустая либо нулевая строка)
    
    //ошибки команд работы с открытой сессией
    RGLRfidErrorCodesSessionAccessKeyNotSet                = 0x8300001B, //ключ не был установлен для текущей сессии (требуется SM)
    
    //-----------------------------------------------------------------------------
    // операции с паролями eID
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionPwdManagementNotAuthorized     = 0x8300001C, //операция запрещена для текущего терминала
    
    //-----------------------------------------------------------------------------
    // процедура защищённого доступа к данным
    //-----------------------------------------------------------------------------
    //ошибки команды RFID_Command_Session_AccessControlProc
    RGLRfidErrorCodesSessionAccessControlUnknownType       = 0x83000020, //неизвестный тип процедуры
    RGLRfidErrorCodesSessionAccessControlRequiresSM        = 0x83000021, //требуется предварительное открытие защищённой сессии (PACE либо BAC)
    RGLRfidErrorCodesSessionAccessControlRequiresPACE      = 0x83000022, //требуется предварительное открытие защищённой сессии (PACE)
    RGLRfidErrorCodesSessionAccessControlRequiresCAKeys    = 0x83000023, //требуется выполнение предварительного шага TA -
    //генерация ключей CA (EAC v2) (TCA_SetupParams *)->TA_preliminary_step
    RGLRfidErrorCodesSessionAccessControlRequiresTA        = 0x83000024, //требуется предварительное проведение TA
    RGLRfidErrorCodesSessionAccessControlRequiresCA        = 0x83000025, //требуется предварительное проведение CA
    
    RGLRfidErrorCodesSessionAccessControlIncorrectOptionCA = 0x83000026, //несоответствие выбранного варианта проведения CA на предварительном
    //и основном этапах (TCA_SetupParams *)->nOptionIdx
    //т.е. ключи были сгенерированы с другими параметрами
    
    //отличные от RFID_Error_Failed коды нужны для работы с ReadProtocol4(), где невозможно анализировать
    //состояние объекта сессии в процессе работы, а можно ориентироваться только на общий код возврата
    //точная причина регистрируется в accessControlInfo->Status и в accessControlInfo->Notifications
    //(для RI - в TRFID_AccessControlInfo.SpecificData.nType содержится признак отзыва чипа)
    RGLRfidErrorCodesSessionAccessControlCaFailed         = 0x83000027, //CA не прошла
    RGLRfidErrorCodesSessionAccessControlTaFailed         = 0x83000028, //TA не прошла
    RGLRfidErrorCodesSessionAccessControlAaFailed         = 0x83000029, //AA не прошла
    RGLRfidErrorCodesSessionAccessControlRiFailed         = 0x8300002A, //RI не прошла
    
    //-----------------------------------------------------------------------------
    // процедура пассивной аутентификации
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionPaSignatureCheckFailed         = 0x83000030, //проверка подписи объекта защиты (SO) не прошла
    RGLRfidErrorCodesSessionPaHashCheckFailed              = 0x83000031, //проверка хэша файла не прошла
    
    //-----------------------------------------------------------------------------
    // проверка вспомогательных пользовательских данных
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionInvalidAuxDataDateOfExpiry     = 0x83000040,
    RGLRfidErrorCodesSessionInvalidAuxDataDateOfBirth      = 0x83000041,
    RGLRfidErrorCodesSessionInvalidAuxDataCommunityID      = 0x83000042,
    
    //-----------------------------------------------------------------------------
    // eSign
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionESignRequiresAppSelection      = 0x83000050, //для доступа к функциям требуется выбор приложения eSign
    RGLRfidErrorCodesSessionESignPinNotSet                 = 0x83000051, //необходимо установить значение eSign-PIN для текущей сессии
    RGLRfidErrorCodesSessionESignPinNotVerified            = 0x83000052, //необходимо выполнить верификацию eSign-PIN для текущей сессии
    
    //-----------------------------------------------------------------------------
    // загрузка данных сессии
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionIncorrectData                  = 0x83000060,
    
    //-----------------------------------------------------------------------------
    // групповые коды критических ошибок - + file ID из eRFID_DataFile_Type
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesSessionFileNotEnoughData              = 0x83010000, //нехватает данных для создания объекта ASN.1
    //(file->Notifications содержит errLDS_ASN_NotEnoughData)
    RGLRfidErrorCodesSessionFileIncorrectData              = 0x83020000, //неверные данные для создания объекта ASN.1
    //(file->Notifications содержит errLDS_ASN_IncorrectData)
    RGLRfidErrorCodesSessionFileUnexpectedData             = 0x83030000, //несоответствие структуры объекта описанию ASN.1
    //(file->Notifications содержит errLDS_ASN_Contents_UnexpectedData)
    RGLRfidErrorCodesSessionFileContentsUnexpectedData     = 0x83040000, //несоответствие структуры объекта описанию в контексте файла
    //(file->Notifications содержит errLDS_DG_Contents_UnexpectedData)
    RGLRfidErrorCodesSessionFileWrongTag                   = 0x83050000, //неверное значение тэга группы данных
    //(file->Notifications содержит errLDS_DG_WrongTag)
    RGLRfidErrorCodesSessionFileCantUseData                = 0x83060000, //использование прочитанных данных невозможно
    //(например, реакция на dplStrictISO при наличии каких-то замечаний)
    //(file->Notifications содержит код конкретной ошибки)
    RGLRfidErrorCodesSessionFileCantReadData               = 0x83070000, //ошибка физического чтения данных
    RGLRfidErrorCodesSessionFileAccessDenied               = 0x83080000, //ошибка доступа к защищённым группам данных
    
    //-----------------------------------------------------------------------------
    // новые команды SDK v3.5 - настройка/работа по Layer1-4
    //-----------------------------------------------------------------------------
    RGLRfidErrorCodesLayer34NoError                         = 0x84000000,   //
    RGLRfidErrorCodesLayer34TimeOut                         = 0x84010000,   //time-out
    RGLRfidErrorCodesLayer34Collision                       = 0x84020000,   //collision
    RGLRfidErrorCodesLayer34CRC                             = 0x84030000,   //BCC, CRC (software check)
    RGLRfidErrorCodesLayer34DataIntegrity                   = 0x84040000,   //parity, CRC (hardware check)
    RGLRfidErrorCodesLayer34DataLength                      = 0x84050000,   //неверное к-во принятых байт (по контексту)
    RGLRfidErrorCodesLayer34RFU                             = 0x84060000,   //использование RFU данных
    RGLRfidErrorCodesLayer34CollisionTooMany                = 0x84070000,   //слишком много итераций в цикле антиколлизии
    RGLRfidErrorCodesLayer34ProtocolB                       = 0x84080000,   //ошибки протокола 14443B (stop-bit, SOF, EOF)
    RGLRfidErrorCodesLayer34DataContents                    = 0x84090000,   //неверное содержимое данных (по значению)
    RGLRfidErrorCodesLayer34Protocol                        = 0x840A0000,   //несоблюдение протокола (неверный тип блока, содержимое ответа)
    RGLRfidErrorCodesLayer34GlobalTimeOut                   = 0x840B0000,   //time-out
    RGLRfidErrorCodesLayer34MifareAuth                      = 0x840C0000   //MIFARE Authentication
} RGLRfidErrorCodes;

typedef NS_ENUM(NSInteger, RGLRfidCertificateType) {
  RGLRfidCertificateTypeUndefined  = 0,
  RGLRfidCertificateTypeCSCA       = 1,
  RGLRfidCertificateTypeCSCALink   = 2,
  RGLRfidCertificateTypeDS         = 3,
  RGLRfidCertificateTypeMLS        = 4,
  RGLRfidCertificateTypeDevLS      = 5,
  RGLRfidCertificateTypeDefLS      = 6
};

@interface RGLRfidNotify: NSObject

@property(nonatomic, assign, readonly) UInt32 code;
@property(nonatomic, assign, readonly) double value;
@property(nonatomic, assign, readonly) UInt32 aCode;
@property(nonatomic, assign, readonly) UInt32 number;

- (instancetype)initWithCode:(UInt32)code number:(UInt32)number;

+ (NSString *)rfidDataFileTypeName:(RGLRfidDataFileType)type;
+ (NSString *)rfidErrorCodesName:(RGLRfidErrorCodes)errorCode;

@end
