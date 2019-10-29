#import <UIKit/UIkit.h>

#import "RGLDocumentReaderCameraViewController.h"

@class RGLDocumentReaderCameraViewController;

NS_SWIFT_NAME(Customization)
@interface RGLCustomization : NSObject

@property(nonatomic, weak, nullable) RGLDocumentReaderCameraViewController *cameraViewController;
@property(nonatomic, assign) BOOL showHelpAnimation;
@property(nonatomic, strong, nullable) UIImage *helpAnimationImage;
@property(nonatomic, assign) BOOL showStatusMessages;
@property(nonatomic, assign) BOOL showResultStatusMessages;
@property(nonatomic, strong, nullable) NSString *status;
@property(nonatomic, strong, nullable) NSString *resultStatus;
@property(nonatomic, assign) CGFloat statusPositionMultiplier;
@property(nonatomic, assign) CGFloat resultStatusPositionMultiplier;
@property(nonatomic, assign) RGLCameraFrameShapeType cameraFrameShapeType;
@property(nonatomic, strong, null_resettable) UIColor *tintColor;
@property(nonatomic, strong, null_resettable) UIColor *resultStatusTextColor;
@property(nonatomic, strong, null_resettable) UIFont *resultStatusTextFont;
@property(nonatomic, strong, nullable) UIColor *resultStatusBackgroundColor;
@property(nonatomic, strong, null_resettable) UIColor *cameraFrameDefaultColor;
@property(nonatomic, strong, null_resettable) UIColor *cameraFrameActiveColor;
@property(nonatomic, assign) CGFloat cameraFrameBorderWidth;
@property(nonatomic, strong, nullable) UIColor *statusTextColor;
@property(nonatomic, strong, null_resettable) UIFont *statusTextFont;
@property(nonatomic, strong, nullable) UIColor *activityIndicatorColor;
@property(nonatomic, strong, nullable) UIColor *multipageButtonBackgroundColor;
@property(nonatomic, strong, nullable) UIImage *multipageAnimationFrontImage;
@property(nonatomic, strong, nullable) UIImage *multipageAnimationBackImage;
@property(nonatomic, assign) CGFloat cameraFrameLineLength;
@property(nonatomic, assign) BOOL showNextPageAnimation;
@property(nonatomic, assign) BOOL showBackgroundMask;
@property(nonatomic, strong, nullable) UIImage *borderBackgroundImage;
@property(nonatomic, assign) CGFloat backgroundMaskAlpha;
@property(nonatomic, assign) UIViewContentMode helpAnimationImageContentMode;
@property(nonatomic, assign) UIViewContentMode multipageAnimationFrontImageContentMode;
@property(nonatomic, assign) UIViewContentMode multipageAnimationBackImageContentMode;
@property(nonatomic, assign) UIViewContentMode borderBackgroundImageContentMode;

@end
