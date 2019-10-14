#import <Foundation/Foundation.h>

@class RGLAttribute, RGLRfidValue;

@interface RGLAuthority : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLAttribute *> *attributes;
@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, strong, readonly, nonnull) RGLRfidValue *friendlyName;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
