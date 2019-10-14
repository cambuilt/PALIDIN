#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "RGLScenario.h"
#import "RGLProcessParams.h"

@class RGLDocumentReaderCameraViewController, RGLDocumentReaderResults, RGLImageReader;

typedef NS_ENUM(NSInteger, RGLCameraViewControllerAction) {
    RGLCameraViewControllerActionDone,
    RGLCameraViewControllerActionProcess,
    RGLCameraViewControllerActionCancel,
    RGLCameraViewControllerActionMorePagesAvailable
};

typedef void (^RGLCameraViewControllerHandler)(RGLDocumentReaderCameraViewController * _Nullable controller,
                                            RGLCameraViewControllerAction action,
                                            RGLDocumentReaderResults * _Nullable results);


@protocol RGLDocumentReaderCameraViewControllerDelegate <NSObject>

- (BOOL)didMotionControlEnabledInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)didSkipFocusingFramesInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showCaptureButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showChangeFrameSizeButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showSwapCameraButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showTorchButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showCloseButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (AVCaptureSessionPreset _Nullable)videoSessionPresetInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showLogoInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showHelpAnimationInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)multipageProcessingInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIInterfaceOrientationMask)supportedOrientationsInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (void)startNewPageInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showStatusMessagesInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showResultMessagesInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nonnull)tintColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nonnull)resultStatusTextColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIFont *_Nullable)resultStatusTextFontInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nullable)resultStatusBackgroundColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nonnull)cameraFrameDefaultColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nonnull)cameraFrameActiveColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (CGFloat)cameraFrameBorderWidthInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)cameraFrameHideInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nonnull)statusTextColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIFont *_Nullable)statusTextFontInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nullable)activityIndicatorViewColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIColor *_Nullable)skipMultipageButtonBackgroundColorInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (RGLCameraFrameShapeType)cameraFrameShapeTypeInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (CGFloat)cornerViewLineLengthInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showNextPageAnimationInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showMaskViewInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (RGLDocReaderFrame)cameraFrameSizeInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (NSArray <NSNumber *> * _Nullable)barcodeTypesInCameraController:(RGLDocumentReaderCameraViewController * _Nonnull)controller;
- (AVCaptureDevicePosition)cameraPositionInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)showSkipNextPageButtonInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIImage *_Nullable)helpAnimationImageInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIImage *_Nullable)multipageAnimationFrontImageInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIImage *_Nullable)multipageAnimationBackImageInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (CGFloat)statusPositionMultiplierInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (CGFloat)resultStatusPositionMultiplierInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (UIImage *_Nullable)borderBackgroundImageInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (BOOL)uvTorchEnabledInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (NSString *_Nullable)btDeviceNameInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;
- (NSString *_Nullable)cameraStatusInCameraController:(RGLDocumentReaderCameraViewController *_Nonnull)controller;

@end

@class RGLDocumentReaderCameraViewControllerDelegate;

@interface RGLDocumentReaderCameraViewController : UIViewController

@property(nonatomic, weak, nullable) id<RGLDocumentReaderCameraViewControllerDelegate> cameraViewControllerDelegate;
@property(nonatomic, strong, nullable) RGLCameraViewControllerHandler cameraViewControllerHandler;
@property(nonatomic, strong, nullable) RGLImageReader *imageReader;
@property(nonatomic, strong, nullable) RGLImageReader *photoImageReader;
@property(nonatomic, assign) BOOL recognitionIsActive;

@property(nonatomic, assign) BOOL showChangeFrameButton;

+ (RGLDocumentReaderCameraViewController * _Nonnull)
  showCameraViewControllerFromPresenter:(UIViewController * _Nonnull)presenter
                            imageReader:(RGLImageReader * _Nonnull)imageReader
                       photoImageReader:(RGLImageReader * _Nonnull)photoImageReader
                               delegate:(id<RGLDocumentReaderCameraViewControllerDelegate> _Nullable)delegate
                                handler:(RGLCameraViewControllerHandler _Nonnull)handler;

+ (RGLDocumentReaderCameraViewController * _Nonnull)
  prepareCameraViewControllerWithImageReader:(RGLImageReader *_Nonnull)imageReader
                            photoImageReader:(RGLImageReader * _Nonnull)photoImageReader
                                    delegate:(id<RGLDocumentReaderCameraViewControllerDelegate> _Nullable)delegate
                                     handler:(RGLCameraViewControllerHandler _Nonnull)handler;

- (void)closeTapped:(UIButton *_Nonnull)button;
- (void)flashTapped:(UIButton *_Nonnull)button;
- (void)swapTapped:(UIButton *_Nonnull)button;
- (void)captureButtonTapped:(UIButton *_Nonnull)button;
- (void)skipMultipageTapped:(UIButton *_Nonnull)button;
- (void)changeFrameTapped:(UIButton *_Nonnull)button;
- (void)processParamChanged;
- (void)setHiddenForFlashButton:(BOOL)isHidden;
- (void)setHiddenForCloseButton:(BOOL)isHidden;
- (void)setHiddenForCaptureButton:(BOOL)isHidden;
- (void)setHiddenForSwapCameraButton:(BOOL)isHidden;
- (void)setVideoSessionPreset:(AVCaptureSessionPreset _Nonnull)sessionPreset;
- (void)configureSession;
- (void)setAVCaptureDevicePosition:(AVCaptureDevicePosition)cameraPosition;

- (void)notifyTintColorChanged;
- (void)notifyResultStatusTextColorChanged;
- (void)notifyResultStatusTextFontChanged;
- (void)notifyCameraFrameDefaultColorChanged;
- (void)notifyStatusTextColorChanged;
- (void)notifyStatusTextFontChanged;
- (void)notifyShowStatusMessagesChanged;
- (void)notifyShowResultStatusMessagesChanged;
- (void)notifyCameraStatusChanged;
- (void)notifyCameraResultStatusChanged;
- (void)notifyCameraFrameShapeTypeChanged;
- (void)notifyMultipageButtonBackgroundColorChanged;
- (void)notifyCameraFrameBorderWidthChanged;
- (void)notifyActivityIndicatorColorChanged;
- (void)notifyResultStatusBackgroundColorChanged;
- (void)notifyCameraFrameLineLengthChanged;
- (void)notifyShowBackgroundMaskChanged;
- (void)notifyBorderBackgroundImageChanged;
- (void)notifyBackgroundMaskAlphaChanged;
- (void)notifyHelpAnimationImageContentModeChanged;
- (void)notifyMultipageAnimationFrontImageContentModeChanged;
- (void)notifyMultipageAnimationBackImageContentModeChanged;
- (void)notifyBorderBackgroundImageContentModeChanged;
- (void)notifyHelpAnimationImageChanged;
- (void)notifyMultipageAnimationFrontImageChanged;
- (void)notifyMultipageAnimationBackImageChanged;

- (void)closeCameraViewController:(void(^_Nullable)(void))completion;
    
@end
