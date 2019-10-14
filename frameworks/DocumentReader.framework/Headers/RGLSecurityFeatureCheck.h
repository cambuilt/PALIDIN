#import <Foundation/Foundation.h>
#import "RGLAuthenticityElement.h"

@class RGLElementRect;

@interface RGLSecurityFeatureCheck : RGLAuthenticityElement

@property(nonatomic, strong, readonly, nonnull) RGLElementRect *elementRect;

- (NSString *_Nonnull)typeName;

@end
