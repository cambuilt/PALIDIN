#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderResults.h"

@interface RGLDocumentReaderJsonResultGroup : NSObject

@property(nonatomic, assign, readonly) RGLResultType resultType;
@property(nonatomic, assign, readonly) NSInteger lightType;
@property(nonatomic, assign, readonly) NSInteger pageIdx;
@property(nonatomic, strong, readonly, nonnull) NSString *jsonResult;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
