from HAL.Digital import DIGITAL_CHIP

class Flipper:
  def __new__ (self):
    self.extend = DIGITAL_CHIP.export(5)
    self.retract = DIGITAL_CHIP.export(6)

    self.extend.setOutput()
    self.extend.setLow()
    self.retact.setOutput()
    self.retact.setLow()