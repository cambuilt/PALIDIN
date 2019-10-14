#import <Foundation/Foundation.h>

@class RGLCertificateData;

@interface RGLSecurityObjectCertificates : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLCertificateData *securityObject;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
