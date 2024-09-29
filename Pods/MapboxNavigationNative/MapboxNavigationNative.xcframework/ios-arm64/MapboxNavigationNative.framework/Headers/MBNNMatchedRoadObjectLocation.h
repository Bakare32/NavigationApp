// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNMatchedGantryLocation;
@class MBNNMatchedPointLocation;
@class MBNNMatchedPolygonLocation;
@class MBNNMatchedPolylineLocation;
@class MBNNMatchedSubgraphLocation;
@class MBNNOpenLRLineLocation;
@class MBNNOpenLRPointAlongLineLocation;
@class MBNNRouteAlertLocation;
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNMatchedRoadObjectLocationType)
{
    MBNNMatchedRoadObjectLocationTypeOpenLRLineLocation,
    MBNNMatchedRoadObjectLocationTypeOpenLRPointAlongLineLocation,
    MBNNMatchedRoadObjectLocationTypeMatchedPolylineLocation,
    MBNNMatchedRoadObjectLocationTypeMatchedGantryLocation,
    MBNNMatchedRoadObjectLocationTypeMatchedPolygonLocation,
    MBNNMatchedRoadObjectLocationTypeMatchedPointLocation,
    MBNNMatchedRoadObjectLocationTypeMatchedSubgraphLocation,
    MBNNMatchedRoadObjectLocationTypeRouteAlertLocation
} NS_SWIFT_NAME(MatchedRoadObjectLocationType);

NS_SWIFT_NAME(MatchedRoadObjectLocation)
__attribute__((visibility ("default")))
@interface MBNNMatchedRoadObjectLocation : NSObject

- (nonnull instancetype)initWithValue:(nonnull id)value;

+ (nonnull instancetype)fromOpenLRLineLocation:(nonnull MBNNOpenLRLineLocation *)value;
+ (nonnull instancetype)fromOpenLRPointAlongLineLocation:(nonnull MBNNOpenLRPointAlongLineLocation *)value;
+ (nonnull instancetype)fromMatchedPolylineLocation:(nonnull MBNNMatchedPolylineLocation *)value;
+ (nonnull instancetype)fromMatchedGantryLocation:(nonnull MBNNMatchedGantryLocation *)value;
+ (nonnull instancetype)fromMatchedPolygonLocation:(nonnull MBNNMatchedPolygonLocation *)value;
+ (nonnull instancetype)fromMatchedPointLocation:(nonnull MBNNMatchedPointLocation *)value;
+ (nonnull instancetype)fromMatchedSubgraphLocation:(nonnull MBNNMatchedSubgraphLocation *)value;
+ (nonnull instancetype)fromRouteAlertLocation:(nonnull MBNNRouteAlertLocation *)value;

- (BOOL)isOpenLRLineLocation;
- (BOOL)isOpenLRPointAlongLineLocation;
- (BOOL)isMatchedPolylineLocation;
- (BOOL)isMatchedGantryLocation;
- (BOOL)isMatchedPolygonLocation;
- (BOOL)isMatchedPointLocation;
- (BOOL)isMatchedSubgraphLocation;
- (BOOL)isRouteAlertLocation;

- (nonnull MBNNOpenLRLineLocation *)getOpenLRLineLocation;
- (nonnull MBNNOpenLRPointAlongLineLocation *)getOpenLRPointAlongLineLocation;
- (nonnull MBNNMatchedPolylineLocation *)getMatchedPolylineLocation;
- (nonnull MBNNMatchedGantryLocation *)getMatchedGantryLocation;
- (nonnull MBNNMatchedPolygonLocation *)getMatchedPolygonLocation;
- (nonnull MBNNMatchedPointLocation *)getMatchedPointLocation;
- (nonnull MBNNMatchedSubgraphLocation *)getMatchedSubgraphLocation;
- (nonnull MBNNRouteAlertLocation *)getRouteAlertLocation;

@property (nonatomic, nonnull) id value;

@property (nonatomic, readonly) MBNNMatchedRoadObjectLocationType type;

@end
