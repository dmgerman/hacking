#!/usr/bin/ruby
# -*- coding: utf-8 -*-


require 'rubygems'
require 'nokogiri'         
require 'open-uri'
require 'sqlite3'

BASE_URL = "http://www.healthspace.ca/Clients/VIHA/VIHA_Website.nsf/Food-FacilityHistory?OpenView&RestrictToCategory="
SUFFIX = "&count=120"


def restaurant_info(db, rest)

  def Parse_Date(st)

    months = {
      "" => 99,
      "Jan" => 1,
      "Feb" => 2,
      "Mar" => 3,
      "Apr" => 4,
      "May" => 5,
      "Jun" => 6,
      "Jul" => 7,
      "Aug" => 8,
      "Sep" => 9,
      "Oct" => 10,
      "Nov" => 11,
      "Dec" => 12
    }

    st = st.gsub(/ /,' ')
    st = st.sub(/^ +/,'')
    st = st.sub(/ +$/,'')

    parts =  st.split('-')

    "%04d-%02d-%02d" % [parts[2].to_i,months[parts[1]],parts[0]]
    
  end

  def parse_row(r)
    i = 0;
    field = 'unknown'
    value = 'unknown'
    r.css('td').each do | td | 
      if (i == 0) 
        field = td.text.to_s
        field = field.sub(/:  /, "")
      else
        value = td.text
      end
      i = i+1
    end
    return [field,value]
  end

  restaurant_exists = lambda do
    findStm = db.prepare "select count(*) from rests where name = ? and rhash = ? and address = ? and code = ?;"

    rs = findStm.execute ([rest['name'],rest['url'],rest['location'],rest['Facility Number']])
    row = rs.next
    puts row[0]> 0?"#{rest} exists" :"#{rest} does notexists" 
    row[0] > 0
  end


  def parse_row_visits(r)
    i = 0;
    field = 'unknown'
    value = 'unknown'
    hashVisit = 'unknown'
    r.css('td').each do | td | 
      if (i == 0) 
        field = td.text
        hashVisit = td.css('a')[0]['href'].sub(/\/Clients\/VIHA\/VIHA_Website.nsf\/0\//i,"").sub("\?OpenDocument","")
      else
        value = td.text
        value = value.sub(/^ +/,"")
#        puts "[#{value}]"
      end
      i = i + 1
    end
    return [field,value, hashVisit]
  end

  url = rest['url']
  
  puts "Starting"
  
  db.execute('BEGIN TRANSACTION;')
  
  fullURL = "#{BASE_URL}#{url}#{SUFFIX}"
  page = Nokogiri::HTML(open(fullURL))
  if page == nil
    throw "we can't download [#{url}]"
  end
  
  rows = page.at_css('body/table').css('tr')
  rows.each do |r|
    field, value = parse_row(r)
    puts "Field #{field} Value #{value}"
    rest[field] = value
  end
  
  puts "Processing: #{rest}"  
  
  if (restaurant_exists.call)
    print "To update ", rest['name']
    updateStm = db.prepare "UPDATE rests set rtype = ?, whenopen = ?, rwhenupdated = date() where name = ? and rhash = ? and address = ? and code = ?";
    updateStm.execute rest['Facility Type'], rest['Months Open'], rest['name'], url, rest['location'], rest['Facility Number']
  else
    puts "To insert restaurant ", rest
    insertStm = db.prepare "INSERT INTO rests(name, rhash, address, code, rtype, whenopen, rwhenupdated, rwhenadded) values (?,?,?,?,?,?, date(),date());"
    insertStm.execute rest['name'], url, rest['location'], rest['Facility Number'], rest['Facility Type'], rest['Months Open']
  end
  
  visits = Array.new
  if (defined? page.search('table').css('table')[1].css)
    insertStm2 = db.prepare "INSERT OR REPLACE INTO visits(code, vhash, vtype, vwhen, vwhenupdated) values (?,?,?,?, date());"
    
    rows = page.search('table').css('table')[1].css('tr')
    # ignore first table
    rows.shift
    
    rows.each do |r|
        field, value, hashVisit = parse_row_visits(r)
        puts url
        visitDate = Parse_Date(value)
        visits.push(field, visitDate, hashVisit)
        #    puts value
        #    puts visitDate
        insertStm2.execute rest['Facility Number'], hashVisit, field, visitDate
    end
  end
  
  rest['visits'] = visits
    
  db.execute('COMMIT')

  rest
end

      
def parseRest(r)
  ret = Hash.new
  r.css('a').each do | link | 
    url = link.attributes['href']
    match = /RestrictToCategory=([^&]+)/.match(url)
    ret["name"] = link.text.to_s
    ret["url"] = match[1]
    break
  end

  td1, td2, td3 = r.xpath('td')

  ret["location"] = td3.text.sub(/ /, "")

  return ret

end
#  match = /RestrictToCategory=([^&]+)/.match(link)


begin
  db = SQLite3::Database.new "rests.db"

  page = Nokogiri::HTML(open("/tmp/rip2.html"))   
  rows = page.css('tr')

  
  rows.each do |r|
    restInfo = parseRest(r)
    
    next if (restInfo["name"].eql?("") or restInfo["name"] == nil)
    
    restInfo2 = restaurant_info(db, restInfo)

    puts restInfo2['visits']
    
    restInfo = restInfo.merge(restInfo2);
    
    puts "#{restInfo['name']};#{restInfo['url']};#{restInfo['location']};#{restInfo['Facility Number']};#{restInfo['Facility Type']};#{restInfo['Months Open']};#{restInfo['FOODSAFE Excellence Certified']}"

  end

  db.close if db


end


