#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RGLPosition : NSObject

@property(nonatomic, assign, readonly) CGSize size;
@property(nonatomic, assign, readonly) CGPoint center;
@property(nonatomic, assign, readonly) double angle;

@property(nonatomic, strong, readonly, nonnull) NSArray <NSValue *> *bounds;
@property(nonatomic, assign, readonly) double perspectiveTr;
@property(nonatomic, assign, readonly) double objArea;
@property(nonatomic, assign, readonly) double objIntAngleDev;
@property(nonatomic, assign, readonly) BOOL resultStatusConfirmed;
@property(nonatomic, assign, readonly) NSInteger docFormat;
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (nullable instancetype)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

+ (NSArray <NSValue *> *_Nonnull)calculateRectWithDictionary:(NSDictionary *_Nonnull)dict;

@end
