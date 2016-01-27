#!/usr/bin/ruby
# -*- coding: utf-8 -*-


require 'rubygems'
require 'nokogiri'         
require 'open-uri'
require 'sqlite3'

begin
  db = SQLite3::Database.new "rests.db"
  puts db.get_first_value 'SELECT SQLITE_VERSION()'
  stm = db.prepare "INSERT INTO restaurants(name, hash, address, code, rtype, whenopen) values (?,?,?,?,?,?);"

  f = File.open(ARGV[0], "r")
  f.each_line { |line|
    (name, hash, address, code, rtype, whenOpen) =line.split(';')

    puts "#{whenOpen}"

    rtype = rtype.match(/\(([A-Za-z ]+)\)/)[1]

    puts "#{rtype}"

    stm.execute name, hash, address, code, rtype, whenOpen

    rescue SQLite3::Exception => e 
    
      puts "Exception occurred"
      puts e

  }
  stm.close if stm
  f.close

rescue SQLite3::Exception => e 
  
  puts "Exception occurred"
  puts e
  
ensure
  db.close if db


end
