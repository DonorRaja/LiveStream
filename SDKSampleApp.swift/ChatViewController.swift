//
//  ChatViewController.swift
//  SwiftExample
//
//  Created by Dan Leonard on 5/11/16.
//  Copyright © 2016 MacMeDan. All rights reserved.
//

import UIKit
import JSQMessagesViewController
import SocketIO
import StarscreamSocketIO

class ChatViewController: JSQMessagesViewController {
    var messages = [JSQMessage]()
    let defaults = UserDefaults.standard
    var conversation: Conversation?
    var incomingBubble: JSQMessagesBubbleImage!
    var outgoingBubble: JSQMessagesBubbleImage!
    fileprivate var displayName: String!
    
    var comments: [JSQMessage] = []
    var room: Room!
    
    var socket: SocketIOClient!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.messages = makeGroupConversation()
        self.inputToolbar.contentView.textView.placeHolder = "Chat here..."
        self.inputToolbar.contentView.backgroundColor = .white
        self.collectionView.backgroundColor = UIColor.lightGray.withAlphaComponent(0.45)
        self.senderId = self.senderId()
        self.senderDisplayName = self.senderDisplayName()
        
            // Bubbles with tails
            incomingBubble = JSQMessagesBubbleImageFactory().incomingMessagesBubbleImage(with: UIColor.clear)
            outgoingBubble = JSQMessagesBubbleImageFactory().outgoingMessagesBubbleImage(with: UIColor.clear)
 
        /**
         *  Example on showing or removing Avatars based on user settings.
         */
           collectionView?.collectionViewLayout.incomingAvatarViewSize = CGSize(width: kJSQMessagesCollectionViewAvatarSizeDefault, height:kJSQMessagesCollectionViewAvatarSizeDefault )
            collectionView?.collectionViewLayout.outgoingAvatarViewSize = CGSize(width: kJSQMessagesCollectionViewAvatarSizeDefault, height:kJSQMessagesCollectionViewAvatarSizeDefault )
        
        // This is a beta feature that mostly works but to make things more stable it is diabled.
        collectionView?.collectionViewLayout.springinessEnabled = false
        
        automaticallyScrollsToMostRecentMessage = true

        self.collectionView?.reloadData()
        self.collectionView?.layoutIfNeeded()
        
        //self.collectionView.tintColor = UIColor.black
        socket.on("comment") {[weak self] data ,ack in
            let comment = JSQMessage(coder: data[0] as! NSCoder)
            self?.comments.append(comment!)
            //self.tableView.reloadData()
        }
        self.tapGesture()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        self.view.backgroundColor = .clear
        
    }
   
    func setupBackButton() {
        let backButton = UIBarButtonItem(title: "Back", style: UIBarButtonItemStyle.plain, target: self, action: #selector(backButtonTapped))
        navigationItem.leftBarButtonItem = backButton
    }
    func backButtonTapped() {
        dismiss(animated: true, completion: nil)
    }
    
    func tapGesture(){
       let tapGesture = UITapGestureRecognizer(target: self, action: #selector(self.tapGestureTapped(recognizer:)))
        self.view.addGestureRecognizer(tapGesture)
    }
    func tapGestureTapped(recognizer: UITapGestureRecognizer) {
        self.view.endEditing(true)
    }
    
    func receiveMessagePressed(_ sender: UIBarButtonItem) {
        /**
         *  DEMO ONLY
         *
         *  The following is simply to simulate received messages for the demo.
         *  Do not actually do this.
         */
        
        /**
         *  Show the typing indicator to be shown
         */
        self.showTypingIndicator = !self.showTypingIndicator
        
        /**
         *  Scroll to actually view the indicator
         */
        self.scrollToBottom(animated: true)
        
        /**
         *  Copy last sent message, this will be the new "received" message
         */
        var copyMessage = self.messages.last?.copy()
        
        if (copyMessage == nil) {
            copyMessage = JSQMessage(senderId: AvatarIdJobs, displayName: getName(User.Jobs), text: "First received!")
        }
            
        var newMessage:JSQMessage!
        var newMediaData:JSQMessageMediaData!
        var newMediaAttachmentCopy:AnyObject?
        
        if (copyMessage! as AnyObject).isMediaMessage() {
            /**
             *  Last message was a media message
             */
            let copyMediaData = (copyMessage! as AnyObject).media
            
            switch copyMediaData {
            case is JSQPhotoMediaItem:
                let photoItemCopy = (copyMediaData as! JSQPhotoMediaItem).copy() as! JSQPhotoMediaItem
                photoItemCopy.appliesMediaViewMaskAsOutgoing = false
                
                newMediaAttachmentCopy = UIImage(cgImage: photoItemCopy.image!.cgImage!)
                
                /**
                 *  Set image to nil to simulate "downloading" the image
                 *  and show the placeholder view5017
                 */
                photoItemCopy.image = nil;
                
                newMediaData = photoItemCopy
            case is JSQLocationMediaItem:
                let locationItemCopy = (copyMediaData as! JSQLocationMediaItem).copy() as! JSQLocationMediaItem
                locationItemCopy.appliesMediaViewMaskAsOutgoing = false
                newMediaAttachmentCopy = locationItemCopy.location!.copy() as AnyObject?
                
                /**
                 *  Set location to nil to simulate "downloading" the location data
                 */
                locationItemCopy.location = nil;
                
                newMediaData = locationItemCopy;
            case is JSQVideoMediaItem:
                let videoItemCopy = (copyMediaData as! JSQVideoMediaItem).copy() as! JSQVideoMediaItem
                videoItemCopy.appliesMediaViewMaskAsOutgoing = false
                newMediaAttachmentCopy = (videoItemCopy.fileURL! as NSURL).copy() as AnyObject?
                
                /**
                 *  Reset video item to simulate "downloading" the video
                 */
                videoItemCopy.fileURL = nil;
                videoItemCopy.isReadyToPlay = false;
                
                newMediaData = videoItemCopy;
            case is JSQAudioMediaItem:
                let audioItemCopy = (copyMediaData as! JSQAudioMediaItem).copy() as! JSQAudioMediaItem
                audioItemCopy.appliesMediaViewMaskAsOutgoing = false
                newMediaAttachmentCopy = (audioItemCopy.audioData! as NSData).copy() as AnyObject?
                
                /**
                 *  Reset audio item to simulate "downloading" the audio
                 */
                audioItemCopy.audioData = nil;
                
                newMediaData = audioItemCopy;
            default:
                assertionFailure("Error: This Media type was not recognised")
            }
            
            newMessage = JSQMessage(senderId: AvatarIdJobs, displayName: getName(User.Jobs), media: newMediaData)
        }
        else {
            /**
             *  Last message was a text message
             */
            
            newMessage = JSQMessage(senderId: AvatarIdJobs, displayName: getName(User.Jobs), text: (copyMessage! as AnyObject).text)
        }
        
        /**
         *  Upon receiving a message, you should:
         *
         *  1. Play sound (optional)
         *  2. Add new JSQMessageData object to your data source
         *  3. Call `finishReceivingMessage`
         */
        
        self.messages.append(newMessage)
        self.finishReceivingMessage(animated: true)
        
        if newMessage.isMediaMessage {
            /**
             *  Simulate "downloading" media
             */
            DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + Double(Int64(1 * Double(NSEC_PER_SEC))) / Double(NSEC_PER_SEC)) {
                /**
                 *  Media is "finished downloading", re-display visible cells
                 *
                 *  If media cell is not visible, the next time it is dequeued the view controller will display its new attachment data
                 *
                 *  Reload the specific item, or simply call `reloadData`
                 */
                
                switch newMediaData {
                case is JSQPhotoMediaItem:
                    (newMediaData as! JSQPhotoMediaItem).image = newMediaAttachmentCopy as? UIImage
                    self.collectionView!.reloadData()
                case is JSQLocationMediaItem:
                    (newMediaData as! JSQLocationMediaItem).setLocation(newMediaAttachmentCopy as? CLLocation, withCompletionHandler: {
                        self.collectionView!.reloadData()
                    })
                case is JSQVideoMediaItem:
                    (newMediaData as! JSQVideoMediaItem).fileURL = newMediaAttachmentCopy as? URL
                    (newMediaData as! JSQVideoMediaItem).isReadyToPlay = true
                    self.collectionView!.reloadData()
                case is JSQAudioMediaItem:
                    (newMediaData as! JSQAudioMediaItem).audioData = newMediaAttachmentCopy as? Data
                    self.collectionView!.reloadData()
                default:
                    assertionFailure("Error: This Media type was not recognised")
                }
            }
        }
    }
    
    // MARK: JSQMessagesViewController method overrides
    override func didPressSend(_ button: UIButton, withMessageText text: String, senderId: String, senderDisplayName: String, date: Date) {
        /**
         *  Sending a message. Your implementation of this method should do *at least* the following:
         *
         *  1. Play sound (optional)
         *  2. Add new id<JSQMessageData> object to your data source
         *  3. Call `finishSendingMessage`
         */
        
        let message = JSQMessage(senderId: senderId, senderDisplayName: senderDisplayName, date: date, text: text)
        self.messages.append(message!)
        self.finishSendingMessage(animated: true)
       // self.inputToolbar.isHidden = true
       // self.inputToolbar.contentView.textView.resignFirstResponder()
        if text != "" {
            socket.emit("comment", [
                "roomKey": room.key,
                "text": text
                ])
        }
    }
    
    override func didPressAccessoryButton(_ sender: UIButton) {
        self.inputToolbar.contentView!.textView!.resignFirstResponder()
        
        let sheet = UIAlertController(title: "Media messages", message: nil, preferredStyle: .actionSheet)
        
        let photoAction = UIAlertAction(title: "Send photo", style: .default) { (action) in
            /**
             *  Create fake photo
             */
            let photoItem = JSQPhotoMediaItem(image: UIImage(named: "goldengate"))
            self.addMedia(photoItem!)
        }
        
        let locationAction = UIAlertAction(title: "Send location", style: .default) { (action) in
            /**
             *  Add fake location
             */
            let locationItem = self.buildLocationItem()
            
            self.addMedia(locationItem)
        }
        
        let videoAction = UIAlertAction(title: "Send video", style: .default) { (action) in
            /**
             *  Add fake video
             */
            let videoItem = self.buildVideoItem()
            
            self.addMedia(videoItem)
        }
        
        let audioAction = UIAlertAction(title: "Send audio", style: .default) { (action) in
            /**
             *  Add fake audio
             */
           // let audioItem = self.buildAudioItem()
            
           // self.addMedia(audioItem)
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
        
        sheet.addAction(photoAction)
        sheet.addAction(locationAction)
        sheet.addAction(videoAction)
        sheet.addAction(audioAction)
        sheet.addAction(cancelAction)
        
        self.present(sheet, animated: true, completion: nil)
    }
    
    func buildVideoItem() -> JSQVideoMediaItem {
        let videoURL = URL(fileURLWithPath: "file://")
        
        let videoItem = JSQVideoMediaItem(fileURL: videoURL, isReadyToPlay: true)
        
        return videoItem!
    }
    
    func buildAudioItem() -> JSQAudioMediaItem {
        let sample = Bundle.main.path(forResource: "audioMsg", ofType: "m4a")
        let audioData = try? Data(contentsOf: URL(fileURLWithPath: sample!))
        
        let audioItem = JSQAudioMediaItem(data: audioData)
        
        return audioItem
    }
    
    func buildLocationItem() -> JSQLocationMediaItem {
        let ferryBuildingInSF = CLLocation(latitude: 37.795313, longitude: -122.393757)
        
        let locationItem = JSQLocationMediaItem()
        locationItem.setLocation(ferryBuildingInSF) {
            self.collectionView!.reloadData()
        }
        
        return locationItem
    }
    
    func addMedia(_ media:JSQMediaItem) {
        let message = JSQMessage(senderId: self.senderId(), displayName: self.senderDisplayName(), media: media)
        self.messages.append(message!)
        
        //Optional: play sent sound
        
        self.finishSendingMessage(animated: true)
    }
    
    
    //MARK: JSQMessages CollectionView DataSource
    
    fileprivate func senderId() -> String {
        return User.Wozniak.rawValue
    }
    
   fileprivate func senderDisplayName() -> String {
        return getName(.Wozniak)
    }
    
    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return messages.count
    }
    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell:JSQMessagesCollectionViewCell = (super.collectionView(collectionView, cellForItemAt: indexPath) as? JSQMessagesCollectionViewCell)!
        //cell.textView?.textColor = UIColor.black
        cell.backgroundColor = UIColor.clear
        //cell.contentView.backgroundColor = .red
        return cell
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, messageDataForItemAt indexPath: IndexPath) -> JSQMessageData {
        
        return messages[indexPath.item]
    }
    
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, messageBubbleImageDataForItemAt indexPath: IndexPath) -> JSQMessageBubbleImageDataSource {
        return messages[indexPath.item].senderId == self.senderId() ? outgoingBubble : incomingBubble
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, avatarImageDataForItemAt indexPath: IndexPath) -> JSQMessageAvatarImageDataSource? {
        let message = messages[indexPath.item]
        return getAvatar(message.senderId)
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, attributedTextForCellTopLabelAt indexPath: IndexPath) -> NSAttributedString? {
        
        if (indexPath.item % 3 == 0) {
            let message = self.messages[indexPath.item]
            
            return JSQMessagesTimestampFormatter.shared().attributedTimestamp(for: message.date)
        }
        
        return nil
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, attributedTextForMessageBubbleTopLabelAt indexPath: IndexPath) -> NSAttributedString? {
        let message = messages[indexPath.item]
        if message.senderId == self.senderId {
            return nil
        }
        return NSAttributedString(string: message.senderDisplayName)
    }
    
    override func collectionView(_ collectionView: JSQMessagesCollectionView, layout collectionViewLayout: JSQMessagesCollectionViewFlowLayout, heightForCellTopLabelAt indexPath: IndexPath) -> CGFloat {
       
        if indexPath.item % 3 == 0 {
            return kJSQMessagesCollectionViewCellLabelHeightDefault
        }
        return 0.0
    }

    override func collectionView(_ collectionView: JSQMessagesCollectionView, layout collectionViewLayout: JSQMessagesCollectionViewFlowLayout, heightForMessageBubbleTopLabelAt indexPath: IndexPath) -> CGFloat {
        
        let currentMessage = self.messages[indexPath.item]
        if currentMessage.senderId == self.senderId {
            return 0.0
        }
        if indexPath.item - 1 > 0 {
            let previousMessage = self.messages[indexPath.item - 1]
            if previousMessage.senderId == currentMessage.senderId {
                return 0.0
            }
        }
        return kJSQMessagesCollectionViewCellLabelHeightDefault;
    }
    
}
