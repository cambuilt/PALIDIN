#import <Foundation/Foundation.h>
#import "RGLRfidNotify.h"

@class RGLFileData, RGLSecurityObjectCertificates;

@interface RGLFile : NSObject

@property(nonatomic, strong, readonly, nonnull) RGLFileData *fileData;
@property(nonatomic, strong, readonly, nonnull) NSString *fileID;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *notifications;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes pAStatus;
@property(nonatomic, assign, readonly) RGLRfidErrorCodes readingStatus;
@property(nonatomic, assign, readonly) NSInteger readingTime;
@property(nonatomic, assign, readonly) RGLRfidDataFileType type;
@property(nonatomic, strong, readonly, nonnull) NSString *typeName;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsText;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsGraphics;
@property(nonatomic, strong, readonly, nonnull) NSArray <NSNumber *> *docFieldsOriginals;
@property(nonatomic, strong, readonly, nonnull) RGLSecurityObjectCertificates *certificates;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
