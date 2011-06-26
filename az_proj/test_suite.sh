#!/bin/sh
GS="/usr/local/bin/gs -q"
GS261="/usr/local/bin/gs261 -q"
XV="/usr/local/bin/xv"

COURIER="alphabet_courier.ps"
HELVETICA="alphabet_helvetica.ps"
TIGER="tiger.ps"

#echo "testing ghostscript setup"
#echo "testing font COURIER"
#$GS -- $COURIER 

#echo "testing font HELVETICA"
#$GS -- $HELVETICA

#echo "testing graphics: tiger"
#$GS -- $TIGER

#echo "testing AZ_PROJ"

#echo "testing with no input files"
#echo "continue with ^D (control D), will allow program to exit"
#echo "after the ^D, the lat/lon lines will be drawn"
#$GS az_ini.ps -- az_proj.ps 

#echo "map of NA, portrait projected from ARRL, countries, provinces, states"
#echo "rivers, lakes, compass rose, lat/lon lines"
#$GS az_ini.ps -- az_proj.ps n_amer.wdb 

#echo "map of NA drawn using config.ps file, landscape, projected from ARRL,"
#echo "distance circles, grid_squares, lakes fill off"
#echo "center offset to mid USA, US call areas, verbose output on console"
#$GS az_ini.ps config_test_1.ps -- az_proj.ps n_amer.wdb call_w.dat

FILE=config_test_2
#echo "gif file, oceania from Sydney, down-under portrait, no lat/lon or gridsquare lines"
#echo "countries, states, vk/zl call areas, city"
#$GS261 -sDEVICE=gif8 -sOutputFile=${FILE}.gif az_ini.ps ${FILE}.ps -- az_proj.ps oceania.wdb call_vk.dat call_zl.dat city_min.dat
#echo "loading gif with xv"
#echo "dismiss in window to exit xv"
#$XV ${FILE}.gif
#echo ""

#FILE=config_test_3
#echo "NA centered using gridsquare from FM05lw, all gridsquares"
#echo "city_maj"
#$GS az_ini.ps ${FILE}.ps -- az_proj.ps city_maj.dat


#FILE=config_test_4
#echo "New England from ARRL, all gridsquares, rover, mountain, all beacons"
#echo "letter and number grids"
#$GS az_ini.ps ${FILE}.ps -- az_proj.ps rover.dat mountain.dat bea_all.dat
#echo "6m­icd"
#$GS az_ini.ps  -- az_proj.ps 6m_icd.dat
#FILE=config_test_7
#echo "6m_usf"
#$GS az_ini.ps  ${FILE}.ps -- az_proj.ps 6m_usf.dat

#echo "qraden"
#$GS az_ini.ps -- az_proj.ps qra6mden.dat
#echo "qra 6m"
#$GS az_ini.ps -- az_proj.ps qra_6m.dat
#echo "grid"
#$GS az_ini.ps -- az_proj.ps gridw3ep.dat
#echo "grid worked "
#$GS az_ini.ps -- az_proj.ps jun95.dat
#FILE=config_test_6
#echo "qso"
#$GS az_ini.ps ${FILE}.ps -- az_proj.ps qso_test.dat
#echo "annot dxcc"
#$GS az_ini.ps -- az_proj.ps annot.dat dxcc.dat 
#FILE=config_test_8
#echo "qso_2mau"
#$GS az_ini.ps ${FILE}.ps -- az_proj.ps qso_2mau.dat

#echo "low res us call den"
#$GS az_ini.ps  -- az_proj.ps us_call4.den
#echo "high res us call den"
#$GS az_ini.ps  -- az_proj.ps us_call6.den
#echo "fall 99 144 density and qso"
#$GS az_ini.ps  -- az_proj.ps fs_144_99.dat fs_qso_144_99.dat

echo "tv"
$GS az_ini.ps  -- az_proj.ps tv_ve.dat

