#import <Foundation/Foundation.h>
#import "RGLRfidNotify.h"

@class RGLAccessControlProcedureType, RGLApplication, RGLSecurityObject, RGLCardProperties;

@interface RGLRFIDSessionData : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLAccessControlProcedureType *> *accessControls;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLApplication *> *applications;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLSecurityObject *> *securityObjects;
@property(nonatomic, strong, readonly, nonnull) RGLCardProperties *cardProperties;
@property(nonatomic, assign, readonly) NSInteger totalBytesReceived;
@property(nonatomic, assign, readonly) NSInteger totalBytesSent;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes status;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes extLeSupport;
@property(nonatomic, assign, readonly) double processTime;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
