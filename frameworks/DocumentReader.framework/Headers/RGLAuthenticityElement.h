#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@interface RGLAuthenticityElement : NSObject

@property(nonatomic, assign, readonly) RGLCheckResult status;
@property(nonatomic, assign, readonly) RGLSecurityFeatureType elementType;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
