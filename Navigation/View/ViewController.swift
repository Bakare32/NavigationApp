//
//  ViewController.swift
//  Navigation
//
//  Created by Bakare Waris on 24/09/2024.
//

import UIKit
import MapboxCoreNavigation
import MapboxDirections
import CoreLocation
import UIKit
import MapboxDirections


class ViewController: UIViewController, CLLocationManagerDelegate {
    
    
    var mapView: MapView!
    var navigationMapView: NavigationMapView!
    
    
    private let layout = HomeViewLayout()
    
    var locationManager: CLLocationManager!
    var userLocation: CLLocation?
    var layoutBottomConstraint: NSLayoutConstraint?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .white
        setupNavigationMapView()
        
        layout.continueButton.addTarget(self, action: #selector(getRoute), for: .touchUpInside)
        
        setupLocationManager()
        
        setupKeyboardObservers()
    }
    
    func setupLocationManager() {
           locationManager = CLLocationManager()
           locationManager.delegate = self
           checkLocationAuthorization()
       }
       
       func checkLocationAuthorization() {
           let authorizationStatus = locationManager.authorizationStatus
           switch authorizationStatus {
           case .notDetermined:
               locationManager.requestWhenInUseAuthorization()
           case .restricted, .denied:
               print("Location access denied or restricted.")
           case .authorizedAlways, .authorizedWhenInUse:
               locationManager.startUpdatingLocation()
           @unknown default:
               break
           }
       }
    

    
    func setupNavigationMapView() {
        let mapInitOptions = MapInitOptions(styleURI: .streets)
        mapView = MapView(frame: view.bounds, mapInitOptions: mapInitOptions)
        mapView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(mapView)
        view.addSubview(layout)
        layout.backgroundColor = .clear
        layout.translatesAutoresizingMaskIntoConstraints = false
        layout.anchor(top: navigationMapView.bottomAnchor, leading: navigationMapView.leadingAnchor, bottom: nil, trailing: navigationMapView.trailingAnchor, padding: .init(top: 100, left: 0, bottom: 0, right: 0))
        
        
        layoutBottomConstraint = layout.bottomAnchor.constraint(equalTo: navigationMapView.bottomAnchor, constant: 0)
        layoutBottomConstraint?.isActive = true
        
        layout.constrainHeight(constant: 300)
        
    }
    
    private func setupKeyboardObservers() {
        NotificationCenter.default.addObserver(self, selector: #selector(handleKeyboardWillShow), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(handleKeyboardWillHide), name: UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    @objc private func handleKeyboardWillShow(notification: NSNotification) {
        guard let userInfo = notification.userInfo,
              let keyboardFrame = userInfo[UIResponder.keyboardFrameEndUserInfoKey] as? CGRect else {
            return
        }
        

        layoutBottomConstraint?.constant = -keyboardFrame.height
        UIView.animate(withDuration: 0.3) {
            self.view.layoutIfNeeded()
        }
    }
    
    @objc private func handleKeyboardWillHide(notification: NSNotification) {
        layoutBottomConstraint?.constant = 0
        UIView.animate(withDuration: 0.3) {
            self.view.layoutIfNeeded()
        }
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
            guard let location = locations.first else { return }
            self.userLocation = location
            locationManager.stopUpdatingLocation()
            let geocoder = CLGeocoder()
            geocoder.reverseGeocodeLocation(location) { [weak self] (placemarks, error) in
                if let placemark = placemarks?.first {
                    if let address = placemark.name {
                        self?.layout.originTextField.text = address
                    }
                }
            }
        }
    
    
    
    @objc func getRoute() {
       
        let startCoordinate = CLLocationCoordinate2D(latitude: 37.7749, longitude: -122.4194)
        let destinationCoordinate = CLLocationCoordinate2D(latitude: 37.7849, longitude: -122.4094)
        
        let routeCalculator = RouteViewModel()
        
        routeCalculator.calculateRoute(from: startCoordinate, to: destinationCoordinate) { [weak self] route in
            guard let self = self, let route = route else { return }
            
            // Render route on the map
            self.drawRoute(route)
        }
    }

    func drawRoute(_ route: Route) {
        var routeCoordinates = route.shape!.coordinates
        let routeLine = Polyline(coordinates: routeCoordinates)
        
        let lineManager = self.mapView.annotations.makePolylineAnnotationManager()
        lineManager.annotations = [routeLine]
        
        // Optionally zoom into the route
        let cameraOptions = CameraOptions(center: routeCoordinates.first, zoom: 14.0)
        mapView.mapboxMap.setCamera(to: cameraOptions)
    }

    
}


