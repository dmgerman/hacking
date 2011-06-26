@rem This sends to a file, that we then print (in binary)
@rem you need ghostscript v3.33 at least for this
@rem prints beacons for North America.
gs386 -q -sDEVICE=cdj550 -sOutputFile=bea_na.cdj az_ini.ps -- az_proj.ps n_amer.wdb bea_na.dat
copy /b bea_na.cdj LPT1:

