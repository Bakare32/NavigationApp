// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNBorderCrossingInfo;
@class MBNNIncidentInfo;
@class MBNNServiceAreaInfo;
@class MBNNTollCollectionInfo;
@class MBNNTunnelInfo;
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRoadObjectMetadataType)
{
    MBNNRoadObjectMetadataTypeIncidentInfo,
    MBNNRoadObjectMetadataTypeTunnelInfo,
    MBNNRoadObjectMetadataTypeBorderCrossingInfo,
    MBNNRoadObjectMetadataTypeTollCollectionInfo,
    MBNNRoadObjectMetadataTypeServiceAreaInfo
} NS_SWIFT_NAME(RoadObjectMetadataType);

NS_SWIFT_NAME(RoadObjectMetadata)
__attribute__((visibility ("default")))
@interface MBNNRoadObjectMetadata : NSObject

- (nonnull instancetype)initWithValue:(nonnull id)value;

+ (nonnull instancetype)fromIncidentInfo:(nonnull MBNNIncidentInfo *)value;
+ (nonnull instancetype)fromTunnelInfo:(nonnull MBNNTunnelInfo *)value;
+ (nonnull instancetype)fromBorderCrossingInfo:(nonnull MBNNBorderCrossingInfo *)value;
+ (nonnull instancetype)fromTollCollectionInfo:(nonnull MBNNTollCollectionInfo *)value;
+ (nonnull instancetype)fromServiceAreaInfo:(nonnull MBNNServiceAreaInfo *)value;

- (BOOL)isIncidentInfo;
- (BOOL)isTunnelInfo;
- (BOOL)isBorderCrossingInfo;
- (BOOL)isTollCollectionInfo;
- (BOOL)isServiceAreaInfo;

- (nonnull MBNNIncidentInfo *)getIncidentInfo;
- (nonnull MBNNTunnelInfo *)getTunnelInfo;
- (nonnull MBNNBorderCrossingInfo *)getBorderCrossingInfo;
- (nonnull MBNNTollCollectionInfo *)getTollCollectionInfo;
- (nonnull MBNNServiceAreaInfo *)getServiceAreaInfo;

@property (nonatomic, nonnull) id value;

@property (nonatomic, readonly) MBNNRoadObjectMetadataType type;

@end
