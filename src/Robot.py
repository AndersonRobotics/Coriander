from Systems.Chassis import Chassis
from Systems.Flipper import Flipper

class Robot:
  def __new__ (self):
    self.chassis = Chassis()
    self.flipper = Flipper()