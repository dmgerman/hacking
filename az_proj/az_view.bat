@rem	example: call this program as
@rem	c:\> az_view n_amer.wdb eurasia.wdb beacon.dat
	gs  -sDEVICE=vga       -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9
@rem redirect the screen messages to a file to give a clean screen
@rem However at the end the prompt to exit will also go to the error.out file
@rem so when everything stops, remember to give a <cr> to exit.
@rem	gs  -sDEVICE=vga       -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
@rem	gs  -sDEVICE=ega       -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
@rem	gs  -sDEVICE=atiw      -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
@rem	gs  -sDEVICE=s3vga     -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
@rem	gs  -sDEVICE=tseng     -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
@rem	gs  -sDEVICE=tvga      -q az_ini.ps -- az_proj.ps %1 %2 %3 %4 %5 %6 %7 %8 %9 >error.out
