//
//  BasePreviewProvider.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

#if DEBUG && canImport(SwiftUI)
import SwiftUI

@available(iOS 13.0, *)
public struct BasePreviewProvider<SMview: UIView>: UIViewRepresentable {
    
    @available(iOS 13.0, *)
    public func makeUIView(context: UIViewRepresentableContext<BasePreviewProvider<SMview>>) -> SMview {
        return SMview()
    }
    
    @available(iOS 13.0, *)
    public func updateUIView(_ uiView: SMview, context: UIViewRepresentableContext<BasePreviewProvider<SMview>>) {
        
    }
    
    public typealias UIViewType = SMview
    init() {}
        
}

#endif

