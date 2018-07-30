class DigitalLine:
  def __new__ (self, value, direction):
    self.value = value
    self.direction = direction
  
  def setInput (self):
    self.direction.write('in')
  
  def setOutput (self):
    self.direction.write('out')
  
  def setHigh (self):
    self.value.write(1)

  def setLow (self):
    self.value.write(0)


class DigitalChip:
  def __new__ (self):
    self.export = open('/sys/class/gpio/export', 'r+')
    self.remove = open('/sys/class/gpio/unexport', 'r+')
  
  def export (line):
    self.export.write(line)

    value_handle = open('/sys/class/gpio/gpio{}/value'.format(line), 'r+')
    direction_handle = open('/sys/class/gpio/gpio{}/direction'.format(line), 'r+')

    return DigitalLine(value_handle, direction_handle)

DIGITAL_CHIP = DigitalChip()