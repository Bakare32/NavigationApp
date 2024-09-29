import Foundation

enum RouteLineType {
    
    case source(isMainRoute: Bool, isSourceCasing: Bool)
    
    case route(isMainRoute: Bool)
    
    case routeCasing(isMainRoute: Bool)
}
