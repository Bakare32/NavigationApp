// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNCacheHandle;
@class MBNNHistoryRecorderHandle;

NS_SWIFT_NAME(Router)
__attribute__((visibility ("default")))
__attribute__((deprecated("Public Router class for onboard router is redundant. Please use: 'MBNNRouterFactory' instead.", "MBNNRouterFactory")))
@interface MBNNRouter : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs router object with given dependencies
 * @param `cache` cache created with `CacheFactory`
 * @param historyRecorder       History recorder created with `HistoryRecorderHandle::build()` method
 */
- (nonnull instancetype)initWithCache:(nonnull MBNNCacheHandle *)cache
                      historyRecorder:(nullable MBNNHistoryRecorderHandle *)historyRecorder;


@end
