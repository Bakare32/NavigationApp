//
//  BaseView.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import UIKit

open class BaseView: UIView {
    
    open func setup() {
        backgroundColor = .themeWhite
    }
    
    public override init(frame: CGRect) {
        super.init(frame: frame)
        setup()
    }
    
    open override func layoutSubviews() {
        super.layoutSubviews()
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}

