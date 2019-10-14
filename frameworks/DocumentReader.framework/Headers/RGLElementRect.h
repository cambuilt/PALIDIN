#import <Foundation/Foundation.h>

@interface RGLElementRect : NSObject

@property(nonatomic, assign, readonly) NSInteger bottom;
@property(nonatomic, assign, readonly) NSInteger left;
@property(nonatomic, assign, readonly) NSInteger right;
@property(nonatomic, assign, readonly) NSInteger top;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (instancetype _Nonnull)elementRect;

@end
