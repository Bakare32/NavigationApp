// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNGenerateEh360Callback.h"

/**
 * Contains experimental APIs which can be changed without any deprecation process.
 * Also note that this interface will be exposed directly to the end user without any additional
 * wrappers from platform side(it is done to speed up delivery of the new features to the end user)
 */
NS_SWIFT_NAME(Experimental)
@protocol MBNNExperimental
/** Generate electronic horizon 360 asynchronously and call the callback */
- (void)generateEh360ForGraphTraversalRadiusInMeters:(double)graphTraversalRadiusInMeters
                                            callback:(nonnull MBNNGenerateEh360Callback)callback;
@end
