// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNActiveGuidanceOptions;

NS_SWIFT_NAME(SetRouteHistoryRecord)
__attribute__((visibility ("default")))
@interface MBNNSetRouteHistoryRecord : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRouteResponse:(nullable NSString *)routeResponse
                                   routeIndex:(uint32_t)routeIndex
                                     legIndex:(uint32_t)legIndex
                                      options:(nonnull MBNNActiveGuidanceOptions *)options;

/** route response's json, will be null in case if route was reset */
@property (nonatomic, readonly, nullable, copy) NSString *routeResponse;

@property (nonatomic, readonly) uint32_t routeIndex;
@property (nonatomic, readonly) uint32_t legIndex;
@property (nonatomic, readonly, nonnull) MBNNActiveGuidanceOptions *options;

@end
