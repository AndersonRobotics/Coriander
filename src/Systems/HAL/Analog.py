class AnalogLine:
  def __new__ (self, period, duty):
    self.period = period
    self.duty = duty
  
  def setPeriod (self, period)
    self.period.write(period)

  def setDuty (self, duty)
    self.duty.write(duty)


class AnalogChip:
  def __new__ (self):
    self.export = open('/sys/class/pwm/pwmchip0/export', 'r+')
    self.remove = open('/sys/class/pwm/pwmchip0/unexport', 'r+')
  
  def export (line):
    self.export.write(line)

    period_handle = open('/sys/class/pwm/pwmchip0/pwm{}/period'.format(line), 'r+')
    duty_handle = open('/sys/class/pwm/pwmchip0/pwm{}/duty_cycle'.format(line), 'r+')

    return AnalogLine(period_handle, duty_handle)

ANALOG_CHIP = AnalogChip()