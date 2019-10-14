#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderResults.h"

@interface RGLDocumentReaderValue : NSObject

@property(nonatomic, assign, readonly) RGLResultType sourceType;
@property(nonatomic, strong, readonly, nonnull) NSString *value;
@property(nonatomic, strong, readonly, nonnull) NSString *originalValue;
@property(nonatomic, assign, readonly) CGRect boundRect;
@property(nonatomic, assign, readonly) RGLFieldVerificationResult validity;
@property(nonatomic, strong, readonly, nonnull) NSDictionary <NSNumber *, NSNumber *> *comparison;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
