//
//  HomeViewLayout.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import UIKit

final class HomeViewLayout: BaseView {
    
    let originTextField = UITextField()
    let destinationTextField = UITextField()
    let continueButton = SMButton(title: "Find Route")
    
    override func setup() {
        super.setup()
        addSubviews(originTextField, destinationTextField, continueButton)
        originTextField.borderStyle = .roundedRect
        originTextField.placeholder = "Enter start address"
        destinationTextField.borderStyle = .roundedRect
        destinationTextField.placeholder = "Enter destination address"
        originTextField.constrainHeight(constant: 64)
        destinationTextField.constrainHeight(constant: 64)
        continueButton.constrainHeight(constant: 60)
        
        continueButton.anchor(top: nil, leading: leadingAnchor, bottom: bottomAnchor, trailing: trailingAnchor, padding: .init(top: 0, left: 18, bottom: 30, right: 18))
        destinationTextField.anchor(top: nil, leading: leadingAnchor, bottom: continueButton.topAnchor, trailing: trailingAnchor, padding: .init(top: 0, left: 18, bottom: 20, right: 18))
        originTextField.anchor(top: nil, leading: leadingAnchor, bottom: destinationTextField.topAnchor, trailing: trailingAnchor, padding: .init(top: 0, left: 18, bottom: 20, right: 18))
        continueButton.addTarget(self, action: #selector(handleContinueButtonTapped), for: .touchUpInside)
    }

    @objc private func handleContinueButtonTapped() {
            self.endEditing(true)
        }
}

#if DEBUG && canImport(SwiftUI)
import SwiftUI

@available(iOS 13.0.0, *)
struct HomeViewLayoutPreview: PreviewProvider {
    static var previews: some View {
        BasePreviewProvider<HomeViewLayout>()
    }
}

#endif

