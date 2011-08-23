# This is redundant but it makes me feel better:
from paver.defaults import *

options(
    setup=Bunch(
        name=
))

@task
def make_constants_pxi():
    from make_constants_pxi import make_constants_pxi
    make_constants_pxi("wimpiggy/lowlevel/constants.txt",
                       "wimpiggy/lowlevel/constants.pxi")

@task
# Make sdist automatically create a fake setup.py, include a copy of paver,
# and run our code generator:
@needs(["generate_setup", "minilib",
        "make_constants_pxi",
        "setuptools.command.sdist"])
def sdist():
    call_task("minilib")
    #call_task("generate_setup")
    call_task("make_constants_pxi")
    call_task("setuptools.command.sdist")

# Tweaked from http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/502261
def pkgconfig(*packages, **kw):
    flag_map = {'-I': 'include_dirs',
                '-L': 'library_dirs',
                '-l': 'libraries'}
    cmd = "pkg-config --libs --cflags %s" % (" ".join(packages),)
    (status, output) = commands.getstatusoutput(cmd)
    if not (os.WIFEXITED(status) and os.WEXITSTATUS(status) == 0):
        raise Exception, ("call to pkg-config ('%s') failed" % (cmd,))
    for token in output.split():
        if flag_map.has_key(token[:2]):
            kw.setdefault(flag_map.get(token[:2]), []).append(token[2:])
        else: # throw others to extra_link_args
            kw.setdefault('extra_link_args', []).append(token)
        for k, v in kw.iteritems(): # remove duplicates
            kw[k] = list(set(v))
    return kw

