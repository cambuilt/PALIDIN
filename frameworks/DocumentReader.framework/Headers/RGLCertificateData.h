#import <Foundation/Foundation.h>

@interface RGLCertificateData : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, assign, readonly) NSInteger length;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
