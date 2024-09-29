// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Standard of OpenLR */
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNOpenLRStandard)
{
    /**
     * TomTom OpenLR (http://www.openlr.org/)
     * Supported references: line location, point along line, polygon.
     */
    MBNNOpenLRStandardTomTom,
    /**
     * TPEG OpenLR.
     * Only line locations are supported.
     */
    MBNNOpenLRStandardTPEG
} NS_SWIFT_NAME(OpenLRStandard);
