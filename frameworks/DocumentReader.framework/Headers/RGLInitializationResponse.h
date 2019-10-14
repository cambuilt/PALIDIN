#import <Foundation/Foundation.h>

@interface RGLInitializationResponse : NSObject

@property (nonatomic, assign, readonly) BOOL status;
@property (nonatomic, strong, readonly) NSString *message;
@property (nonatomic, assign, readonly) BOOL showLogo;
@property (nonatomic, assign, readonly) BOOL rfidAvailable;

- (instancetype)initWithJSON:(NSDictionary *)json;
+ (instancetype)initWithJSON:(NSDictionary *)json;

@end
