// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRoutingProfile;

NS_SWIFT_NAME(RouteRefreshOptions)
__attribute__((visibility ("default")))
@interface MBNNRouteRefreshOptions : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRequestId:(nonnull NSString *)requestId
                               routeIndex:(uint32_t)routeIndex
                                 legIndex:(uint32_t)legIndex
                           routingProfile:(nonnull MBNNRoutingProfile *)routingProfile;

/** A uuid specifying the request containing the route being refreshed */
@property (nonatomic, readonly, nonnull, copy) NSString *requestId;

/** The index of the specified route */
@property (nonatomic, readonly) uint32_t routeIndex;

/** The index of the leg to start the refresh response (inclusive) */
@property (nonatomic, readonly) uint32_t legIndex;

/** The routing profile to use. Possible values are driving-traffic, driving, walking, or cycling with account name */
@property (nonatomic, readonly, nonnull) MBNNRoutingProfile *routingProfile;


@end
