#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLDocumentReaderTextField;

@interface RGLDocumentReaderTextResult : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderTextField *> *fields;
@property(nonatomic, assign, readonly) RGLCheckResult status;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFields:(NSArray <RGLDocumentReaderTextField *> *_Nonnull)fields status:(RGLCheckResult)status;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
