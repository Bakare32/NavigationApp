//
//  ViewController.swift
//  Navigation
//
//  Created by Bakare Waris on 24/09/2024.
//

import UIKit
import MapboxMaps
import MapboxDirections

class ViewController: UIViewController {
    
    var mapView: MapView!
    var startAddressTextField: UITextField!
    var destinationAddressTextField: UITextField!
    var routeButton: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        setupMapView()
        setupUI()
    }
    
    func setupMapView() {
           let mapInitOptions = MapInitOptions(styleURI: .streets)
           mapView = MapView(frame: view.bounds, mapInitOptions: mapInitOptions)
           mapView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
           view.addSubview(mapView)
       }
    
    func setupUI() {
            // Start Address Text Field
            startAddressTextField = UITextField(frame: CGRect(x: 20, y: 50, width: view.frame.width - 40, height: 40))
            startAddressTextField.borderStyle = .roundedRect
            startAddressTextField.placeholder = "Enter start address"
            view.addSubview(startAddressTextField)
            
            // Destination Address Text Field
            destinationAddressTextField = UITextField(frame: CGRect(x: 20, y: 100, width: view.frame.width - 40, height: 40))
            destinationAddressTextField.borderStyle = .roundedRect
            destinationAddressTextField.placeholder = "Enter destination address"
            view.addSubview(destinationAddressTextField)
            
            // Route Button
            routeButton = UIButton(type: .system)
            routeButton.frame = CGRect(x: 20, y: 150, width: view.frame.width - 40, height: 50)
            routeButton.setTitle("Get Route", for: .normal)
            routeButton.addTarget(self, action: #selector(getRoute), for: .touchUpInside)
            view.addSubview(routeButton)
        }
    
    @objc func getRoute() {
        
        let startCoordinate = CLLocationCoordinate2D(latitude: 37.7749, longitude: -122.4194)
        let destinationCoordinate = CLLocationCoordinate2D(latitude: 37.7849, longitude: -122.4094) 
        
        let routeCalculator = RouteCalculator()
        
        routeCalculator.calculateRoute(from: startCoordinate, to: destinationCoordinate) { [weak self] route in
            guard let self = self, let route = route else { return }
            
            // Render route on the map
            self.drawRoute(route)
        }
    }


    
    func drawRoute(_ route: Route) {
        guard let routeShape = route.shape else { return }
        var routeCoordinates: [CLLocationCoordinate2D] = []
        
        for coord in routeShape.coordinates {
            routeCoordinates.append(CLLocationCoordinate2D(latitude: coord.latitude, longitude: coord.longitude))
        }

        let polylineAnnotation = PolylineAnnotation(lineCoordinates: routeCoordinates)

        let polylineManager = mapView.annotations.makePolylineAnnotationManager()

        polylineManager.annotations = [polylineAnnotation]

        if let firstCoord = routeCoordinates.first {
            let cameraOptions = CameraOptions(center: firstCoord, zoom: 14.0)
            mapView.mapboxMap.setCamera(to: cameraOptions)
        }
    }


}


class RouteCalculator {
    let directions = Directions.shared
    
    func calculateRoute(from start: CLLocationCoordinate2D, to destination: CLLocationCoordinate2D, completion: @escaping (Route?) -> Void) {
        let startWaypoint = Waypoint(coordinate: start, name: "Start")
        let destinationWaypoint = Waypoint(coordinate: destination, name: "Destination")
        
        let options = RouteOptions(waypoints: [startWaypoint, destinationWaypoint], profileIdentifier: .walking)
        
        directions.calculate(options) { [weak self] (result) in
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
