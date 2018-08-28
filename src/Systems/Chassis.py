from HAL.Analog import ANALOG_CHIP
from HAL.Digital import DIGITAL_CHIP

class Chassis:
  def __new__ (self):
    self.leftSpeed = ANALOG_CHIP.export(17)
    self.leftReverse = DIGITAL_CHIP.export(8)
    self.rightSpeed = ANALOG_CHIP.export(18)
    self.rightReverse = DIGITAL_CHIP.export(9)

    self.leftSpeed.setPeriod(1000000)
    self.rightSpeed.setPeriod(1000000)
    self.leftSpeed.setDuty(0)
    self.rightSpeed.setDuty(0)

    self.leftReverse.setOutput()
    self.rightReverse.setOutput()

    self.leftReverse.setHigh()
    self.rightReverse.setLow()