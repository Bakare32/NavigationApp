//
//  RouteViewModel.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import UIKit
import MapboxCoreNavigation
import MapboxDirections
import CoreLocation

protocol RouteCalculatorService {
    func calculateRoute(from origin: CLLocationCoordinate2D, to destinationAddress: CLLocationCoordinate2D, completion: @escaping (Route?) -> Void)
}

final class RouteViewModel: RouteCalculatorService {
    let directions = Directions.shared

    
    func calculateRoute(from start: CLLocationCoordinate2D, to destination: CLLocationCoordinate2D, completion: @escaping (Route?) -> Void) {
        let startWaypoint = Waypoint(coordinate: start, name: "Start")
        let destinationWaypoint = Waypoint(coordinate: destination, name: "Destination")
        
        let options = RouteOptions(waypoints: [startWaypoint, destinationWaypoint], profileIdentifier: .walking)
        
        directions.calculate(options) { [weak self] session, result in
            switch result {
            case .failure(let error):
                print("Error calculating route: \(error.localizedDescription)")
                completion(nil)
            case .success(let response):
                completion(response.routes?.first)
            }
        }
    }
    
}
