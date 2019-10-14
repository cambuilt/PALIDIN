#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class RGLDocumentReaderJsonResultGroup;

@interface RGLDocumentReaderJsonResult : NSObject

@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderJsonResultGroup *> *results;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithResults:(NSArray <RGLDocumentReaderJsonResultGroup *> *_Nonnull)results;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
