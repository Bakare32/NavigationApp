// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNRouteState.h"

@class MBNNActiveGuidanceInfo;
@class MBNNBannerInstruction;
@class MBNNFixLocation;
@class MBNNMapMatcherOutput;
@class MBNNSpeedLimit;
@class MBNNUpcomingRouteAlert;
@class MBNNVoiceInstruction;

NS_SWIFT_NAME(NavigationStatus)
__attribute__((visibility ("default")))
@interface MBNNNavigationStatus : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRouteState:(MBNNRouteState)routeState
                                     stale:(BOOL)stale
                                  location:(nonnull MBNNFixLocation *)location
                       routeSequenceNumber:(uint32_t)routeSequenceNumber
                                routeIndex:(uint32_t)routeIndex
                                  legIndex:(uint32_t)legIndex
                                 stepIndex:(uint32_t)stepIndex
                                isFallback:(BOOL)isFallback
                                  inTunnel:(BOOL)inTunnel
                                 predicted:(NSTimeInterval)predicted
                                shapeIndex:(uint32_t)shapeIndex
                         intersectionIndex:(uint32_t)intersectionIndex
                                  roadName:(nonnull NSString *)roadName
                                shieldName:(nonnull NSString *)shieldName
                          voiceInstruction:(nullable MBNNVoiceInstruction *)voiceInstruction
                         bannerInstruction:(nullable MBNNBannerInstruction *)bannerInstruction
                                speedLimit:(nullable MBNNSpeedLimit *)speedLimit
                                 keyPoints:(nonnull NSArray<MBNNFixLocation *> *)keyPoints
                          mapMatcherOutput:(nonnull MBNNMapMatcherOutput *)mapMatcherOutput
                              offRoadProba:(float)offRoadProba
                        activeGuidanceInfo:(nullable MBNNActiveGuidanceInfo *)activeGuidanceInfo
                       upcomingRouteAlerts:(nonnull NSArray<MBNNUpcomingRouteAlert *> *)upcomingRouteAlerts
                         nextWaypointIndex:(uint32_t)nextWaypointIndex
                                     layer:(nullable NSNumber *)layer;

@property (nonatomic, readonly) MBNNRouteState routeState;
/**
 * We didn't have location updates for too much time.
 * This can be handled as "grey puck" or "No GPS" on client side.
 */
@property (nonatomic, readonly, getter=isStale) BOOL stale;

/** enhanced location */
@property (nonatomic, readonly, nonnull) MBNNFixLocation *location;

/**
 * sequence number of current route (when this NavigationStatus was built). After the `Navigator.setRoute(...)`
 * is called - the new route is applied, and `NavigationStatus` entities with previous `routeSequenceNumber` are outdated,
 * they should be ignored. Even `setRoute(...)` with empty `routeResponse` increments current `routeSequenceNumber`.
 */
@property (nonatomic, readonly) uint32_t routeSequenceNumber;

/** index of route */
@property (nonatomic, readonly) uint32_t routeIndex;

/** index of current leg in route bounds */
@property (nonatomic, readonly) uint32_t legIndex;

/** index of current step in leg bounds */
@property (nonatomic, readonly) uint32_t stepIndex;

/**
 * `true` if status was produced in "fallback" mode, i.e. navigation tiles were not used
 * (e.g. they are not available), usually it means worse user experience
 */
@property (nonatomic, readonly, getter=isIsFallback) BOOL isFallback;

/** is current location belongs to tunnel */
@property (nonatomic, readonly, getter=isInTunnel) BOOL inTunnel;

@property (nonatomic, readonly) NSTimeInterval predicted;
/** index in leg shape */
@property (nonatomic, readonly) uint32_t shapeIndex;

/** index in step bounds(i.e. on each new step we start indexing from 0) */
@property (nonatomic, readonly) uint32_t intersectionIndex;

/** current road name */
@property (nonatomic, readonly, nonnull, copy) NSString *roadName;

/**
 * Current road shield icon name. ShieldName corresponds to the bannerInstruction's road shield icon.
 * Contains normalized ref name. Lowercase characters with "-" for spaces.
 * It can be used in conjunction with the country code to determine the highway shield icon for the current road.
 * At this point, only U.S. shields are supported.
 * Empty string for unknown highway shield icons.
 * Examples: "i-50", "us-50", "i-81".
 */
@property (nonatomic, readonly, nonnull, copy) NSString *shieldName;

/** voice instruction to be presented */
@property (nonatomic, readonly, nullable) MBNNVoiceInstruction *voiceInstruction;

/** banner instruction to be presented */
@property (nonatomic, readonly, nullable) MBNNBannerInstruction *bannerInstruction;

/**
 * current speed limit
 *  `nullopt` for unknown speed limit
 */
@property (nonatomic, readonly, nullable) MBNNSpeedLimit *speedLimit;

/**
 * Contains key points(for example corners) of route shape passed by pack between `getStatus` calls or from last notification of observer.
 * For now can be used in route mode only, always contain at least one point besides the very first `getStatus` call.
 * Only `coordinate`, ``bearing`, `monotonicTimestampNanoseconds` and `time` fields are filled. Last point is always the same as `location`.
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNFixLocation *> *keyPoints;

/** Output of map matcher on this status. */
@property (nonatomic, readonly, nonnull) MBNNMapMatcherOutput *mapMatcherOutput;

/**
 * Probability of vehicle to be off-road:
 * 1.0 - vehicle is definitely off-road, 0.0 - vehicle is definitely on-road
 */
@property (nonatomic, readonly) float offRoadProba;

/** Will be empty if we are in free-drive now(i.e. routeState == invalid) */
@property (nonatomic, readonly, nullable) MBNNActiveGuidanceInfo *activeGuidanceInfo;

/** Array of upcoming route alerts, doesn't contain route alerts that were already passed by user */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNUpcomingRouteAlert *> *upcomingRouteAlerts;

/** Index of next waypoint on the route in the initial list of waypoints. If no waypoints - 0 */
@property (nonatomic, readonly) uint32_t nextWaypointIndex;

/** current Z-level, can be used to build route from proper level of road */
@property (nonatomic, readonly, nullable) NSNumber *layer;


@end
