// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNCompassUpdateCallback_Internal.h"
#import "MBNNIMUUpdateCallback_Internal.h"

NS_SWIFT_NAME(IMUService)
@protocol MBNNIMUService
- (int32_t)registerCompassUpdateCallbackForCallback:(nonnull MBNNCompassUpdateCallback)callback;
- (int32_t)registerIMUUpdateCallbackForCallback:(nonnull MBNNIMUUpdateCallback)callback;
- (void)unregisterCallbackForId:(int32_t)id;
@end
