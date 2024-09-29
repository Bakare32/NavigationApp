// This file is generated and will be overwritten automatically.

#import "MBNNRouterFactory.h"

@interface MBNNRouterFactory ()
+ (nonnull id<MBNNRouterInterface>)buildForType:(MBNNRouterType)type
                                          cache:(nonnull MBNNCacheHandle *)cache
                                historyRecorder:(nullable MBNNHistoryRecorderHandle *)historyRecorder __attribute((ns_returns_retained));
@end
