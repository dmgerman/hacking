#!/usr/bin/ruby

require 'date'

def extractFields(file)
  #  STDERR.puts file
  f = File.foreach(file).map{ |l| l.chomp.encode('UTF-8', :invalid => :replace)}
  index = f.each_index.select{ |i| f[i] == ''}[0]
  if (index == nil)
    return
  end
  f = f[0..index-1]
  a = f.grep(/^(Date|Message-ID):/i).map{ |line| {line[0..line.index(':')-1].downcase => line[line.index(':')+1..-1].chomp } }
  b = a.reduce({}, :merge)
  if (b["date"] == nil)
    STDERR.puts "did not contain a date: #{file}"
    return
  end
#print DateTime.parse(b["date"]).strftime("%+"), ":", b["message-id"],  ":", file, "\n"
  if file.index(':')
    status = file[file.index(':')+1..-1]
  else
    status = ''
  end
  #print b["date"].strip, ";", b["message-id"].strip,  ";", file, ";",  status, "\n"
  print DateTime.parse(b["date"].strip).strftime("%d %b %Y %H:%M:%S %z"), ";#{b["message-id"].strip};#{file};#{status}\n"

rescue Exception => e  
  STDERR.print file, " ", e.message, "\n"
end


STDIN.read.split("\n").each do |file|
  extractFields file
end

