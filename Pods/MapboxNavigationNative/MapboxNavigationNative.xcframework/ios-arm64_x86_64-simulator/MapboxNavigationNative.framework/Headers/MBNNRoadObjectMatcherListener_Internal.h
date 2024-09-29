// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
@class MBXExpected;

@class MBNNRoadObject;
@class MBNNRoadObjectMatcherError;

NS_SWIFT_NAME(RoadObjectMatcherListener)
@protocol MBNNRoadObjectMatcherListener
- (void)onRoadObjectMatchedForRoadObject:(nonnull MBXExpected *)roadObject;
/** Called if matching a RoadObject with the specified id was cancelled. */
- (void)onMatchingCancelledForId:(nonnull NSString *)id;
@end
