#import <Foundation/Foundation.h>

typedef enum {
    RGLRfidSdkProfilerTypeDoc9303Edition2006 = 0x00000001,
    RGLRfidSdkProfilerTypeDoc9303LdsPkiMaintenance = 0x00000002
} RGLRfidSdkProfilerType;

typedef NS_ENUM(NSInteger, RGLRfidAuthenticationProcedureType) {
    RGLRfidAuthenticationProcedureTypeUndefined = 0,
    RGLRfidAuthenticationProcedureTypeStandard = 1,
    RGLRfidAuthenticationProcedureTypeAdvanced = 2,
    RGLRfidAuthenticationProcedureTypeGeneral = 3
};

typedef NS_ENUM(NSInteger, RGLRfidAccessControlProcedureType) {
    RRGLRfidAccessControlProcedureTypeUndefined = 0,
    RGLRfidAccessControlProcedureTypeBac = 1,
    RGLRfidAccessControlProcedureTypePace = 2,
    RGLRfidAccessControlProcedureTypeCa = 3,
    RGLRfidAccessControlProcedureTypeTa = 4,
    RGLRfidAccessControlProcedureTypeAa = 5,
    RGLRfidAccessControlProcedureTypeRi = 6,
    RGLRfidAccessControlProcedureTypeCardInfo = 7
};

typedef NS_ENUM(NSInteger, RGLRfidPasswordType) {
    RGLRfidPasswordTypeUnknown = 0,
    RGLRfidPasswordTypeMrz = 1,
    RGLRfidPasswordTypeCan = 2,
    RGLRfidPasswordTypePin = 3,
    RGLRfidPasswordTypePuk = 4,
    RGLRfidPasswordTypePinEsign = 5,
    RGLRfidPasswordTypeSai = 6
};

typedef NS_ENUM(NSInteger, RLGRfidTerminalType) {
    RLGRfidTerminalTypeUndefined = 0,
    RLGRfidTerminalTypeInspectionSystem = 1,
    RLGRfidTerminalTypeAuthenticationTerminal = 2,
    RLGRfidTerminalTypeSignatureTerminal = 3,
    RLGRfidTerminalTypeUnauthenticatedTerminal = 4
};

typedef NS_ENUM(NSInteger, RGLESignManagementAction) {
    RGLESignManagementActionUndefined = 0,
    RGLESignManagementActionCreatePIN = 1,
    RGLESignManagementActionChangePIN = 2,
    RGLESignManagementActionUnblockPIN = 3,
    RGLESignManagementActionTerminatePIN = 4,
    RGLESignManagementActionGenerateKeys = 5,
    RGLESignManagementActionTerminateKeys = 6,
    RGLESignManagementActionSignData = 7
};

@class RGLDataGroup;

@interface RGLRfidScenario : NSObject

@property(nonatomic, assign) RGLESignManagementAction signManagementAction;
@property(nonatomic, assign) int readingBuffer;
@property(nonatomic, assign) int onlineTAToSignDataType;
@property(nonatomic, assign) BOOL onlineTA;
@property(nonatomic, assign) BOOL writeEid;
@property(nonatomic, assign) RGLRfidSdkProfilerType profilerType;
@property(nonatomic, assign) RGLRfidAuthenticationProcedureType authProcType;
@property(nonatomic, assign) RGLRfidAccessControlProcedureType baseSMProcedure;
@property(nonatomic, assign) RGLRfidPasswordType pacePasswordType;
@property(nonatomic, assign) RLGRfidTerminalType terminalType;
@property(nonatomic, assign) BOOL universalAccessRights;
@property(nonatomic, assign) BOOL authorizedRestrictedIdentification;
@property(nonatomic, assign) BOOL auxVerificationCommunityID;
@property(nonatomic, assign) BOOL auxVerificationDateOfBirth;
@property(nonatomic, assign) BOOL skipAA;
@property(nonatomic, assign) BOOL strictProcessing;
@property(nonatomic, assign) BOOL pkdDSCertPriority;
@property(nonatomic, assign) BOOL pkdUseExternalCSCA;
@property(nonatomic, assign) BOOL trustedPKD;
@property(nonatomic, assign) BOOL passiveAuth;
@property(nonatomic, assign) BOOL paceStaticBinding;
@property(nonatomic, strong, nonnull) NSString *password;
@property(nonatomic, assign) BOOL useSFI;
@property(nonatomic, strong, nonnull) NSString *pkdPA;
@property(nonatomic, strong, nonnull) NSString *pkdEAC;
@property(nonatomic, assign) BOOL readEPassport;
@property(nonatomic, assign) BOOL readEID;
@property(nonatomic, assign) BOOL readEDL;
@property(nonatomic, strong, nonnull) RGLDataGroup *ePassportDataGroups;
@property(nonatomic, strong, nonnull) RGLDataGroup *eIDDataGroups;
@property(nonatomic, strong, nonnull) RGLDataGroup *eDLDataGroups;
@property(nonatomic, strong, nonnull) NSString *mrz;
@property(nonatomic, strong, nonnull) NSString *eSignPINDefault;
@property(nonatomic, strong, nonnull) NSString *eSignPINNewValue;
@property(nonatomic, assign) BOOL authorizedSTSignature;
@property(nonatomic, assign) BOOL authorizedSTQSignature;
@property(nonatomic, assign) BOOL authorizedWriteDG17;
@property(nonatomic, assign) BOOL authorizedWriteDG18;
@property(nonatomic, assign) BOOL authorizedWriteDG19;
@property(nonatomic, assign) BOOL authorizedWriteDG20;
@property(nonatomic, assign) BOOL authorizedWriteDG21;
@property(nonatomic, assign) BOOL authorizedVerifyAge;
@property(nonatomic, assign) BOOL authorizedVerifyCommunityID;
@property(nonatomic, assign) BOOL authorizedPrivilegedTerminal;
@property(nonatomic, assign) BOOL authorizedCANAllowed;
@property(nonatomic, assign) BOOL authorizedPINManagment;
@property(nonatomic, assign) BOOL authorizedInstallCert;
@property(nonatomic, assign) BOOL authorizedInstallQCert;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
- (NSDictionary *_Nonnull)rfidScenarioDictionary;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
