#import <Foundation/Foundation.h>

@interface RGLLicense : NSObject

@property(nonatomic, strong, readonly, nullable) NSDate *expiryDate;
@property(nonatomic, strong, readonly, nullable) NSArray <NSString *> *countryFilter;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;

@end
