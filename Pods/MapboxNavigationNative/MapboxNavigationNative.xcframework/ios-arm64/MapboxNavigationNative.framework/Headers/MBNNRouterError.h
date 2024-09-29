// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(RouterError)
__attribute__((visibility ("default")))
@interface MBNNRouterError : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithError:(nonnull NSString *)error
                                 code:(uint32_t)code
                            requestId:(uint64_t)requestId;

/** Error message */
@property (nonatomic, readonly, nonnull, copy) NSString *error;

/** Error code */
@property (nonatomic, readonly) uint32_t code;

/** Request ID */
@property (nonatomic, readonly) uint64_t requestId;


@end
