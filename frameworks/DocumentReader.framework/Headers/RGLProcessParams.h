#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLBarcodeType) {
  RGLBarcodeTypeUnknown         = 0,
  RGLBarcodeTypeCode128         = 1,
  RGLBarcodeTypeCode39          = 2,
  RGLBarcodeTypeEAN8            = 3,
  RGLBarcodeTypeITF             = 4,
  RGLBarcodeTypePDF417          = 5,
  RGLBarcodeTypeSTF             = 6,
  RGLBarcodeTypeMTF             = 7,
  RGLBarcodeTypeIATA            = 8,
  RGLBarcodeTypeCODABAR         = 9,
  RGLBarcodeTypeUPCA            = 10,
  RGLBarcodeTypeCODE93          = 11,
  RGLBarcodeTypeUPCE            = 12,
  RGLBarcodeTypeEAN13           = 13,
  RGLBarcodeTypeQRCODE          = 14,
  RGLBarcodeTypeAZTEC           = 15,
  RGLBarcodeTypeDATAMATRIX      = 16,
  RGLBarcodeTypeALL_1D          = 17
};

typedef NS_ENUM(NSInteger, RGLMeasureSystem) {
  RGLMeasureSystemMetric = 0,
  RGLMeasureSystemImperial = 1
};

@class RGLRfidScenario;

@interface RGLProcessParams : NSObject

@property (nonatomic, strong, nullable) NSString *scenario;
@property (nonatomic, strong, nullable) NSString *captureButtonScenario;
@property (nonatomic, assign) BOOL logs;
@property (nonatomic, assign) BOOL multipageProcessing;
@property (nonatomic, assign) BOOL disableFocusingCheck;
@property (nonatomic, assign) BOOL debugSaveImages;
@property (nonatomic, assign) BOOL debugSaveCroppedImages;
@property (nonatomic, assign) BOOL debugSaveLogs;
@property (nonatomic, strong, null_resettable) NSString *dateFormat;
@property (nonatomic, strong, nullable) NSArray *documentIDList;
@property (nonatomic, strong, readonly, nullable) NSString *sessionLogFolder;
@property (nonatomic, strong, nullable) NSArray *fieldTypesFilter;
@property (nonatomic, strong, nullable) NSArray *barcodeTypes;
@property (nonatomic, strong, nonnull) RGLRfidScenario *rfidOptions;
@property (nonatomic, assign) RGLMeasureSystem measureSystem;
@property (nonatomic, assign) BOOL returnOriginalImage;

- (void)setSessionLogFolder:(NSString * _Nullable)sessionLogFolder;
- (NSDictionary * _Nullable)processParamsDictionary;

@end
