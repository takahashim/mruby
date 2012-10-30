1000000.times do |i|
  ##100000.times{|x|  }
  LED.led(i%2)
  syslog(4,i.to_s)
  GC.start
  Sleep.sleep(1000)
end



