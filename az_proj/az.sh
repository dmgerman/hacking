#gs261 -sDEVICE=gif8 -sOutputFile=$1.gif az_ini.ps $1.ps -- az_proj.ps $1.dat n_amer.wdb
#gs az_ini.ps $1.ps -- az_proj.ps $1.dat n_amer.wdb
#gs261 -sDEVICE=gif8 -sOutputFile=junk.gif az_ini.ps ../maps/928598657.ps -- az_proj.ps eurasia.wdb oceania.wdb
#gs261 -sDEVICE=gif8 -sOutputFile=junk.gif az_ini.ps ../maps/928598657.ps -- az_proj.ps junk.wdb 
#gs510 az_ini.ps debug.ps -- az_proj.ps n_amer.wdb 
#gs510 -sDEVICE=cdj550 -sOutputFile=junk.cdj az_ini.ps debug.ps -- az_proj.ps n_amer.wdb 
#gs261 -sDEVICE=gif8 -sPAPERSIZE=a3 -sOutputFile=foo.gif az_ini.ps -- az_proj.ps n_amer.wdb 
#gs az_ini.ps debug.ps -- az_proj.ps qra6mden.dat n_amer.wdb
#gs az_ini_ss.ps -- az_proj_b8.ps n_amer.wdb ss_432.dat city_maj.dat
#gs261 -sDEVICE=gif8 -sOutputFile=144ss.gif az_ini_ss.ps -- az_proj_b8.ps n_amer.wdb ss_144.dat city_maj.dat
#gs261 -sDEVICE=gif8 -sOutputFile=432ss.gif az_ini_ss.ps -- az_proj_b8.ps n_amer.wdb ss_432.dat city_maj.dat
#gs261 -sDEVICE=gif8 -sOutputFile=50ss.gif az_ini_ss.ps -- az_proj_b8.ps n_amer.wdb ss_50.dat city_maj.dat
gs -sDEVICE=pdfwrite -sOutputFile=az.pdf  az_ini.ps -- az_proj.ps n_amer.wdb world.wdb city_maj.dat  #rover.dat
#gs510 -sDEVICE=png16m -sOutputFile=foo.png az_ini.ps 931448544.ps -- az_proj.ps world.wdb
#gs az_ini.ps japan5.ps -- az_proj_b10.ps etopo_legend.dat QM.dat QN.dat PM.dat PN.dat eurasia.wdb city_min.dat
#gs261 -sDEVICE=gif8 -sOutputFile=japan5.gif az_ini.ps japan5.ps -- az_proj_b10.ps japan5.dat eurasia.wdb city_min.dat 
#gs az_ini.ps austral5.ps -- az_proj_b10.ps austral5.dat oceania.wdb city_min.dat
#gs261 -sDEVICE=gif8 -sOutputFile=austral5.gif az_ini.ps austral5.ps -- az_proj_b10.ps austral5.dat oceania.wdb city_min.dat 
#gs az_ini.ps africa5.ps -- az_proj_b10.ps africa5.dat africa.wdb city_min.dat
#gs261 -sDEVICE=gif8 -sOutputFile=africa5.gif az_ini.ps africa5.ps -- az_proj_b10.ps africa5.dat africa.wdb city_min.dat 
#gs az_ini.ps n_amer5.ps -- az_proj_b10.ps n_amer5.dat n_amer.wdb city_maj.dat
#gs261 -sDEVICE=gif8 -sOutputFile=america5.gif az_ini.ps america5.ps -- az_proj_b10.ps america5.dat n_amer.wdb city_min.dat 
#gs az_ini.ps africa_test.ps -- az_proj.ps africa.wdb
#gs -sDEVICE=gif8 -sOutputFile=test.gif az_ini.ps -- az_proj.ps n_amer.wdb #city_min.dat 
