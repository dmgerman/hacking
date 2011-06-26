@rem shows use of nmea.dat and 10GHconf.ps file
@rem gs v3.33 bombs sometimes if outputting all grid square 
@rem labels and borders, to the screen. However is OK when printing.
@rem gs v2.61 is OK to screen.
@rem if not using a GPS receiver, you can leave out the nmea.dat file
gs386 -q az_ini.ps 10ghconf.ps -- az_proj.ps nmea.dat n_amer.wdb rover.dat mountain.dat
