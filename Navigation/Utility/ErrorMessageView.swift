//
//  ErrorMessageView.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import Foundation
import UIKit

final class ErrorMessageView: UIView {
    
    let errorView: UIView = {
        let v = UIView()
        v.translatesAutoresizingMaskIntoConstraints = false
        return v
    }()
    
    let errorText: UILabel = {
        let v = UILabel()
        v.translatesAutoresizingMaskIntoConstraints = false
        v.textAlignment = .left
        v.font = .themeFont(fontStyle: .medium, size: .size12)
        v.textColor = .red
        return v
    }()
    
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupViews()
        setupConstraints()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func setupViews() {
        addSubview(errorView)
        errorView.addSubview(errorText)
    }
    
    func setupConstraints() {
        errorView.fillSuperview()
        
        
        errorText.anchor(top: errorView.topAnchor, leading: errorView.leadingAnchor, bottom: errorView.bottomAnchor, trailing: errorView.trailingAnchor, padding: UIEdgeInsets(top: 0, left: 2, bottom: 0, right: 0))
    }
}

