//
//  String+Extension.swift
//  Navigation
//
//  Created by Bakare Waris on 29/09/2024.
//

import Foundation

extension Date {
    
    enum TransactionDateFormat: String {
        case monthDateYear = "MMM dd, yyyy"
        case serverDate = "yyyy-MM-dd'T'HH:mm:ss.SSS'Z'"
        case testDate = "yyyy-MM-dd HH:mm:ss.SSS 'Z'"
        case monthDateYearSec = "dd-MM-yyyy HH:mm:ss"
        case dayMonthYear = "dd MM yyyy"
        
        var identifier: String { rawValue }
    }
    
    func displayDate(in formatStyle: TransactionDateFormat) -> String? {
        return Date.formatDate(in: formatStyle).string(from: self)
    }
    
    static func formatDate(in dateFormat: TransactionDateFormat) -> DateFormatter {
        let formatter = DateFormatter()
        formatter.dateStyle = .full
        formatter.dateFormat = dateFormat.identifier
        formatter.locale = Locale(identifier: "en_US_POSIX")
        return formatter
    }
    
    func dayNumber(from lastDate: Date) -> Int {
        return Calendar.current.dateComponents([.day], from: lastDate, to: self).day ?? 0
    }
   
    func getGreeting() -> String {
        let hour = Calendar.current.component(.hour, from: self)
        var greeting = "..."
        switch hour {
        case 4..<12 : greeting = "Good Morning ☀️"
        case 12..<17 : greeting = "Good Afternoon 🌞"
        case 17..<22 : greeting = "Good Evening 🌙"
        default: greeting = "Good Evening 🌙"
        }
        
        return greeting
    }
    
    func timeAgoDisplay() -> String {
        
        let calendar = Calendar.current
        let minuteAgo = calendar.date(byAdding: .minute, value: -1, to: Date())!
        let hourAgo = calendar.date(byAdding: .hour, value: -1, to: Date())!
        let dayAgo = calendar.date(byAdding: .day, value: -1, to: Date())!
        let weekAgo = calendar.date(byAdding: .day, value: -7, to: Date())!
        
        if minuteAgo < self {
            let diff = Calendar.current.dateComponents([.second], from: self, to: Date()).second ?? 0
            return "\(diff) sec ago"
        } else if hourAgo < self {
            let diff = Calendar.current.dateComponents([.minute], from: self, to: Date()).minute ?? 0
            return "\(diff) min ago"
        } else if dayAgo < self {
            let diff = Calendar.current.dateComponents([.hour], from: self, to: Date()).hour ?? 0
            return "\(diff) hrs ago"
        } else if weekAgo < self {
            let diff = Calendar.current.dateComponents([.day], from: self, to: Date()).day ?? 0
            return "\(diff) days ago"
        }
        let diff = Calendar.current.dateComponents([.weekOfYear], from: self, to: Date()).weekOfYear ?? 0
        return "\(diff) weeks ago"
    }
}



extension String {
    
    var isValidEmail: Bool {
        let emailRegex = "[A-Z0-9a-z._%+-]{0,64}+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}"
        return NSPredicate(format: "SELF MATCHES %@", emailRegex).evaluate(with: self)
    }
    
    var isValidURL: Bool {
        let urlRegEx =
        "^(http|https|ftp)://([a-zA-Z0-9.-]+(?::[a-zA-Z0-9.&amp;%$-]+)*@)*((25[0-5]|2[0-4][0-9]|[0-1][0-9]{2}|[1-9][0-9]|[1-9])\\.(25[0-5]|2[0-4][0-9]|[0-1][0-9]{2}|[1-9][0-9]|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1][0-9]{2}|[1-9][0-9]|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1][0-9]{2}|[1-9][0-9]|[0-9])|localhost|([a-zA-Z0-9-]+\\.)*[a-zA-Z0-9-]+\\.(com|ru|kz|edu|gov|int|mil|net|org|biz|arpa|info|name|pro|aero|coop|museum|[a-zA-Z]{2}))(?::[0-9]+)*(/($|[a-zA-Z0-9.,?'\\\\+&amp;%$#=~_-]+))*(?:\\(\\d+\\))?$"
        return NSPredicate(format: "SELF MATCHES %@", urlRegEx).evaluate(with: self)
    }
    
    func containsHTTPS() -> Bool {
        return self.contains("https://")
    }
    
    
    var isValidText: Bool {
        return !self.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }
    
    var asInput: String? {
        guard self.isValidText else { return nil }
        return self
    }
    
    func asDate(from format: Date.TransactionDateFormat) -> Date? {
        Date.formatDate(in: format).date(from: self)
    }
    
    var trimmedPhoneNumber: String {
        let characterSet = CharacterSet(charactersIn: "+0123456789")
        return self.components(separatedBy: characterSet.inverted).joined()
    }
    
    var timeLapse: String {
        return "1m"
    }
    
    func decodejwtToken() -> [String: Any] {
        let segments = self.components(separatedBy: ".")
        return decodeJWTPart(segments[1]) ?? [:]
    }
    
    func base64UrlDecode(_ value: String) -> Data? {
        var base64 = value
            .replacingOccurrences(of: "-", with: "+")
            .replacingOccurrences(of: "_", with: "/")
        
        let length = Double(base64.lengthOfBytes(using: String.Encoding.utf8))
        let requiredLength = 4 * ceil(length / 4.0)
        let paddingLength = requiredLength - length
        if paddingLength > 0 {
            let padding = "".padding(toLength: Int(paddingLength), withPad: "=", startingAt: 0)
            base64 = base64 + padding
        }
        return Data(base64Encoded: base64, options: .ignoreUnknownCharacters)
    }
    
    
    func decodeJWTPart(_ value: String) -> [String: Any]? {
        guard let bodyData = base64UrlDecode(value),
            let json = try? JSONSerialization.jsonObject(with: bodyData, options: []), let payload = json as? [String: Any] else {
                return nil
        }
        return payload
    }
    
    func formatPhoneNumber(with mask: String = "+XXX XXX XXX XXXX") -> String {
        let numbers = self.replacingOccurrences(of: "[^0-9]", with: "", options: .regularExpression)
        var result = ""
        var index = numbers.startIndex // numbers iterator

        // iterate over the mask characters until the iterator of numbers ends
        for ch in mask where index < numbers.endIndex {
            if ch == "X" {
                // mask requires a number in this place, so take the next one
                result.append(numbers[index])

                // move numbers iterator to the next index
                index = numbers.index(after: index)

            } else {
                result.append(ch) // just append a mask character
            }
        }
        return result
    }
    
   
    func toSimpleDateFromFormat(outputFormat : String = "yyyy-MM-dd", inputFormat : String = "d MMMM yyyy")-> String {
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = inputFormat
        guard let date = dateFormatter.date(from: self) else { return "N/A" }
        
        let fdateFormatter = DateFormatter()
        fdateFormatter.dateFormat = outputFormat
        return fdateFormatter.string(from: date)
    }
    
}

