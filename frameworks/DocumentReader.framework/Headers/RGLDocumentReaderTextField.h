#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLDocumentReaderValue;

@interface RGLDocumentReaderTextField : NSObject

@property(nonatomic, assign, readonly) RGLFieldType fieldType;
@property(nonatomic, strong, readonly, nonnull) NSString *fieldName;
@property(nonatomic, assign, readonly) RGLLcid lcid;
@property(nonatomic, strong, readonly, nonnull) NSString *lcidName;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderValue *> *values;
@property(nonatomic, assign, readonly) RGLCheckResult status;

- (RGLDocumentReaderValue *_Nullable)getValue;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFieldType:(RGLFieldType)fieldType;
- (instancetype _Nonnull)initWithFieldType:(RGLFieldType)fieldType lcid:(RGLLcid)lcid;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

+ (NSString *_Nonnull)fieldTypeName:(RGLFieldType) fieldType;
+ (NSString *_Nonnull)lcidName:(RGLLcid) lcid;

@end
