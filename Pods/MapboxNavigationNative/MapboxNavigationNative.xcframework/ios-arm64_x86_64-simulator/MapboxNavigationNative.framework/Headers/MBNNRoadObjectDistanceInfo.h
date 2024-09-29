// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNGantryDistanceInfo;
@class MBNNLineDistanceInfo;
@class MBNNPointDistanceInfo;
@class MBNNPolygonDistanceInfo;
@class MBNNSubGraphDistanceInfo;
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRoadObjectDistanceInfoType)
{
    MBNNRoadObjectDistanceInfoTypePointDistanceInfo,
    MBNNRoadObjectDistanceInfoTypeGantryDistanceInfo,
    MBNNRoadObjectDistanceInfoTypePolygonDistanceInfo,
    MBNNRoadObjectDistanceInfoTypeSubGraphDistanceInfo,
    MBNNRoadObjectDistanceInfoTypeLineDistanceInfo
} NS_SWIFT_NAME(RoadObjectDistanceInfoType);

NS_SWIFT_NAME(RoadObjectDistanceInfo)
__attribute__((visibility ("default")))
@interface MBNNRoadObjectDistanceInfo : NSObject

- (nonnull instancetype)initWithValue:(nonnull id)value;

+ (nonnull instancetype)fromPointDistanceInfo:(nonnull MBNNPointDistanceInfo *)value;
+ (nonnull instancetype)fromGantryDistanceInfo:(nonnull MBNNGantryDistanceInfo *)value;
+ (nonnull instancetype)fromPolygonDistanceInfo:(nonnull MBNNPolygonDistanceInfo *)value;
+ (nonnull instancetype)fromSubGraphDistanceInfo:(nonnull MBNNSubGraphDistanceInfo *)value;
+ (nonnull instancetype)fromLineDistanceInfo:(nonnull MBNNLineDistanceInfo *)value;

- (BOOL)isPointDistanceInfo;
- (BOOL)isGantryDistanceInfo;
- (BOOL)isPolygonDistanceInfo;
- (BOOL)isSubGraphDistanceInfo;
- (BOOL)isLineDistanceInfo;

- (nonnull MBNNPointDistanceInfo *)getPointDistanceInfo;
- (nonnull MBNNGantryDistanceInfo *)getGantryDistanceInfo;
- (nonnull MBNNPolygonDistanceInfo *)getPolygonDistanceInfo;
- (nonnull MBNNSubGraphDistanceInfo *)getSubGraphDistanceInfo;
- (nonnull MBNNLineDistanceInfo *)getLineDistanceInfo;

@property (nonatomic, nonnull) id value;

@property (nonatomic, readonly) MBNNRoadObjectDistanceInfoType type;

@end
