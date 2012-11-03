10.times do |i|
  ##100000.times{|x|  }
  LED.led(i%2)
  Sleep.sleep(50)
end



