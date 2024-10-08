import CoreLocation
import Foundation
import MapboxDirections

/**
 A tuple that pairs an array of coordinates with level of traffic congestion along these coordinates.
 */
typealias CongestionSegment = ([CLLocationCoordinate2D], CongestionLevel)

/**
 A stop dictionary representing the default line widths of the route line by zoom level when `NavigationMapViewDelegate.navigationMapView(_:routeLineLayerWithIdentifier:sourceIdentifier:)` is undefined.
 
 You may use this constant in your implementation of `NavigationMapViewDelegate.navigationMapView(_:routeLineLayerWithIdentifier:sourceIdentifier:)` if you want to keep the default line widths but customize other aspects of the route line.
 */
public var RouteLineWidthByZoomLevel: [Double: Double] = [
    10.0: 8.0,
    13.0: 9.0,
    16.0: 11.0,
    19.0: 22.0,
    22.0: 28.0
]

/**
 The minium distance remaining on a route before overhead zooming is stopped.
 */
public var NavigationMapViewMinimumDistanceForOverheadZooming: CLLocationDistance = 200

/**
 Attribute name for the route line that is used for identifying whether a RouteLeg is the current active leg.
 */
public let CurrentLegAttribute = "isCurrentLeg"

/**
 Attribute name for the route line that is used for identifying different `CongestionLevel` along the route.
 */
public let CongestionAttribute = "congestion"

/**
 The minimum volume for the device before a gentle warning is emitted when beginning navigation.
 */
public let NavigationViewMinimumVolumeForWarning: Float = 0.3

/**
 The distance of fading color change between two different congestion level segments in meters.
 */
public var GradientCongestionFadingDistance: CLLocationDistance = 30.0

extension Notification.Name {
    /**
     Posted when `StyleManager` applies a style that was triggered by change of time of day, or when entering or exiting a tunnel.
     
     This notification is the equivalent of `StyleManagerDelegate.styleManager(_:didApply:)`.
     The user info dictionary contains the key `StyleManagerNotificationUserInfoKey.style` and `StyleManagerNotificationUserInfoKey.styleManager`.
     */
    public static let styleManagerDidApplyStyle: Notification.Name = .init(rawValue: "StyleManagerDidApplyStyle")
}

/**
 Keys in the user info dictionaries of various notifications posted by instances of `StyleManager`.
 */
public struct StyleManagerNotificationUserInfoKey: Hashable, Equatable, RawRepresentable {
    public typealias RawValue = String
    
    public var rawValue: String
    
    public init(rawValue: String) {
        self.rawValue = rawValue
    }
    
    /**
     A key in the user info dictionary of `StyleManagerDidApplyStyleNotification` notification. The corresponding value is an `Style` instance that was applied.
     */
    static let styleKey: StyleManagerNotificationUserInfoKey = .init(rawValue: "style")
    
    /**
     A key in the user info dictionary of `StyleManagerDidApplyStyleNotification` notification. The corresponding value is an `StyleManager` instance that applied the style.
     */
    static let styleManagerKey: StyleManagerNotificationUserInfoKey = .init(rawValue: "styleManager")
}
