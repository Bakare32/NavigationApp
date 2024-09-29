//
//  RouteViewModel.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import UIKit
import MapboxMaps
import MapboxNavigation
import MapboxCoreNavigation
import MapboxDirections
import CoreLocation

protocol RouteCalculatorService {
    func calculateRoute(from origin: CLLocationCoordinate2D, to destinationAddress: String, completion: @escaping (RouteResponse?) -> Void)
}

final class RouteViewModel: RouteCalculatorService {
    let directions = Directions.shared
    var passedOptions: NavigationRouteOptions?
    
    func calculateRoute(from origin: CLLocationCoordinate2D, to destinationAddress: String, completion: @escaping (RouteResponse?) -> Void) {
        let geocoder = CLGeocoder()
        print(destinationAddress)
        geocoder.geocodeAddressString(destinationAddress) { [weak self] (placemarks, error) in
            guard let placemark = placemarks?.first, let destinationCoordinate = placemark.location?.coordinate else {
                print("Failed to geocode destination address.")
                return
            }
            let originWaypoint = Waypoint(coordinate: origin, coordinateAccuracy: -1, name: "Current Location")
            let destinationWaypoint = Waypoint(coordinate: destinationCoordinate, coordinateAccuracy: -1, name: destinationAddress)
            
            let options = NavigationRouteOptions(waypoints: [originWaypoint, destinationWaypoint])
            self?.passedOptions = options
            self?.directions.calculate(options) { session, result  in
                switch result {
                case .failure(let error):
                    print("Error calculating route: \(error.localizedDescription)")
                    completion(nil)
                case .success(let response):
                    completion(response)
                }
            }
        }
    }
}
