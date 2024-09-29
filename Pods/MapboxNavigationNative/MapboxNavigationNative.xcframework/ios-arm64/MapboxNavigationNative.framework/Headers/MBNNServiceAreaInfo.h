// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNServiceAreaType.h"

NS_SWIFT_NAME(ServiceAreaInfo)
__attribute__((visibility ("default")))
@interface MBNNServiceAreaInfo : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithType:(MBNNServiceAreaType)type;

/** type of service area */
@property (nonatomic, readonly) MBNNServiceAreaType type;


@end
