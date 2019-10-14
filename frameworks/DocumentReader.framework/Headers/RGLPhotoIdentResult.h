#import <Foundation/Foundation.h>
#import "RGLAuthenticityElement.h"
#import <UIKit/UIKit.h>

@class RGLElementRect;

@interface RGLPhotoIdentResult : RGLAuthenticityElement

@property(nonatomic, strong, readonly, nonnull) RGLElementRect *area;
@property(nonatomic, assign, readonly) RGLLightType lightIndex;
@property(nonatomic, assign, readonly) NSInteger reserved1;
@property(nonatomic, assign, readonly) NSInteger reserved2;
@property(nonatomic, assign, readonly) NSInteger reserved3;
@property(nonatomic, assign, readonly) RGLCheckResult result;
@property(nonatomic, strong, readonly, nonnull) NSArray <UIImage *> *resultImages;
@property(nonatomic, strong, readonly, nonnull) NSArray <UIImage *> *sourceImage;

@end
