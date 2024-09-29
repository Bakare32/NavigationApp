// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRoadObjectType)
{
    /** road object represents some road incident */
    MBNNRoadObjectTypeIncident,
    MBNNRoadObjectTypeTollCollectionPoint,
    MBNNRoadObjectTypeBorderCrossing,
    MBNNRoadObjectTypeTunnel,
    MBNNRoadObjectTypeRestrictedArea,
    MBNNRoadObjectTypeServiceArea,
    MBNNRoadObjectTypeBridge,
    /** road object was added by user(via `RoadObjectsStore.addCustomRoadObject`) */
    MBNNRoadObjectTypeCustom
} NS_SWIFT_NAME(RoadObjectType);
