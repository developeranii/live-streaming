//
//  StreamPlayerVC.swift
//  LiveStreaming
//
//  Created by Anil Choudhary on 19/06/23.
//

import UIKit
import BambuserPlayer
import AVFAudio

class ViewController: UIViewController, BambuserPlayerDelegate {
    var bambuserPlayer: BambuserPlayer
    var playButton: UIButton
    var pauseButton: UIButton
    var rewindButton: UIButton

    required init?(coder aDecoder: NSCoder) {
        bambuserPlayer = BambuserPlayer()
        playButton = UIButton(type: UIButton.ButtonType.system)
        pauseButton = UIButton(type: UIButton.ButtonType.system)
        rewindButton = UIButton(type: UIButton.ButtonType.system)
        super.init(coder: aDecoder)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        do {
            try AVAudioSession.sharedInstance().setCategory(.playback)
            try    AVAudioSession.sharedInstance().setActive(true)
        } catch {}

        bambuserPlayer.delegate = self
        bambuserPlayer.applicationId = "GFZalqkR5iyZcIgaolQmA"
        bambuserPlayer.playVideo("https://cdn.bambuser.net/broadcasts/ec968ec1-2fd9-f8f3-4f0a-d8e19dccd739?da_signature_method=HMAC-SHA256&da_id=432cebc3-4fde-5cbb-e82f-88b013140ebe&da_timestamp=1456740399&da_static=1&da_ttl=0&da_signature=8e0f9b98397c53e58f9d06d362e1de3cb6b69494e5d0e441307dfc9f854a2479")
        self.view.addSubview(bambuserPlayer)
        playButton.setTitle("Play", for: UIControl.State.normal)
        playButton.addTarget(bambuserPlayer, action: #selector(BambuserPlayer.playVideo as (BambuserPlayer) -> () -> Void), for: UIControl.Event.touchUpInside)
        self.view.addSubview(playButton)
        pauseButton.setTitle("Pause", for: UIControl.State.normal)
        pauseButton.addTarget(bambuserPlayer, action: #selector(BambuserPlayer.pauseVideo as (BambuserPlayer) -> () -> Void), for: UIControl.Event.touchUpInside)
        self.view.addSubview(pauseButton)
        rewindButton.setTitle("Rewind", for: UIControl.State.normal)
        rewindButton.addTarget(self, action: #selector(ViewController.rewind), for: UIControl.Event.touchUpInside)
        self.view.addSubview(rewindButton)
    }

    @objc func rewind() {
        bambuserPlayer.seek(to: 0.0);
    }

    override func viewWillLayoutSubviews() {
        let statusBarOffset = self.topLayoutGuide.length
        bambuserPlayer.frame = CGRect(x: 0, y: 0 + statusBarOffset, width: self.view.bounds.size.width, height: self.view.bounds.size.height - statusBarOffset)
        playButton.frame = CGRect(x: 20, y: 20 + statusBarOffset, width: 100, height: 40)
        pauseButton.frame = CGRect(x: 20, y: 80 + statusBarOffset, width: 100, height: 40)
        rewindButton.frame = CGRect(x: 20, y: 140 + statusBarOffset, width: 100, height: 40)
    }

    func playbackStatusChanged(_ status: BambuserPlayerState) {
        switch status {
        case kBambuserPlayerStatePlaying:
            playButton.isEnabled = false
            pauseButton.isEnabled = true
            break

        case kBambuserPlayerStatePaused:
            playButton.isEnabled = true
            pauseButton.isEnabled = false
            break

        case kBambuserPlayerStateStopped:
            playButton.isEnabled = true
            pauseButton.isEnabled = false
            break

        case kBambuserPlayerStateError:
            NSLog("Failed to load video for %@", bambuserPlayer.resourceUri);
            break

        default:
            break
        }
    }
}
