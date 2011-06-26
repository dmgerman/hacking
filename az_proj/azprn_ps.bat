@rem This sends files to a postscript printer on LPT1
@rem concatenates AZ_PROJ files for sending to a Postscript printer
@rem note controld.ps is at the end of big.ps
copy az_ini.ps+tv_conf.ps+az_proj.ps+n_amer.wdb+us_call.dat+tv_nach2.dat+controld.ps big.ps
copy big.ps LPT1:
