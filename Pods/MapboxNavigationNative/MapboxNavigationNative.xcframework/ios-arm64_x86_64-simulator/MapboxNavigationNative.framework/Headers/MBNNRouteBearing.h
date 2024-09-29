// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(RouteBearing)
__attribute__((visibility ("default")))
@interface MBNNRouteBearing : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithAngle:(nullable NSNumber *)angle
                              degrees:(nullable NSNumber *)degrees;

/** An angle clockwise from true north between 0 and 360 */
@property (nonatomic, readonly, nullable) NSNumber *angle;

/** The range of degrees by which the angle can deviate (recommended value is 45° or 90°) */
@property (nonatomic, readonly, nullable) NSNumber *degrees;


- (BOOL)isEqualToRouteBearing:(nonnull MBNNRouteBearing *)other;

@end
