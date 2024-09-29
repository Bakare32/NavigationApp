// This file is generated and will be overwritten automatically.

#import "MBNNNavigator.h"
#import "MBNNSetRouteCallback_Internal.h"

@interface MBNNNavigator ()
- (nonnull MBXExpected *)setRouteForRouteResponse:(nullable NSString *)routeResponse
                                            route:(uint32_t)route
                                              leg:(uint32_t)leg
                                          options:(nonnull MBNNActiveGuidanceOptions *)options __attribute((ns_returns_retained)) __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-setRouteForRouteResponse:route:leg:options:' instead.", "-setRouteForRouteResponse:route:leg:options:")));
- (void)setRouteForRouteResponse:(nullable NSString *)routeResponse
                           route:(uint32_t)route
                             leg:(uint32_t)leg
                    routeRequest:(nullable NSString *)routeRequest
                        callback:(nonnull MBNNSetRouteCallback)callback;
- (nonnull id<MBNNRouteAlternativesControllerInterface>)createRouteAlternativesControllerForRouter:(nonnull id<MBNNRouterInterface>)router __attribute((ns_returns_retained));
@end
