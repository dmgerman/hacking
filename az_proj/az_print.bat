@rem	Output goes to PRN.  use 'mode' to redirect PRN to COM1: etc if
@rem		needed. Add option -sOutputFile=file.nam to send to file.
@rem
@rem	Uncomment your printer....
@rem
@rem	example: call this program as:
@rem	az_print n_amer.wdb s_amer.wdb dxcc.dat beacon.dat
@rem	gs386 -sDEVICE=deskjet   -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
	gs386 -sDEVICE=djet500   -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=laserjet  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=ljetplus  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=ljet2p    -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=ljet3     -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=cdeskjet  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=cdjcolor  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=cdjmono   -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=cdj550    -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=paintjet  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=pjetxl    -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	this is for 24pin epson's highest res
@rem	gs386 -sDEVICE=epson -r360x180 -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	this is for 9pin epson's highest res
@rem	gs386 -sDEVICE=epson -r240x72 -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=eps9high  -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=ibmpro    -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=bj10e     -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=gifmono -sOutputFile=az.gif -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=gif8    -sOutputFile=az.gif -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=pcxmono -sOutoutFile=az.pcx -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=pcx16   -sOutputFile=az.pcx -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=pcx256  -sOutputFile=az.pcx -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem	gs386 -sDEVICE=bit     -sOutputFile=az.bit -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
