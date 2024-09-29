// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNOpenLRStandard.h"

/** The record represents a piece of data which is required to match one OpenLR. */
NS_SWIFT_NAME(MatchableOpenLr)
__attribute__((visibility ("default")))
@interface MBNNMatchableOpenLr : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithBase64Encoded:(nonnull NSString *)base64Encoded
                                     standard:(MBNNOpenLRStandard)standard
                                           id:(nonnull NSString *)id;

/** Encoded OpenLR */
@property (nonatomic, readonly, nonnull, copy) NSString *base64Encoded;

/** Encoding standard */
@property (nonatomic, readonly) MBNNOpenLRStandard standard;

/** id of the resulting object */
@property (nonatomic, readonly, nonnull, copy) NSString *id;


@end
