// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNScanResultCallback_Internal.h"

NS_SWIFT_NAME(BLEService)
@protocol MBNNBLEService
- (int32_t)registerScanResultCallbackForCallback:(nonnull MBNNScanResultCallback)callback;
- (void)unregisterCallbackForId:(int32_t)id;
@end
