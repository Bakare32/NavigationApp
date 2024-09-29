//
//  SMButton.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import UIKit

final class SMButton: UIButton {
    
    enum ButtonTheme {
        case themeGreen
        case themeGreen_a012
        case clear
        case clearGreenWithGreenBorder
        case clearWithGreenText
        case destructive
    }
    
    override public var isSelected: Bool {
            didSet {
                self.adjustsImageWhenHighlighted = false
                self.backgroundColor = .none
            }
        }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    convenience init(title: String,
                     theme: ButtonTheme = .themeGreen,
                     borderWidth: CGFloat = 0.0,
                     titleSize: ThemeFont.Size = .size18,
                     cornerRadius: CGFloat = 30.0) {
        self.init(type: .system)
        clipsToBounds = true
        layer.cornerRadius = cornerRadius
        setTitle(title, for: .normal)
        titleLabel?.font = .themeFont(fontStyle: .medium, size: titleSize)
        handleTheme(theme: theme, borderWidth: borderWidth)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func handleTheme(theme: ButtonTheme, borderWidth: CGFloat) {
        switch theme {
        case .themeGreen:
            backgroundColor = .themeGreen
            setTitleColor(.white, for: .normal)
        case .themeGreen_a012:
            backgroundColor = .themeGreen.withAlphaComponent(0.05)
            setTitleColor(.themeGreen, for: .normal)
            layer.borderWidth = borderWidth
            layer.borderColor = UIColor.themeGreen.cgColor
        case .clear:
            backgroundColor = .clear
            setTitleColor(.themeWhite, for: .normal)
            layer.borderColor = UIColor.themeWhite.cgColor
            layer.borderWidth = borderWidth
        case .clearGreenWithGreenBorder:
            backgroundColor = .themeGreen.withAlphaComponent(0.05)
            setTitleColor(.themeGreen, for: .normal)
            layer.borderColor = UIColor.themeGreen.cgColor
            layer.borderWidth = borderWidth
        case .destructive:
            backgroundColor = ._FF5656.withAlphaComponent(0.23)
            setTitleColor(._FF5656, for: .normal)
        case .clearWithGreenText:
            backgroundColor = .clear
            setTitleColor(.themeGreen, for: .normal)
            layer.borderColor = UIColor.themeWhite.cgColor
            layer.borderWidth = borderWidth
        }
    }
    
}
