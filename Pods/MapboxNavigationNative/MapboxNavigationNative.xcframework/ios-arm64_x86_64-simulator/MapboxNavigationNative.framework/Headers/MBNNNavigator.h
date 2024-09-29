// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNActiveGuidanceGeometryEncoding.h"
#import "MBNNChangeRouteLegCallback.h"
#import "MBNNGetBannerInstructionCallback.h"
#import "MBNNUpdateAnnotationsCallback.h"
#import "MBNNUpdateLocationCallback.h"
#import "MBNNUpdateSensorDataCallback.h"
@class MBXExpected;

@class MBNNActiveGuidanceOptions;
@class MBNNBannerInstruction;
@class MBNNCacheHandle;
@class MBNNConfigHandle;
@class MBNNElectronicHorizonOptions;
@class MBNNFixLocation;
@class MBNNHistoryRecorderHandle;
@class MBNNNavigationStatus;
@class MBNNPredictiveCacheController;
@class MBNNPredictiveCacheControllerOptions;
@class MBNNPredictiveLocationTrackerOptions;
@class MBNNRoadObjectsStore;
@class MBNNRouteInfo;
@class MBNNSensorData;
@class MBXTileStore;
@class MBXTilesetDescriptor;
@protocol MBNNElectronicHorizonObserver;
@protocol MBNNExperimental;
@protocol MBNNFallbackVersionsObserver;
@protocol MBNNNavigatorObserver;
@protocol MBNNRerouteManager;
@protocol MBNNRouteAlternativesControllerInterface;
@protocol MBNNRouterInterface;

NS_SWIFT_NAME(Navigator)
__attribute__((visibility ("default")))
@interface MBNNNavigator : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs navigator object with given dependencies
 *
 * @param config           config created with `ConfigFactory`
 * @param cache            cache created with `CacheFactory`
 * @param historyRecorder  history recorder created with `HistoryRecorderHandle.build` method
 */
- (nonnull instancetype)initWithConfig:(nonnull MBNNConfigHandle *)config
                                 cache:(nonnull MBNNCacheHandle *)cache
                       historyRecorder:(nullable MBNNHistoryRecorderHandle *)historyRecorder;

/**
 * Shuts down Navigator instance, so it frees resources.
 * This Navigator instance should not be used after shutdown call.
 */
- (void)shutdown;
/**
 * Sets the `FallbackVersionsObserver` instance for notifications about fallback (available offline) versions found.
 * In order to remove observer just call `setFallbackVersionsObserver(null)`.
 */
- (void)setFallbackVersionsObserverForObserver:(nullable id<MBNNFallbackVersionsObserver>)observer;
/**
 * After setting observer `getStatus` shouldn't be called,
 * but `Navigator` object will start calling `NavigatorObserver.onStatus` as soon as at least one raw location is received.
 */
- (void)addObserverForObserver:(nonnull id<MBNNNavigatorObserver>)observer;
- (void)removeObserverForObserver:(nonnull id<MBNNNavigatorObserver>)observer;
/**
 * Updates annotations so that subsequent calls to getStatus will
 * reflect the most current annotations for the route
 *
 * @param  annotations  A string containing the json/pbf annotations
 * @param  route  Which route to apply the annotation update to
 * @param  leg    Which leg to apply the annotation update to
 *
 * @return  True if the annotations could be updated false if not (wrong number of annotations)
 */
- (BOOL)updateAnnotationsForRouteResponse:(nonnull NSString *)routeResponse
                                    route:(uint32_t)route
                                      leg:(uint32_t)leg __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-updateAnnotationsForRouteResponse:route:leg:' instead.", "-updateAnnotationsForRouteResponse:route:leg:")));
/**
 * Asynchronously updates annotations so that subsequent calls to getStatus will
 * reflect the most current annotations for the route.
 * The callback is scheduled using the `common::Scheduler` of the thread calling the `Navigator` constructor.
 *
 * @param  annotations  A string containing the json/pbf annotations
 * @param  route  Which route to apply the annotation update to
 * @param  leg    Which leg to apply the annotation update to
 * @param  callback Callback which is called when the async operation is completed
 */
- (void)updateAnnotationsForRouteResponse:(nonnull NSString *)routeResponse
                                    route:(uint32_t)route
                                      leg:(uint32_t)leg
                                 callback:(nonnull MBNNUpdateAnnotationsCallback)callback;
/**
 * Passes in the current fix location of the user.
 *
 * @param  fix  The current fix location of user.
 *
 * @return true if the fix location was usable false if not
 */
- (BOOL)updateLocationForFixLocation:(nonnull MBNNFixLocation *)fixLocation __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-updateLocationForFixLocation:' instead.", "-updateLocationForFixLocation:")));
/**
 * Asynchronously passes in the current fix location of the user.
 * The callback is scheduled using the `common::Scheduler` of the thread calling the `Navigator` constructor.
 *
 * @param  fix  The current fix location of user.
 * @param  callback Callback which is called when the async operation is completed
 */
- (void)updateLocationForFixLocation:(nonnull MBNNFixLocation *)fixLocation
                            callback:(nonnull MBNNUpdateLocationCallback)callback;
/**
 * Passes in the current sensor data of the user.
 *
 * @param  data  The current sensor data of user.
 *
 * @return true if the sensor data was usable false if not
 */
- (BOOL)updateSensorDataForSensorData:(nonnull MBNNSensorData *)sensorData __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-updateSensorDataForSensorData:' instead.", "-updateSensorDataForSensorData:")));
/**
 * Asynchronously passes in the current sensor data of the user.
 * The callback is scheduled using the `common::Scheduler` of the thread calling the `Navigator` constructor.
 *
 * @param  data  The current sensor data of user.
 * @param  callback Callback which is called when the async operation is completed
 */
- (void)updateSensorDataForSensorData:(nonnull MBNNSensorData *)sensorData
                             callback:(nonnull MBNNUpdateSensorDataCallback)callback;
/**
 * Returns current navigator status(actually last passed to `NavigatorObserver#onStatus`.
 * Guaranteed to be stateless.
 * If there was no previous `updateLocation` call returns null.
 */
- (nullable MBNNNavigationStatus *)getStatus __attribute((ns_returns_retained)) __attribute__((deprecated("This method defines wrong expectations about state of Navigator after using other APIs(because most of other APIs are asynchronous).. Please use: 'MBNNNavigatorObserver' instead.", "MBNNNavigatorObserver")));
/** Gets current banner instruction */
- (nullable MBNNBannerInstruction *)getBannerInstruction __attribute((ns_returns_retained)) __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-getBannerInstruction:' instead.", "-getBannerInstruction:")));
/**
 * Asynchronously gets the current banner instruction
 * The callback is scheduled using the `common::Scheduler` of the thread calling the `Navigator` constructor.
 * @param  callback Callback which is called when the async operation is completed
 */
- (void)getBannerInstructionForCallback:(nonnull MBNNGetBannerInstructionCallback)callback;
/**
 * Follows a new route and leg of the already loaded directions
 * Returns a initialized route state if no errors occurred
 * otherwise, it returns a invalid route state.
 *
 * @param route  new route id
 * @param leg    new leg id
 *
 * @return `true` when the route leg has successfully changed, otherwise `false`.
 */
- (BOOL)changeRouteLegForRoute:(uint32_t)route
                           leg:(uint32_t)leg __attribute__((deprecated("This method is blocking and long running. The new async method is non-blocking, it runs callbacks on the same thread where `onStatus` callbacks are executed, preserving sequential calls ordering.. Please use: '-changeRouteLegForRoute:leg:' instead.", "-changeRouteLegForRoute:leg:")));
/**
 * Asynchronously sets a new route and leg of the already loaded directions
 * The callback is scheduled using the `common::Scheduler` of the thread calling the `Navigator` constructor.
 *
 * @param route  new route id
 * @param leg    new leg id
 * @param  callback Callback which is called when the async operation is completed
 */
- (void)changeRouteLegForRoute:(uint32_t)route
                           leg:(uint32_t)leg
                      callback:(nonnull MBNNChangeRouteLegCallback)callback;
/**
 * Compare given route with current route.
 * Routes are considered the same if one of the routes is a suffix of another
 * without the first and last intersection.
 *
 * If we don't have an active route, return `true`.
 * If given route has less or equal 2 intersections we consider them different
 * Algorithm doesn't depend on current position just compare routes.
 *
 * @param routeResponse     the route in json format
 * @param geometryEncoding  geometry encoding of the given route
 *
 * @return `true` if routes are different, otherwise `false`.
 */
- (BOOL)isDifferentRouteForRouteResponse:(nonnull NSString *)routeResponse
                        geometryEncoding:(MBNNActiveGuidanceGeometryEncoding)geometryEncoding;
/** Set an observer and the configuration for the EH. */
- (void)setElectronicHorizonObserverForObserver:(nullable id<MBNNElectronicHorizonObserver>)observer;
/** Sets electronic horizon options. Pass null to reset to defaults. */
- (void)setElectronicHorizonOptionsForOptions:(nullable MBNNElectronicHorizonOptions *)options;
/** Returns road object store */
- (nonnull MBNNRoadObjectsStore *)roadObjectStore __attribute((ns_returns_retained));
/**
 * Resets ride session. This method exposes recreation of ride session, which is
 * needed for restarting of simulation.
 * Please call it before significant change of location, e.g. when restarting
 * navigation simulation, or before resetting location to not real (simulated)
 * position without recreation of navigator.
 */
- (void)resetRideSession;
/**
 * Creates predictive cache controller to populate the specified tile store instance
 * with the tiles described by the specified tileset descriptors.
 *
 * @param tileStore               a tile store that should be populated with tiles
 * @param descriptors             a list of tileset descriptors
 * @param locationTrackerOptions  options to configure what tiles should be loaded for current location and route
 *
 * @return a PredictiveCacheController object
 */
- (nonnull MBNNPredictiveCacheController *)createPredictiveCacheControllerForTileStore:(nonnull MBXTileStore *)tileStore
                                                                           descriptors:(nonnull NSArray<MBXTilesetDescriptor *> *)descriptors
                                                                locationTrackerOptions:(nonnull MBNNPredictiveLocationTrackerOptions *)locationTrackerOptions __attribute((ns_returns_retained));
/**
 * @param tileStore               a tile store that should be populated with tiles
 * @param cacheOptions            cache options such as dataset and version of tiles
 * @param locationTrackerOptions  options to configure what tiles should be loaded for current location and route
 *
 * @return a PredictiveCacheController object
 */
- (nonnull MBNNPredictiveCacheController *)createPredictiveCacheControllerForTileStore:(nonnull MBXTileStore *)tileStore
                                                                          cacheOptions:(nonnull MBNNPredictiveCacheControllerOptions *)cacheOptions
                                                                locationTrackerOptions:(nonnull MBNNPredictiveLocationTrackerOptions *)locationTrackerOptions __attribute((ns_returns_retained));
/**
 * Creates predictive cache controller to populate inner tile store instance of this navigator.
 *
 * @param cacheOptions            cache options such as dataset and version of tiles
 * @param locationTrackerOptions  options to configure what tiles should be loaded for current location and route
 *
 * @return a PredictiveCacheController object
 */
- (nonnull MBNNPredictiveCacheController *)createPredictiveCacheControllerForCacheOptions:(nonnull MBNNPredictiveCacheControllerOptions *)cacheOptions
                                                                   locationTrackerOptions:(nonnull MBNNPredictiveLocationTrackerOptions *)locationTrackerOptions __attribute((ns_returns_retained));
/**
 * Creates predictive cache controller to populate inner tile store instance of this navigator
 * and take dataset and version of tiles from Navigator's config.
 *
 * @param locationTrackerOptions  options to configure what tiles should be loaded for current location and route
 *
 * @return a PredictiveCacheController object
 */
- (nonnull MBNNPredictiveCacheController *)createPredictiveCacheControllerForLocationTrackerOptions:(nonnull MBNNPredictiveLocationTrackerOptions *)locationTrackerOptions __attribute((ns_returns_retained));
/**
 * Set instance of `RerouteManager` interface to integrate custom re-route implementation to Navigator's pipeline.
 *
 * @param Custom user's re-route manager
 */
- (void)setRerouteManagerForController:(nonnull id<MBNNRerouteManager>)controller;
/**
 * Creates instance of `RerouteManager` based on Mapbox Directions API.
 * You could set it to Navigator using `setRerouteManager` and it will be integrated to re-routes pipeline.
 * Also user could wrap that instance with some app-specific logic and make another class which
 * conforms to `RerouteManager` interface and pass it back to Navigator.
 *
 * @return instance of `RerouteManager` based on Mapbox Directions API
 */
- (nonnull id<MBNNRerouteManager>)createRerouteManager __attribute((ns_returns_retained));
/** Create RouteAlternativesController with default router (HybridRouter by default) */
- (nonnull id<MBNNRouteAlternativesControllerInterface>)createRouteAlternativesController __attribute((ns_returns_retained));
/**
 * Returns interface implementing experimental APIs
 * Caller must guarantee `Navigator` instance is alive when calling any methods of returned instance
 */
- (nonnull id<MBNNExperimental>)getExperimental __attribute((ns_returns_retained));

@end
