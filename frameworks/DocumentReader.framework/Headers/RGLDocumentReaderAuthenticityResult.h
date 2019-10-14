#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLAuthenticityCheck;

@interface RGLDocumentReaderAuthenticityResult : NSObject

@property(nonatomic, assign, readonly) RGLCheckResult status;
@property(nonatomic, strong, readonly, nullable) NSArray <RGLAuthenticityCheck *> *checks;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
