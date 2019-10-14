#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class RGLDocumentReaderGraphicField;

@interface RGLDocumentReaderGraphicResult : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderGraphicField *> *fields;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFields:(NSArray <RGLDocumentReaderGraphicField *> *_Nonnull)fields;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
