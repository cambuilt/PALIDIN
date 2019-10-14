#import <Foundation/Foundation.h>
#import "RGLProcessParams.h"
#import "RGLDocumentReaderBarcodeResult.h"

@class RGLPDF417Info;

@interface RGLDocumentReaderBarcodeField : NSObject

@property(nonatomic, assign, readonly) RGLBarcodeType barcodeType;
@property(nonatomic, assign, readonly) RGLBarcodeResult status;
@property(nonatomic, strong, readonly, nullable) RGLPDF417Info *pdf417Info;
@property(nonatomic, strong, readonly, nonnull) NSData *data;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
