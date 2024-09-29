// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNOpenLROrientation.h"
#import "MBNNOpenLRSideOfRoad.h"
#import <CoreLocation/CoreLocation.h>

@class MBNNGraphPosition;

/**  Defines a point along a line on the road graph */
NS_SWIFT_NAME(OpenLRPointAlongLineLocation)
__attribute__((visibility ("default")))
@interface MBNNOpenLRPointAlongLineLocation : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/** Position of the point on the graph */
- (nonnull MBNNGraphPosition *)getPosition __attribute((ns_returns_retained));
/** Specifies on which side of road locates the point */
- (MBNNOpenLRSideOfRoad)getSideOfRoad;
/** Specifies orientation */
- (MBNNOpenLROrientation)getOrientation;
/** Map coordinate of the point */
- (CLLocationCoordinate2D)getCoordinate;

@end
