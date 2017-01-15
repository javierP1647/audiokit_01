//
//  ViewController.swift
//  audiokit_01
//
//  Created by Devon Deonarine on 2016-12-14.
//  Copyright © 2016 Devon Deonarine. All rights reserved.
//

//import Cocoa
import AudioKit
import AVFoundation
import QuartzCore


class ViewController: NSViewController {

    @IBOutlet var audioInputPlot: EZAudioPlot!
    @IBOutlet weak var visualizer: NSTextField!
    @IBOutlet var imgView: NSImageView!
    @IBOutlet var playButton: NSButton!
    @IBOutlet var playbackSlider: NSSlider!
    @IBOutlet var ffButton: NSButton!
    @IBOutlet var rwButton: NSButton!
    @IBOutlet var playerBgLabel: NSTextField!
    @IBOutlet var timeKeeper: NSTextField!
    @IBOutlet var maxTime: NSTextField!
    @IBOutlet var titleLabel: NSTextField!
    
    var lowTracker: AKAmplitudeTracker!
    var midTracker: AKAmplitudeTracker!
    var highTracker: AKAmplitudeTracker!
    var allTracker: AKAmplitudeTracker!


    var audioFile : AKAudioFile!
    var audioPlayer :AKAudioPlayer!
    var lowFilter : AKLowPassFilter!
    var midFilter1 : AKHighPassFilter!
    var midFilter2 : AKLowPassFilter!
    var highFilter : AKHighPassFilter!
    var mixer : AKMixer!
    
    var theta: CGFloat = 0.0;
    var rotate: Bool = false
    let centerImage : NSImage = NSImage(named:"circle.png")!
    
    var imgWidth: CGFloat!
    var imgHeight: CGFloat!
    
    var musicQueue: [String]!
    var pos : Double!
    var lastCurrentTime : Double! = 0.0
    
    //toggles between play and pause image when neccesary
    @IBAction func playPausePress(_ sender: NSButton) {
        if(audioPlayer.isPlaying)
        {
            lastCurrentTime = audioPlayer.playhead
            audioPlayer.stop()
            playButton.image = NSImage(named:"play.png")

        }
        else{
            audioPlayer.play(from: lastCurrentTime)
            playButton.image = NSImage(named:"pause.png")
        }
    }
    
    //handles if user clicks playblack slider and moves it. still a bit buggy.
    @IBAction func playbackSliderMovement(_ sender: NSSlider)
    {
        let event: NSEvent! = NSApplication.shared().currentEvent!
        switch event.type {
            case NSEventType.leftMouseDown:
                if audioPlayer.isPlaying
                {
                    audioPlayer.stop()
                    playButton.image = NSImage(named:"play.png")
                }
                pos = (audioPlayer.audioFile.duration * (sender.doubleValue/100))
                lastCurrentTime = pos
                break
            case NSEventType.leftMouseUp:
                if (playButton.image?.name())! == "play"
                {
                    playButton.image = NSImage(named:"pause.png")
                }
                audioPlayer.play(from: lastCurrentTime)
                break
            case NSEventType.leftMouseDragged:
                if audioPlayer.isPlaying
                {
                    audioPlayer.stop()
                    playButton.image = NSImage(named:"play.png")
                }
                pos = (audioPlayer.audioFile.duration * (sender.doubleValue/100))
                lastCurrentTime = pos
                break
            default:
                print(event.type)
                break
        }
    }
    
    //shitty file opener that doesnt work yet
    @IBAction func browseFile(sender: AnyObject)
    {
        
        let dialog = NSOpenPanel();
        
        dialog.title                   = "Choose a file";
        dialog.showsResizeIndicator    = true;
        dialog.showsHiddenFiles        = false;
        dialog.canChooseDirectories    = true;
        dialog.canCreateDirectories    = true;
        dialog.allowsMultipleSelection = false;
        dialog.allowedFileTypes        = ["mp3","wav","m4a"];
        
        if (dialog.runModal() == NSModalResponseOK) {
            let result = dialog.url // Pathname of the file
            
            if (result != nil) {
                let path = result!.path
                print(path)
            }
        }
        else
        {
            // User clicked on "Cancel"
            return
        }
    }
    
    //turns string into proper MM:SS string when appropriate
    func secondsToMinutesSeconds (seconds: Double) -> String{
        let sec : Int = Int(seconds) % 60
        if sec < 10{
            return String((Int(seconds) % 3600) / 60) + ":0" + String(sec)
        }else{
            return String((Int(seconds) % 3600) / 60) + ":" + String(sec)
        }
    }
    
    
    func setupPlot() {
        let plot = AKNodeOutputPlot(audioPlayer, frame: audioInputPlot.bounds)
        plot.plotType = .rolling
        plot.shouldFill = true
        plot.shouldMirror = true
        plot.color = NSColor.white
        plot.backgroundColor = NSColor(red:0.13, green:0.13, blue:0.13, alpha:1.00)
        plot.autoresizingMask = .viewWidthSizable
        audioInputPlot.addSubview(plot)
    }
    
    //tweaked filters to seperate audio into low, mid, and high bands.
    func setupTracker(){
        lowFilter = AKLowPassFilter(audioPlayer)
        lowFilter.cutoffFrequency = 350
        lowFilter.resonance = 0
        lowTracker = AKAmplitudeTracker.init(lowFilter)
        
        
        midFilter1 = AKHighPassFilter(audioPlayer)
        midFilter1.cutoffFrequency = 350
        midFilter1.resonance = 0
        midFilter2 = AKLowPassFilter(midFilter1)
        midFilter2.cutoffFrequency = 1500
        midFilter2.resonance = 0
        midTracker = AKAmplitudeTracker.init(midFilter2)
        
        
        highFilter = AKHighPassFilter(audioPlayer)
        highFilter.cutoffFrequency = 1500
        highFilter.resonance = 0
        highTracker = AKAmplitudeTracker.init(highFilter)
        
        
        audioPlayer.looping = false
        mixer = AKMixer(lowTracker,midTracker,highTracker)
        AudioKit.output = mixer
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        AKAudioFile.cleanTempDirectory()
        audioFile = try? AKAudioFile(readFileName: "year5.mp3")
        audioPlayer = try? AKAudioPlayer(file: audioFile!)
        {
            print("Should only do once")
        }
        setupTracker()
    }
    
    func refresh(){
        maxTime.stringValue = String(describing: secondsToMinutesSeconds(seconds: audioPlayer.endTime))
        titleLabel.stringValue = audioFile.fileName
    }
    
    override func viewDidAppear() {
        super.viewDidAppear()
        
        refresh()
        
        playButton.focusRingType = .none
        rwButton.focusRingType = .none
        ffButton.focusRingType = .none

        self.view.window?.makeFirstResponder(playButton)
        
        imgView.imageAlignment = .alignCenter
        
        imgView.image = centerImage
        imgWidth = imgView.image!.size.width
        imgHeight = imgView.image!.size.height
        
        AudioKit.start()
        setupPlot()

        DispatchQueue.main.async {
            Timer.scheduledTimer(timeInterval: 1/240, target: self, selector: #selector(ViewController.updateVisualizer), userInfo: nil, repeats: true)
        }
        DispatchQueue.main.async {
            Timer.scheduledTimer(timeInterval: 1/240, target: self, selector: #selector(ViewController.updateImg), userInfo: nil, repeats: true)
        }
        DispatchQueue.main.async {
            Timer.scheduledTimer(timeInterval: 1/60, target: self, selector: #selector(ViewController.updatePlayback), userInfo: nil, repeats: true)
        }        
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }
    
    //updates playback time
    func updatePlayback() {
        if(audioPlayer.isPlaying){
            timeKeeper.stringValue = String(describing: secondsToMinutesSeconds(seconds: audioPlayer.playhead))
            playbackSlider.doubleValue = (audioPlayer.playhead/audioPlayer.audioFile.duration) * 100.0
        }

    }
    
    //rotates image if enabled
    func updateImg(){
        let x = CGFloat((midTracker.amplitude + lowTracker.amplitude)/3)
        if rotate
        {
            imgView.image = centerImage.imageRotatedByDegreess(degrees: theta);
            imgView.image?.size.width = imgWidth + imgWidth * x
            imgView.image?.size.height = imgHeight + imgHeight * x
            theta += 1
        }
        else
        {
            imgView.image?.size.width = imgWidth + (imgView.image?.size.width)! * x
            imgView.image?.size.height = imgHeight + (imgView.image?.size.height)! * x
        }
    }
    
    func updateVisualizer(){
        //this can be used to rotate main image if its not a circle
        if lowTracker.amplitude > 0.8 && !rotate {
//            rotate = true
        }
        if(lowTracker.amplitude > 0.7 || midTracker.amplitude > 0.55){
            visualizer.backgroundColor = NSColor(red: 0.0, green: 0.66, blue: 0.76, alpha: 1.0)
//            visualizer.backgroundColor = NSColor(red:0.10, green:0.56, blue:0.98, alpha:1.00)
                //NSColor(red:0.60, green:0.36, blue:0.71, alpha:1.00)
        }
        else
        {
            visualizer.backgroundColor = NSColor(red: CGFloat(highTracker.amplitude * 1.6), green: CGFloat(midTracker.amplitude * 0.7 + lowTracker.amplitude * 0.4) , blue: CGFloat(lowTracker.amplitude * 0.7), alpha: 1.0)
//            visualizer.backgroundColor = NSColor(red: CGFloat(lowTracker.amplitude), green: CGFloat(highTracker.amplitude * 1.7) , blue: CGFloat(midTracker.amplitude * 1.5), alpha: 1.0)
        }


    }


}

