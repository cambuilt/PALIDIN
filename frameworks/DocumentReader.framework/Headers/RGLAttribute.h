#import <Foundation/Foundation.h>

@class RGLRfidValue;

@interface RGLAttribute : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *type;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *value;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
