// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNTollCollectionType.h"

NS_SWIFT_NAME(TollCollectionInfo)
__attribute__((visibility ("default")))
@interface MBNNTollCollectionInfo : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithType:(MBNNTollCollectionType)type;

/** type of toll collection point */
@property (nonatomic, readonly) MBNNTollCollectionType type;


@end
