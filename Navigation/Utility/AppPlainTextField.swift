//
//  AppPlainTextField.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import Foundation
import UIKit
import AVFAudio

final class AppPlainTextField: BaseView {
    
    private let outerContainer = UIView()
    private let innerContainer = UIView()
    let textField = UITextField()
    private let placeholderLabel = UILabel()
    private let errorView = ErrorMessageView()
    
    var placeholderText: String? {
        get { placeholderLabel.text }
        set { setTitle(to: newValue) }
    }
    
    var text: String? {
        get { textField.text?.asInput }
        set {
            textField.isHidden = false
            textField.text = newValue
        }
    }
    
    init(placeholderText: String? = nil) {
        self.placeholderLabel.text = placeholderText
        super.init(frame: .zero)
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func setup() {
        super.setup()
        backgroundColor = .clear
        placeholderLabel.textColor =  ._8C9FAB
        innerContainer.backgroundColor = ._F9F9F9
        textField.font = .themeFont(fontStyle: .medium, size: .size16)
        placeholderLabel.font = .themeFont(fontStyle: .medium, size: .size14)
        
        let contentStack = VerticalStack(arrangedSubviews: [placeholderLabel, textField], spacing: 4, distribution: .fill)
        outerContainer.addSubviews(innerContainer)
        innerContainer.addSubviews(contentStack)
        innerContainer.addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(enableFirstResponder)))
        
        outerContainer.layer.borderWidth = 2
        outerContainer.layer.cornerRadius = 8
        outerContainer.layer.borderColor = UIColor._DBDFEB.cgColor
        
        innerContainer.layer.borderWidth = 1.5
        innerContainer.layer.cornerRadius = 6
        innerContainer.layer.borderColor = UIColor.clear.cgColor
        
        let viewStack = VerticalStack(arrangedSubviews: [outerContainer, errorView], spacing: 4)
        addSubviews(viewStack)
        viewStack.fillSuperview()
        
        outerContainer.constrainHeight(constant: 64)
        
        innerContainer.fillSuperview(padding: .init(top: 2, left: 2, bottom: 2, right: 2))
        contentStack.anchor(top: nil, leading: innerContainer.leadingAnchor, bottom: nil, trailing: innerContainer.trailingAnchor, padding: .init(top: 0, left: 16, bottom: 0, right: 16))
        contentStack.centerYInSuperview()
        textField.addTarget(self, action: #selector(addBorder), for: .editingDidBegin)
        textField.addTarget(self, action: #selector(removeBorder), for: .editingDidEnd)
        textField.isHidden = true
        
        clearError()
        removeBorder()
    }
    
    func setKeyboardType(to type: UIKeyboardType) {
        textField.keyboardType = type
        if type == .emailAddress {
            textField.autocapitalizationType = .none
        }
    }
    
    private func setTitle(to text: String?) {
        placeholderLabel.text = text
    }
    
    @objc private func enableFirstResponder() {
        textField.isHidden = false
        textField.becomeFirstResponder()
    }
    
    @objc private func addBorder() {
        placeholderLabel.isHidden = true
        innerContainer.layer.borderColor = UIColor.themeGreen.cgColor
        outerContainer.layer.borderColor = UIColor.themeGreen.cgColor
        clearError()
    }
    
    @objc private func removeBorder() {
        if textField.text?.count ?? 0 < 1 {
            placeholderLabel.isHidden = false
        } else {
            placeholderLabel.isHidden = true
        }
        innerContainer.layer.borderColor = UIColor._DBDFEB.cgColor
        outerContainer.layer.borderColor = UIColor.clear.cgColor
    }
    
    func notifyError(with message: String? = nil) {
        AudioServicesPlaySystemSound(kSystemSoundID_Vibrate)
        errorView.errorText.text = message ?? "Please input a value"
        errorView.isHidden = false
    }
    
    func clearError() {
        errorView.errorText.text = nil
        errorView.isHidden = true
    }
    
    func disable() {
        textField.isUserInteractionEnabled = false
        textField.textColor = ._999999
    }
    
    func enable() {
        textField.isUserInteractionEnabled = true
        textField.textColor = .black
    }
    
    func makeItNumeric() {
        textField.keyboardType = .numberPad
    }
    
   
}

#if DEBUG && canImport(SwiftUI)
import SwiftUI

struct AppPlainTextFieldPreview: PreviewProvider {
    @available(iOS 13.0.0, *)
    static var previews: some View {
        BasePreviewProvider<AppPlainTextField>()
    }
}

#endif

