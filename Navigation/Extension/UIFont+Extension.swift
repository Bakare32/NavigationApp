//
//  UIFont+Extension.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//


import UIKit

struct ThemeFont {
    
    enum Style: String {
        case regular = "AlbertSans-Regular"
        case bold = "AlbertSans-Bold"
        case black = "AlbertSans-Black"
        case medium = "AlbertSans-Medium"
        case semiBold = "AlbertSans-SemiBold"
    }
    
    enum Size: CGFloat {
        case size8  =  8
        case size10 = 10
        case size11 = 11
        case size12 = 12
        case size13 = 13
        case size14 = 14
        case size15 = 15
        case size16 = 16
        case size17 = 17
        case size18 = 18
        case size20 = 20
        case size24 = 24
        case size22 = 22
        case size25 = 25
        case size26 = 26
        case size28 = 28
        case size30 = 30
        case size32 = 32
        case size34 = 34
        case size36 = 36
        case size40 = 40
        case size46 = 46
        case size50 = 50
        case size60 = 60
    }
    
    static func appFont(fontStyle: Style, size: Size) -> UIFont {
        return UIFont(name: fontStyle.rawValue, size: size.rawValue) ?? UIFont()
    }
}


extension UIFont {
    
    static func themeFont(fontStyle: ThemeFont.Style, size: ThemeFont.Size) -> UIFont {
      guard let customFont = UIFont(name: fontStyle.rawValue, size: size.rawValue) else {
          return UIFont.systemFont(ofSize: size.rawValue)
      }
      return customFont
    }
}
