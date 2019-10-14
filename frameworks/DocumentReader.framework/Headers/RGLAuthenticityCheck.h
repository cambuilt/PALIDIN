#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLAuthenticityElement;

@interface RGLAuthenticityCheck : NSObject

@property(nonatomic, assign, readonly) RGLAuthenticity type;
@property(nonatomic, assign, readonly) RGLCheckResult status;
@property(nonatomic, strong, readonly, nullable) NSArray <RGLAuthenticityElement *> *elements;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (nullable instancetype)init NS_UNAVAILABLE;
- (NSString *_Nonnull)typeName;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
