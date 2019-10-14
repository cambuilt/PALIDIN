#import <Foundation/Foundation.h>

@interface RGLPDF417Info : NSObject

@property(nonatomic, assign, readonly) NSInteger errorLevel;
@property(nonatomic, assign, readonly) NSInteger columns;
@property(nonatomic, assign, readonly) NSInteger rows;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end
