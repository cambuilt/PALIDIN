#import <Foundation/Foundation.h>

@class RGLRfidValue;

@interface RGLValidity : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *notAfter;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *notBefore;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
