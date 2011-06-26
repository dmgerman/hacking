@displays files on screen, inputs many files
@rem - replace gs386 with the name of your executable for ghostscript
gs386 -q az_ini.ps -- az_proj.ps nmea.bat grid.bat n_amer.wdb bea_w3ep.dat annot.dat> error.out
