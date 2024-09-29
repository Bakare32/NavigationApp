// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Reroute state */
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRerouteState)
{
    /** RerouteManager is idle. */
    MBNNRerouteStateIdle,
    /** Reroute has been interrupted. */
    MBNNRerouteStateInterrupted,
    /** Re-route request has failed. */
    MBNNRerouteStateFailed,
    /** Route fetching is in progress. */
    MBNNRerouteStateFetchingRoute,
    /** Route has been fetched. */
    MBNNRerouteStateRouteFetched
} NS_SWIFT_NAME(RerouteState);
