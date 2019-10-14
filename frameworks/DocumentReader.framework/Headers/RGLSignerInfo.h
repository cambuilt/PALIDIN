#import <Foundation/Foundation.h>

@class RGLAuthority, RGLExtension, RGLCertificateChain, RGLRfidValue;

@interface RGLSignerInfo : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *dataToHash;
@property(nonatomic, strong, readonly, nonnull) NSString *digestAlgorithm;
@property(nonatomic, assign, readonly) double paStatus;
@property(nonatomic, strong, readonly, nonnull) NSString *signatureAlgorithm;
@property(nonatomic, assign, readonly) NSInteger version;
@property(nonatomic, strong, readonly, nonnull) RGLAuthority *issuer;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *serialNumber;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *signature;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLExtension *> *signedAttributes;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *subjectKeyIdentifier;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLCertificateChain *> *certificateChain;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
