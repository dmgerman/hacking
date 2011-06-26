@rem File to install the AZ_PROJv1.04
@echo Does a crude and simple install of AZ_PROJ into a DOS machine
@echo You must run this file from the directory in which you
@echo will make all your AZ_PROJ maps (eg C:\az_proj)
@echo You must have in this directory the files
@echo azprjxxx.zip (where currently xxx is 104)
@echo gsxxxini.zip (where xxx is 333, fontmap locations are different for 401)
@echo gsxxxdos.zip
@echo gsxxxfn1.zip
@echo gsxxxfn2.zip
@echo -
@echo To convert CT files to AZ_PROJ format, if you don't have awk.
@echo (You can move mawk.exe to a directory in your path if you wish.)
@echo mawk122x.zip
@echo -
@echo you must also have pkunzip in your path
@echo -
@pause
@echo AZ_PROJ and Ghostscript will be installed in the current directory
@echo the Ghostscript fonts will be installed in the directory .\FONTS
@echo Ignore warnings from pkunzip
@echo At the end of the install, you can test Ghostscript by running
@echo the test files tiger.bat, and alphabet.bat
@echo If the install of Ghostscript passes these tests,
@echo then look at README.AZP and run the AZ_PROJ test files (azxxx.bat)
@echo eg azview.bat, azfile.bat
@echo -
@echo Press ^C to exit
@pause
mkdir .\fonts
copy gs333fn1.zip  .\fonts
copy gs333fn2.zip  .\fonts
pkunzip -n gs333dos.zip
pkunzip -n gs333ini.zip
pkunzip -n mawk122x.zip
pkunzip -n azprj*.zip
del *.cmd
del *.os2
cd .\fonts
pkunzip -n *.zip
del *.zip
cd ..
@echo -
@echo install is finished.
@echo To test Ghostscript's graphics, the file tiger.bat will be run
@echo you should get a nice head of a tiger.
@echo -
@echo Press ^C to exit
@pause
@call tiger.bat
@echo -
@echo To test Ghostscript's text, the file alphabet.bat will be run
@echo you should get the alphabet in several font sizes.
@echo The default fonts are not very pretty. You may already
@echo have better ones on your disk (look for .pfa files)
@echo -
@echo Press ^C to exit
@pause
@call alphabet.bat
@echo -
@echo If these tests pass, then look at README.AZP and run the
@echo test files from AZ_PROJ (eg azview.bat)
@echo -
@echo If the install fails, let me know and I'll try to fix it
@echo Joe Mack NA3T mack@ncifcrf.gov
