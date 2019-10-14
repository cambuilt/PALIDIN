#import <Foundation/Foundation.h>
#import "RGLRfidNotify.h"
#import "RGLRfidScenario.h"

@interface RGLAccessControlProcedureType : NSObject

@property(nonatomic, assign, readonly) NSInteger activeOptionIdx;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes status;
@property(nonatomic, assign, readonly) RGLRfidAccessControlProcedureType type;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
