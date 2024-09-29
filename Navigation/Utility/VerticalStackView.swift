//
//  VerticalStackView.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import Foundation
import UIKit

final class VerticalStack: UIStackView {
    
    init(arrangedSubviews: [UIView], spacing: CGFloat = 0, distribution: UIStackView.Distribution = .fill, alignment: UIStackView.Alignment = .fill) {
        super.init(frame: .zero)
        arrangedSubviews.forEach { addArrangedSubview($0) }
        self.spacing = spacing
        self.axis = .vertical
        self.distribution = distribution
        self.alignment = alignment
    }
    
    required init(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
