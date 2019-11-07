//
//  CountDownViewController.swift
//  PALIDIN
//
//  Created by Cameron Conway on 10/30/19.
//  Copyright © 2019 aware. All rights reserved.
//

import UIKit

class CountDownViewController: UIViewController {
  var rotate = true
  var countdownSeconds = 3
  @IBOutlet weak var secondLabel: UILabel!
  public typealias CountDownCompleteCallback = () -> Void
  var countDownCompleteCallback: CountDownCompleteCallback? = { }
  open func setCallback(callback: @escaping CountDownCompleteCallback) {
    countDownCompleteCallback = callback
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    if rotate == true {
      secondLabel.transform = CGAffineTransform(rotationAngle: 90 * (.pi/180))
    }
    Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { (timer) in
      if self.countdownSeconds == 0 {
        if self.rotate == true {
          ((self.presentingViewController as! UINavigationController).viewControllers[0] as! DocReaderMainViewController).view.isHidden = true
          self.dismiss(animated: false, completion: nil)
          ((self.presentingViewController as! UINavigationController).viewControllers[0] as! DocReaderMainViewController).captureImages()
        } else {
          self.view.isHidden = true
          self.dismiss(animated: false, completion: nil)
          self.countDownCompleteCallback!()
        }
        timer.invalidate()
      } else {
        self.countdownSeconds -= 1
        self.secondLabel.text = String(self.countdownSeconds)
      }
    }
  }
}
