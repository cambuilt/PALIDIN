#import <Foundation/Foundation.h>

@interface RGLExtension : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *data;
@property(nonatomic, strong, readonly, nonnull) NSString *type;
- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
