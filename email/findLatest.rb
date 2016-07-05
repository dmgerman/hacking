#!/usr/bin/ruby

counter = 1
file = File.new("readfile.rb", "r")
while (line = file.gets)
  puts "#{counter}: #{line}"
  counter = counter + 1
end
file.close

