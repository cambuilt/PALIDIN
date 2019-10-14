#import <Foundation/Foundation.h>
#import "RGLRfidNotify.h"

@class RGLFile;

@interface RGLApplication : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *applicationID;
@property(nonatomic, strong, readonly, nonnull) NSString *dataHashAlgorithm;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLFile *> *files;
@property(nonatomic, assign, readonly) NSInteger type;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes status;
@property(nonatomic, strong, readonly, nonnull) NSString *unicodeVersion;
@property(nonatomic, strong, readonly, nonnull) NSString *version;


- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
