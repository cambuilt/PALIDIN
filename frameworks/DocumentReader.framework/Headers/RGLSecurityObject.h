#import <Foundation/Foundation.h>

@class RGLSignerInfo;

@interface RGLSecurityObject : NSObject

@property(nonatomic, assign, readonly) NSInteger fileReference;
@property(nonatomic, strong, readonly, nonnull) NSString *objectType;
@property(nonatomic, assign, readonly) NSInteger version;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLSignerInfo *> *signerInfos;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
