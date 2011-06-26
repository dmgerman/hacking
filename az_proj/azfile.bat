@rem produces printer file for HP550c color inkjet printer.
@rem For your printer, you'll need to change the DEVICE (here cdj550)
@rem and optionally the extension for the printer filename (here .cdj).
@rem you'll need v3.33 (or greater) of ghostscript for this (see readme.azp)
gs386 -q -sDEVICE=cdj550 -sOutputFile=n_amer.cdj az_ini.ps -- az_proj.ps grid.dat n_amer.wdb
