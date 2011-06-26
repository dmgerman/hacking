@rem displays files on screen
@rem use ghostscript in Postscript (stdin) mode
call makebig
type big.ps | gs386 -q -
