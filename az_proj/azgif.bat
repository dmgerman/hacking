@rem produces gif8 output.
@ rem you'll need v2.61 of ghostscript for this (see readme.azp).
@ rem change the name gs to that for your ghostscript executable
gs386 -q -sDEVICE=gif8 -sOutputFile=n_amer.gif az_ini.ps -- az_proj.ps n_amer.wdb
