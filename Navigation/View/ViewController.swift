//
//  ViewController.swift
//  Navigation
//
//  Created by Bakare Waris on 24/09/2024.
//

import UIKit
import MapboxMaps
import MapboxNavigation
import MapboxCoreNavigation
import MapboxDirections
import CoreLocation


class ViewController: UIViewController, CLLocationManagerDelegate, NavigationMapViewDelegate, NavigationViewControllerDelegate {
    
    
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
        navigationMapView = NavigationMapView(frame: view.bounds)
        navigationMapView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(navigationMapView)
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
        
        guard let currentLocation = userLocation else {
            print("User location not available.")
            return
        }
        guard let destination = layout.destinationTextField.text, !destination.isEmpty else {
            print("Destination not provided.")
            return
        }
        let routeCalculator = RouteViewModel()
        
        routeCalculator.calculateRoute(from: currentLocation.coordinate, to: destination) { [weak self] route in
            guard let self = self, let route = route else { return }
            self.navigationMapView.showcase(route.routes ?? [])
            let navigationcontroller = NavigationViewController(for: route, routeIndex: 0, routeOptions: routeCalculator.passedOptions!)
            navigationcontroller.delegate = self
            self.present(navigationcontroller, animated: true)
        }
    }
    
    func navigationViewControllerDidDismiss(_ navigationViewController: NavigationViewController, byCanceling canceled: Bool) {
            self.layout.isHidden = false
        }


}


