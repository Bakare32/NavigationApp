// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNActiveGuidanceGeometryEncoding.h"
#import "MBNNActiveGuidanceMode.h"

@class MBNNWaypoint;

/** Declares additional parameters for setRoute method */
NS_SWIFT_NAME(ActiveGuidanceOptions)
__attribute__((visibility ("default")))
@interface MBNNActiveGuidanceOptions : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithMode:(MBNNActiveGuidanceMode)mode
                    geometryEncoding:(MBNNActiveGuidanceGeometryEncoding)geometryEncoding
                           waypoints:(nonnull NSArray<MBNNWaypoint *> *)waypoints;

/** Indicates active guidance mode: driving, walking or cycling */
@property (nonatomic, readonly) MBNNActiveGuidanceMode mode;

/** Indicates geometry encoding */
@property (nonatomic, readonly) MBNNActiveGuidanceGeometryEncoding geometryEncoding;

/** Waypoints array in the given route to track remaining waypoints, including silent */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNWaypoint *> *waypoints;


@end
