#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLImageQuality;

typedef NS_ENUM(NSInteger, RGLEImageQualityCheckType) {
  RGLEImageQualityCheckTypeImageGlares       = 0,
  RGLEImageQualityCheckTypeImageFocus        = 1,
  RGLEImageQualityCheckTypeImageResolution   = 2
};

@interface RGLImageQualityGroup : NSObject

@property(nonatomic, assign, readonly) NSInteger count;
@property(nonatomic, assign, readonly) RGLCheckResult result;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLImageQuality *> *imageQualityList;

- (nullable instancetype)init NS_UNAVAILABLE;
- (RGLCheckResult)getQualityResultWithType:(RGLEImageQualityCheckType)type;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end

