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
  
  override func viewDidLoad() {
    super.viewDidLoad()
    if rotate == true {
      secondLabel.transform = CGAffineTransform(rotationAngle: 90 * (.pi/180))
    }
    Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { (timer) in
      if self.countdownSeconds == 0 {
        ((self.presentingViewController as! UINavigationController).viewControllers[0] as! DocReaderMainViewController).view.isHidden = true
        self.dismiss(animated: true, completion: nil)
        ((self.presentingViewController as! UINavigationController).viewControllers[0] as! DocReaderMainViewController).captureImages()
        timer.invalidate()
      } else {
        self.countdownSeconds -= 1
        print("label:", String(self.countdownSeconds))
        self.secondLabel.text = String(self.countdownSeconds)
      }
    }
  }
}
