//
//  Model.swift
//  Live
//
//  Created by leo on 16/7/13.
//  Copyright © 2016年 io.ltebean. All rights reserved.
//

import Foundation

struct Room {
    
    var key: String
    var title: String
    
    init(dict: [String: AnyObject]) {
        title = dict["title"] as! String
        key = dict["key"] as! String
    }
    
    func toDict() -> [String: AnyObject] {
        return [
            "title": title as AnyObject,
            "key": key as AnyObject
        ]
    }
}


struct Comment {
    
    var text: String
    
    init(dict: [String: AnyObject]) {
        text = dict["text"] as! String
    }
}


//struct User {
//    
//    var id = Int(arc4random())
//    
//    static let currentUser = User()
//}

struct Config {
    
    static var rtmpPushUrl = "rtmp://106.187.100.229/live/"
    static var rtmpPlayUrl = "rtmp://106.187.100.229/live/"
    static var serverUrl = "http://192.168.100.70:3000"
    
}

public extension String {
    
    
    static func random(_ length: Int = 4) -> String {
        let base = "abcdefghijklmnopqrstuvwxyz"
        var randomString: String = ""
        for _ in 0..<length {
            let randomValue = arc4random_uniform(UInt32(base.characters.count))
            randomString += "\(base[base.characters.index(base.startIndex, offsetBy: Int(randomValue))])"
        }
        return randomString
    }
    
}
