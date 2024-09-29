// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNSensorType.h"

NS_SWIFT_NAME(SensorData)
__attribute__((visibility ("default")))
@interface MBNNSensorData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithSensorType:(MBNNSensorType)sensorType
                                 timestamp:(nonnull NSDate *)timestamp
                          elapsedTimeNanos:(uint64_t)elapsedTimeNanos
                                    values:(nonnull NSArray<NSNumber *> *)values;

@property (nonatomic, readonly) MBNNSensorType sensorType;
@property (nonatomic, readonly, nonnull) NSDate *timestamp;
@property (nonatomic, readonly) uint64_t elapsedTimeNanos;
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *values;

@end
