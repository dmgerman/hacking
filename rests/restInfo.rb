#!/usr/bin/ruby
# -*- coding: utf-8 -*-


require 'rubygems'
require 'nokogiri'         
require 'open-uri'
      

rest = restaurant_info("http://www.healthspace.ca/Clients/VIHA/VIHA_Website.nsf/Food-FacilityHistory?OpenView&RestrictToCategory=F3F0C92DC7FCC71E88257CEB006DF9C3&count=5")

puts rest



