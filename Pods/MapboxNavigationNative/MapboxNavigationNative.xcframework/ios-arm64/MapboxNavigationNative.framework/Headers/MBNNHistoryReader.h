// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNHistoryRecord;

NS_SWIFT_NAME(HistoryReader)
__attribute__((visibility ("default")))
@interface MBNNHistoryReader : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/** @param path to history file */
- (nonnull instancetype)initWithPath:(nonnull NSString *)path;

/** returns next event in history file, if no events left returns null */
- (nullable MBNNHistoryRecord *)next __attribute((ns_returns_retained));

@end
