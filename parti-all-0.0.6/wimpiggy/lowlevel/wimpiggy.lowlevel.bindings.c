/* 0.9.7.2 on Fri Jul  3 14:28:47 2009 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)	PyInt_AsLong(o)
#endif
#ifndef WIN32
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>
#include "X11/Xlib.h"
#include "X11/Xutil.h"
#include "gdk/gdk.h"
#include "gdk/gdkx.h"
#include "pygobject.h"
#include "pygtk/pygtk.h"
#include "X11/extensions/XTest.h"
#include "X11/extensions/Xcomposite.h"
#include "X11/extensions/Xfixes.h"
#include "X11/extensions/Xdamage.h"


typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static PyObject *__Pyx_CreateClass(PyObject *bases, PyObject *dict, PyObject *name, char *modname); /*proto*/

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/

static void __Pyx_WriteUnraisable(char *name); /*proto*/

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i); /*proto*/

static int __Pyx_SetItemInt(PyObject *o, Py_ssize_t i, PyObject *v); /*proto*/

static PyObject *__Pyx_UnpackItem(PyObject *); /*proto*/
static int __Pyx_EndUnpack(PyObject *); /*proto*/

static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from wimpiggy.lowlevel.bindings */

static PyObject *__pyx_k161;
static PyObject *__pyx_k164;
static GObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap(PyObject *,PyObject *); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_wrap(GObject *); /*proto*/
static void *__pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap_boxed(PyObject *,PyObject *); /*proto*/
static GdkDisplay *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_raw_display_for(PyObject *); /*proto*/
static Display *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(PyObject *); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_extension_support(PyObject *,PyObject *,PyObject *,PyObject *,Bool (*)(Display *,int *,int *),Status (*)(Display *,int *,int *)); /*proto*/
static GdkFilterReturn __pyx_f_8wimpiggy_8lowlevel_8bindings_x_event_filter(GdkXEvent *,GdkEvent *,void *); /*proto*/


/* Implementation of wimpiggy.lowlevel.bindings */

static char __pyx_k4[] = "gtk.gdk";
static char __pyx_k5[] = "wimpiggy.util";
static char __pyx_k9[] = "wimpiggy.error";
static char __pyx_k12[] = "wimpiggy.log";
static char __pyx_k14[] = "wimpiggy.lowlevel";
static char __pyx_k163[] = "Reference count a GdkPixmap that needs explicit cleanup.";
static char __pyx_k165[] = "wimpiggy-route-events-to";
static char __pyx_k166[] = "child-map-request-event";
static char __pyx_k167[] = "child-configure-request-event";
static char __pyx_k168[] = "wimpiggy-focus-in-event";
static char __pyx_k169[] = "wimpiggy-focus-out-event";
static char __pyx_k170[] = "wimpiggy-client-message-event";
static char __pyx_k171[] = "wimpiggy-map-event";
static char __pyx_k172[] = "wimpiggy-child-map-event";
static char __pyx_k173[] = "wimpiggy-unmap-event";
static char __pyx_k174[] = "wimpiggy-child-unmap-event";
static char __pyx_k175[] = "wimpiggy-destroy-event";
static char __pyx_k176[] = "wimpiggy-configure-event";
static char __pyx_k177[] = "wimpiggy-reparent-event";
static char __pyx_k178[] = "wimpiggy-property-notify-event";
static char __pyx_k179[] = "wimpiggy-key-press-event";
static char __pyx_k181[] = "wimpiggy-damage-event";

static PyObject *__pyx_n_struct;
static PyObject *__pyx_n_gobject;
static PyObject *__pyx_n_gtk;
static PyObject *__pyx_n_dump_exc;
static PyObject *__pyx_n_LameStruct;
static PyObject *__pyx_n_gtk_main_quit_really;
static PyObject *__pyx_n_trap;
static PyObject *__pyx_n_XError;
static PyObject *__pyx_n_Logger;
static PyObject *__pyx_n_log;
static PyObject *__pyx_n_XNone;
static PyObject *__pyx_n_PointerWindow;
static PyObject *__pyx_n_InputFocus;
static PyObject *__pyx_n_PointerRoot;
static PyObject *__pyx_n_CurrentTime;
static PyObject *__pyx_n_IsUnmapped;
static PyObject *__pyx_n_IsUnviewable;
static PyObject *__pyx_n_IsViewable;
static PyObject *__pyx_n_NoEventMask;
static PyObject *__pyx_n_KeyPressMask;
static PyObject *__pyx_n_KeyReleaseMask;
static PyObject *__pyx_n_ButtonPressMask;
static PyObject *__pyx_n_ButtonReleaseMask;
static PyObject *__pyx_n_EnterWindowMask;
static PyObject *__pyx_n_LeaveWindowMask;
static PyObject *__pyx_n_PointerMotionMask;
static PyObject *__pyx_n_PointerMotionHintMask;
static PyObject *__pyx_n_Button1MotionMask;
static PyObject *__pyx_n_Button2MotionMask;
static PyObject *__pyx_n_Button3MotionMask;
static PyObject *__pyx_n_Button4MotionMask;
static PyObject *__pyx_n_Button5MotionMask;
static PyObject *__pyx_n_ButtonMotionMask;
static PyObject *__pyx_n_KeymapStateMask;
static PyObject *__pyx_n_ExposureMask;
static PyObject *__pyx_n_VisibilityChangeMask;
static PyObject *__pyx_n_StructureNotifyMask;
static PyObject *__pyx_n_ResizeRedirectMask;
static PyObject *__pyx_n_SubstructureNotifyMask;
static PyObject *__pyx_n_SubstructureRedirectMask;
static PyObject *__pyx_n_FocusChangeMask;
static PyObject *__pyx_n_PropertyChangeMask;
static PyObject *__pyx_n_ColormapChangeMask;
static PyObject *__pyx_n_OwnerGrabButtonMask;
static PyObject *__pyx_n_KeyPress;
static PyObject *__pyx_n_KeyRelease;
static PyObject *__pyx_n_ButtonPress;
static PyObject *__pyx_n_ButtonRelease;
static PyObject *__pyx_n_MotionNotify;
static PyObject *__pyx_n_EnterNotify;
static PyObject *__pyx_n_LeaveNotify;
static PyObject *__pyx_n_FocusIn;
static PyObject *__pyx_n_FocusOut;
static PyObject *__pyx_n_KeymapNotify;
static PyObject *__pyx_n_Expose;
static PyObject *__pyx_n_GraphicsExpose;
static PyObject *__pyx_n_NoExpose;
static PyObject *__pyx_n_VisibilityNotify;
static PyObject *__pyx_n_CreateNotify;
static PyObject *__pyx_n_DestroyNotify;
static PyObject *__pyx_n_UnmapNotify;
static PyObject *__pyx_n_MapNotify;
static PyObject *__pyx_n_MapRequest;
static PyObject *__pyx_n_ReparentNotify;
static PyObject *__pyx_n_ConfigureNotify;
static PyObject *__pyx_n_ConfigureRequest;
static PyObject *__pyx_n_GravityNotify;
static PyObject *__pyx_n_ResizeRequest;
static PyObject *__pyx_n_CirculateNotify;
static PyObject *__pyx_n_CirculateRequest;
static PyObject *__pyx_n_PropertyNotify;
static PyObject *__pyx_n_SelectionClear;
static PyObject *__pyx_n_SelectionRequest;
static PyObject *__pyx_n_SelectionNotify;
static PyObject *__pyx_n_ColormapNotify;
static PyObject *__pyx_n_ClientMessage;
static PyObject *__pyx_n_MappingNotify;
static PyObject *__pyx_n_LASTEvent;
static PyObject *__pyx_n_PropModeReplace;
static PyObject *__pyx_n_PropModePrepend;
static PyObject *__pyx_n_PropModeAppend;
static PyObject *__pyx_n_CWX;
static PyObject *__pyx_n_CWY;
static PyObject *__pyx_n_CWWidth;
static PyObject *__pyx_n_CWHeight;
static PyObject *__pyx_n_CWBorderWidth;
static PyObject *__pyx_n_CWSibling;
static PyObject *__pyx_n_CWStackMode;
static PyObject *__pyx_n_Above;
static PyObject *__pyx_n_Below;
static PyObject *__pyx_n_BottomIf;
static PyObject *__pyx_n_TopIf;
static PyObject *__pyx_n_Opposite;
static PyObject *__pyx_n_Success;
static PyObject *__pyx_n_BadRequest;
static PyObject *__pyx_n_BadValue;
static PyObject *__pyx_n_BadWindow;
static PyObject *__pyx_n_BadPixmap;
static PyObject *__pyx_n_BadAtom;
static PyObject *__pyx_n_BadCursor;
static PyObject *__pyx_n_BadFont;
static PyObject *__pyx_n_BadMatch;
static PyObject *__pyx_n_BadDrawable;
static PyObject *__pyx_n_BadAccess;
static PyObject *__pyx_n_BadAlloc;
static PyObject *__pyx_n_BadColor;
static PyObject *__pyx_n_BadGC;
static PyObject *__pyx_n_BadIDChoice;
static PyObject *__pyx_n_BadName;
static PyObject *__pyx_n_BadLength;
static PyObject *__pyx_n_BadImplementation;
static PyObject *__pyx_n_FirstExtensionError;
static PyObject *__pyx_n_LastExtensionError;
static PyObject *__pyx_n_USPosition;
static PyObject *__pyx_n_USSize;
static PyObject *__pyx_n_PPosition;
static PyObject *__pyx_n_PSize;
static PyObject *__pyx_n_PMinSize;
static PyObject *__pyx_n_PMaxSize;
static PyObject *__pyx_n_PResizeInc;
static PyObject *__pyx_n_PAspect;
static PyObject *__pyx_n_PBaseSize;
static PyObject *__pyx_n_PWinGravity;
static PyObject *__pyx_n_InputHint;
static PyObject *__pyx_n_StateHint;
static PyObject *__pyx_n_IconPixmapHint;
static PyObject *__pyx_n_IconWindowHint;
static PyObject *__pyx_n_IconPositionHint;
static PyObject *__pyx_n_IconMaskHint;
static PyObject *__pyx_n_WindowGroupHint;
static PyObject *__pyx_n_XUrgencyHint;
static PyObject *__pyx_n_WithdrawnState;
static PyObject *__pyx_n_NormalState;
static PyObject *__pyx_n_IconicState;
static PyObject *__pyx_n_RevertToParent;
static PyObject *__pyx_n_RevertToPointerRoot;
static PyObject *__pyx_n_RevertToNone;
static PyObject *__pyx_n_NotifyNormal;
static PyObject *__pyx_n_NotifyGrab;
static PyObject *__pyx_n_NotifyUngrab;
static PyObject *__pyx_n_NotifyAncestor;
static PyObject *__pyx_n_NotifyVirtual;
static PyObject *__pyx_n_NotifyInferior;
static PyObject *__pyx_n_NotifyNonlinear;
static PyObject *__pyx_n_NotifyNonlinearVirtual;
static PyObject *__pyx_n_NotifyPointer;
static PyObject *__pyx_n_NotifyPointerRoot;
static PyObject *__pyx_n_NotifyDetailNone;
static PyObject *__pyx_n_GrabModeSync;
static PyObject *__pyx_n_GrabModeAsync;
static PyObject *__pyx_n_AnyKey;
static PyObject *__pyx_n_AnyModifier;
static PyObject *__pyx_n_const;
static PyObject *__pyx_n_PropertyError;
static PyObject *__pyx_n_BadPropertyType;
static PyObject *__pyx_n_PropertyOverflow;
static PyObject *__pyx_n_NoSuchProperty;
static PyObject *__pyx_n__PixmapCleanupHandler;
static PyObject *__pyx_n_object;
static PyObject *__pyx_n___init__;
static PyObject *__pyx_n___del__;
static PyObject *__pyx_n__ev_receiver_key;
static PyObject *__pyx_n_XDamageNotify;
static PyObject *__pyx_n__x_event_signals;

static PyObject *__pyx_k4p;
static PyObject *__pyx_k5p;
static PyObject *__pyx_k9p;
static PyObject *__pyx_k12p;
static PyObject *__pyx_k14p;
static PyObject *__pyx_k163p;
static PyObject *__pyx_k165p;
static PyObject *__pyx_k166p;
static PyObject *__pyx_k167p;
static PyObject *__pyx_k168p;
static PyObject *__pyx_k169p;
static PyObject *__pyx_k170p;
static PyObject *__pyx_k171p;
static PyObject *__pyx_k172p;
static PyObject *__pyx_k173p;
static PyObject *__pyx_k174p;
static PyObject *__pyx_k175p;
static PyObject *__pyx_k176p;
static PyObject *__pyx_k177p;
static PyObject *__pyx_k178p;
static PyObject *__pyx_k179p;
static PyObject *__pyx_k181p;

static PyObject *__pyx_n_GObject;

static PyObject *__pyx_k182p;

static char __pyx_k182[] = "object %r is not a %r";

static GObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap(PyObject *__pyx_v_box,PyObject *__pyx_v_pyclass) {
  GObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  int __pyx_4;
  Py_INCREF(__pyx_v_box);
  Py_INCREF(__pyx_v_pyclass);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":75 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gobject); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_GObject); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyObject_IsSubclass(__pyx_v_pyclass,__pyx_2); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (!__pyx_3) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":76 */
  __pyx_3 = PyObject_IsInstance(__pyx_v_box,__pyx_v_pyclass); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 76; goto __pyx_L1;}
  __pyx_4 = (!__pyx_3);
  if (__pyx_4) {
    __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
    Py_INCREF(__pyx_v_box);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_box);
    Py_INCREF(__pyx_v_pyclass);
    PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_pyclass);
    __pyx_2 = PyNumber_Remainder(__pyx_k182p, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(PyExc_TypeError, __pyx_2, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":78 */
  __pyx_r = pygobject_get(__pyx_v_box);
  goto __pyx_L0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.unwrap");
  __pyx_r = NULL;
  __pyx_L0:;
  Py_DECREF(__pyx_v_box);
  Py_DECREF(__pyx_v_pyclass);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_wrap(GObject *__pyx_v_contents) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  __pyx_1 = pygobject_new(__pyx_v_contents); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 91; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.wrap");
  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_n_GBoxed;

static PyObject *__pyx_k183p;

static char __pyx_k183[] = "object %r is not a %r";

static void *__pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap_boxed(PyObject *__pyx_v_box,PyObject *__pyx_v_pyclass) {
  void *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  int __pyx_4;
  Py_INCREF(__pyx_v_box);
  Py_INCREF(__pyx_v_pyclass);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":95 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gobject); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 95; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_GBoxed); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 95; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyObject_IsSubclass(__pyx_v_pyclass,__pyx_2); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 95; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (!__pyx_3) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 95; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":96 */
  __pyx_3 = PyObject_IsInstance(__pyx_v_box,__pyx_v_pyclass); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 96; goto __pyx_L1;}
  __pyx_4 = (!__pyx_3);
  if (__pyx_4) {
    __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 97; goto __pyx_L1;}
    Py_INCREF(__pyx_v_box);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_box);
    Py_INCREF(__pyx_v_pyclass);
    PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_pyclass);
    __pyx_2 = PyNumber_Remainder(__pyx_k183p, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 97; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(PyExc_TypeError, __pyx_2, 0);
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 97; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":98 */
  __pyx_r = ((PyGBoxed *)__pyx_v_box)->boxed;
  goto __pyx_L0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_WriteUnraisable("wimpiggy.lowlevel.bindings.unwrap_boxed");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_box);
  Py_DECREF(__pyx_v_pyclass);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_premultiply_argb_in_place(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_premultiply_argb_in_place(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_buf = 0;
  int *__pyx_v_cbuf;
  Py_ssize_t __pyx_v_cbuf_len;
  int __pyx_v_a;
  int __pyx_v_r;
  int __pyx_v_g;
  int __pyx_v_b;
  int __pyx_v_i;
  PyObject *__pyx_r;
  int __pyx_1;
  Py_ssize_t __pyx_2;
  static char *__pyx_argnames[] = {"buf",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_buf)) return 0;
  Py_INCREF(__pyx_v_buf);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":111 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (!((sizeof(int)) == 4)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 111; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":112 */
  __pyx_1 = PyObject_AsWriteBuffer(__pyx_v_buf,((void **)(&__pyx_v_cbuf)),(&__pyx_v_cbuf_len)); if (__pyx_1 == (-1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 112; goto __pyx_L1;}

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":114 */
  __pyx_2 = (__pyx_v_cbuf_len / 4);
  for (__pyx_v_i = 0; __pyx_v_i < __pyx_2; ++__pyx_v_i) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":115 */
    __pyx_v_a = (((__pyx_v_cbuf[__pyx_v_i]) >> 24) & 0xff);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":116 */
    __pyx_v_r = (((__pyx_v_cbuf[__pyx_v_i]) >> 16) & 0xff);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":117 */
    __pyx_v_r = ((__pyx_v_r * __pyx_v_a) / 255);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":118 */
    __pyx_v_g = (((__pyx_v_cbuf[__pyx_v_i]) >> 8) & 0xff);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":119 */
    __pyx_v_g = ((__pyx_v_g * __pyx_v_a) / 255);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":120 */
    __pyx_v_b = (((__pyx_v_cbuf[__pyx_v_i]) >> 0) & 0xff);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":121 */
    __pyx_v_b = ((__pyx_v_b * __pyx_v_a) / 255);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":122 */
    (__pyx_v_cbuf[__pyx_v_i]) = ((((__pyx_v_a << 24) | (__pyx_v_r << 16)) | (__pyx_v_g << 8)) | (__pyx_v_b << 0));
  }

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.premultiply_argb_in_place");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_buf);
  return __pyx_r;
}

static PyObject *__pyx_n_gdk;
static PyObject *__pyx_n_Window;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xwindow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xwindow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  GObject *__pyx_3;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 330; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 330; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_Window); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 330; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap(__pyx_v_pywindow,__pyx_1); if (__pyx_3 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 330; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(GDK_WINDOW_XID(((GdkWindow *)__pyx_3))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 330; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_xwindow");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_get_display_for;
static PyObject *__pyx_n_window_foreign_new_for_display;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pywindow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pywindow(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_xwindow = 0;
  PyObject *__pyx_v_disp;
  PyObject *__pyx_v_win;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  static char *__pyx_argnames[] = {"display_source","xwindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_xwindow)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_xwindow);
  __pyx_v_disp = Py_None; Py_INCREF(Py_None);
  __pyx_v_win = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":333 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_display_for); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 333; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 333; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 333; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_disp);
  __pyx_v_disp = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":334 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_window_foreign_new_for_display); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
  Py_INCREF(__pyx_v_disp);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_disp);
  Py_INCREF(__pyx_v_xwindow);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_xwindow);
  __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 334; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_v_win);
  __pyx_v_win = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":335 */
  __pyx_4 = __pyx_v_win == Py_None;
  if (__pyx_4) {
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_XError); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 336; goto __pyx_L1;}
    __pyx_1 = PyLong_FromUnsignedLong(BadWindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 336; goto __pyx_L1;}
    __Pyx_Raise(__pyx_3, __pyx_1, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 336; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":337 */
  Py_INCREF(__pyx_v_win);
  __pyx_r = __pyx_v_win;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_pywindow");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_disp);
  Py_DECREF(__pyx_v_win);
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_xwindow);
  return __pyx_r;
}

static PyObject *__pyx_n_Display;
static PyObject *__pyx_n_Drawable;
static PyObject *__pyx_n_Widget;
static PyObject *__pyx_n_Clipboard;
static PyObject *__pyx_n_get_display;

static PyObject *__pyx_k184p;

static char __pyx_k184[] = "Don't know how to get a display from %r";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_display_for(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_display_for(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_obj = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"obj",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_obj)) return 0;
  Py_INCREF(__pyx_v_obj);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_Display); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_3 = PyObject_IsInstance(__pyx_v_obj,__pyx_1); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 340; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_3) {
    Py_INCREF(__pyx_v_obj);
    __pyx_r = __pyx_v_obj;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 342; goto __pyx_L1;}
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_gdk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 342; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_Drawable); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 342; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 343; goto __pyx_L1;}
  __pyx_4 = PyObject_GetAttr(__pyx_1, __pyx_n_Widget); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 343; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
  __pyx_5 = PyObject_GetAttr(__pyx_1, __pyx_n_Clipboard); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 344; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyTuple_New(3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 342; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_2);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_4);
  PyTuple_SET_ITEM(__pyx_1, 2, __pyx_5);
  __pyx_2 = 0;
  __pyx_4 = 0;
  __pyx_5 = 0;
  __pyx_3 = PyObject_IsInstance(__pyx_v_obj,__pyx_1); if (__pyx_3 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 342; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_3) {
    __pyx_2 = PyObject_GetAttr(__pyx_v_obj, __pyx_n_get_display); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    __pyx_4 = PyObject_CallObject(__pyx_2, 0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 345; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_r = __pyx_4;
    __pyx_4 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 347; goto __pyx_L1;}
    Py_INCREF(__pyx_v_obj);
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_obj);
    __pyx_1 = PyNumber_Remainder(__pyx_k184p, __pyx_5); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 347; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __Pyx_Raise(PyExc_TypeError, __pyx_1, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 347; goto __pyx_L1;}
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_display_for");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_obj);
  return __pyx_r;
}

static GdkDisplay *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_raw_display_for(PyObject *__pyx_v_obj) {
  GdkDisplay *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  GObject *__pyx_4;
  Py_INCREF(__pyx_v_obj);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_display_for); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  Py_INCREF(__pyx_v_obj);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_obj);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_Display); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap(__pyx_3,__pyx_1); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 350; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_r = ((GdkDisplay *)__pyx_4);
  goto __pyx_L0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_raw_display_for");
  __pyx_r = NULL;
  __pyx_L0:;
  Py_DECREF(__pyx_v_obj);
  return __pyx_r;
}

static Display *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(PyObject *__pyx_v_obj) {
  Display *__pyx_r;
  GdkDisplay *__pyx_1;
  Py_INCREF(__pyx_v_obj);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_raw_display_for(__pyx_v_obj); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 353; goto __pyx_L1;}
  __pyx_r = GDK_DISPLAY_XDISPLAY(__pyx_1);
  goto __pyx_L0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_xdisplay_for");
  __pyx_r = NULL;
  __pyx_L0:;
  Py_DECREF(__pyx_v_obj);
  return __pyx_r;
}

static PyObject *__pyx_n_atom_intern;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xatom(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_8wimpiggy_8lowlevel_8bindings_get_xatom[] = "Returns the X atom corresponding to the given Python string or Python\n    integer (assumed to already be an X atom).";
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xatom(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_str_or_xatom = 0;
  PyObject *__pyx_v_gdkatom;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  GdkDisplay *__pyx_5;
  static char *__pyx_argnames[] = {"display_source","str_or_xatom",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_str_or_xatom)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_str_or_xatom);
  __pyx_v_gdkatom = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":367 */
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 367; goto __pyx_L1;}
  Py_INCREF(((PyObject *)(&PyInt_Type)));
  PyTuple_SET_ITEM(__pyx_1, 0, ((PyObject *)(&PyInt_Type)));
  Py_INCREF(((PyObject *)(&PyLong_Type)));
  PyTuple_SET_ITEM(__pyx_1, 1, ((PyObject *)(&PyLong_Type)));
  __pyx_2 = PyObject_IsInstance(__pyx_v_str_or_xatom,__pyx_1); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 367; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {
    Py_INCREF(__pyx_v_str_or_xatom);
    __pyx_r = __pyx_v_str_or_xatom;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":369 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_2 = PyObject_IsInstance(__pyx_v_str_or_xatom,((PyObject *)(&PyString_Type))); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 369; goto __pyx_L1;}
  if (!__pyx_2) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 369; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":370 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 370; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 370; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_3, __pyx_n_atom_intern); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 370; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 370; goto __pyx_L1;}
  Py_INCREF(__pyx_v_str_or_xatom);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_str_or_xatom);
  __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 370; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_gdkatom);
  __pyx_v_gdkatom = __pyx_4;
  __pyx_4 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":371 */
  __pyx_5 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_raw_display_for(__pyx_v_display_source); if (__pyx_5 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 372; goto __pyx_L1;}
  __pyx_1 = PyLong_FromUnsignedLong(gdk_x11_atom_to_xatom_for_display(__pyx_5,PyGdkAtom_Get(__pyx_v_gdkatom))); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 371; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_xatom");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_gdkatom);
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_str_or_xatom);
  return __pyx_r;
}

static PyObject *__pyx_k185p;

static char __pyx_k185[] = "weirdly huge purported xatom: %s";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pyatom(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pyatom(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_xatom = 0;
  GdkDisplay *__pyx_v_disp;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  int __pyx_5;
  GdkDisplay *__pyx_6;
  Atom __pyx_7;
  static char *__pyx_argnames[] = {"display_source","xatom",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_xatom)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_xatom);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":377 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  Py_INCREF(__pyx_v_xatom);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_xatom);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyLong_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyInt_FromLong(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(((PyObject *)(&PyLong_Type)), __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyInt_FromLong(32); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  __pyx_4 = PyNumber_Power(__pyx_1, __pyx_3, Py_None); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_Cmp(__pyx_2, __pyx_4, &__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 377; goto __pyx_L1;}
  __pyx_5 = __pyx_5 > 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (__pyx_5) {
    __pyx_1 = PyNumber_Remainder(__pyx_k185p, __pyx_v_xatom); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 378; goto __pyx_L1;}
    __Pyx_Raise(PyExc_Exception, __pyx_1, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 378; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":380 */
  __pyx_6 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_raw_display_for(__pyx_v_display_source); if (__pyx_6 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 380; goto __pyx_L1;}
  __pyx_v_disp = __pyx_6;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":381 */
  __pyx_7 = PyInt_AsUnsignedLongMask(__pyx_v_xatom); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 381; goto __pyx_L1;}
  __pyx_3 = PyGdkAtom_New(gdk_x11_xatom_to_atom_for_display(__pyx_v_disp,__pyx_7)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 381; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 381; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
  __pyx_3 = 0;
  __pyx_4 = PyObject_CallObject(((PyObject *)(&PyString_Type)), __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 381; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_r = __pyx_4;
  __pyx_4 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_pyatom");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_xatom);
  return __pyx_r;
}

static PyObject *__pyx_n_append;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_gdk_atom_objects_from_gdk_atom_array(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_gdk_atom_objects_from_gdk_atom_array(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_atom_string = 0;
  GdkAtom *__pyx_v_array;
  Py_ssize_t __pyx_v_array_len_bytes;
  PyObject *__pyx_v_array_len;
  PyObject *__pyx_v_objects;
  PyObject *__pyx_v_i;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Py_ssize_t __pyx_4;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  static char *__pyx_argnames[] = {"atom_string",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_atom_string)) return 0;
  Py_INCREF(__pyx_v_atom_string);
  __pyx_v_array_len = Py_None; Py_INCREF(Py_None);
  __pyx_v_objects = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":393 */
  __pyx_1 = PyObject_AsReadBuffer(__pyx_v_atom_string,((void **)(&__pyx_v_array)),(&__pyx_v_array_len_bytes)); if (__pyx_1 == (-1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 393; goto __pyx_L1;}

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":394 */
  __pyx_2 = PyInt_FromSsize_t((__pyx_v_array_len_bytes / (sizeof(GdkAtom)))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 394; goto __pyx_L1;}
  Py_DECREF(__pyx_v_array_len);
  __pyx_v_array_len = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":395 */
  __pyx_2 = PyList_New(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 395; goto __pyx_L1;}
  Py_DECREF(__pyx_v_objects);
  __pyx_v_objects = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":396 */
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 396; goto __pyx_L1;}
  Py_INCREF(__pyx_v_array_len);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_array_len);
  __pyx_3 = PyObject_CallObject(((PyObject *)(&PyRange_Type)), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 396; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyObject_GetIter(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 396; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  for (;;) {
    __pyx_3 = PyIter_Next(__pyx_2);
    if (!__pyx_3) {
      if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 396; goto __pyx_L1;}
      break;
    }
    Py_DECREF(__pyx_v_i);
    __pyx_v_i = __pyx_3;
    __pyx_3 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_v_objects, __pyx_n_append); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    __pyx_4 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    __pyx_5 = PyGdkAtom_New((__pyx_v_array[__pyx_4])); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_6, 0, __pyx_5);
    __pyx_5 = 0;
    __pyx_5 = PyObject_CallObject(__pyx_3, __pyx_6); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
  }
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":398 */
  Py_INCREF(__pyx_v_objects);
  __pyx_r = __pyx_v_objects;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.gdk_atom_objects_from_gdk_atom_array");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_array_len);
  Py_DECREF(__pyx_v_objects);
  Py_DECREF(__pyx_v_i);
  Py_DECREF(__pyx_v_atom_string);
  return __pyx_r;
}

static PyObject *__pyx_n_i;
static PyObject *__pyx_n_l;
static PyObject *__pyx_n_pack;
static PyObject *__pyx_n_unpack;

static PyObject *__pyx_k186p;
static PyObject *__pyx_k188p;

static char __pyx_k186[] = "@";
static char __pyx_k188[] = "@";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_ints_to_longs(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_ints_to_longs(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_data = 0;
  PyObject *__pyx_v_n;
  PyObject *__pyx_v_format_from;
  PyObject *__pyx_v_format_to;
  PyObject *__pyx_r;
  Py_ssize_t __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  static char *__pyx_argnames[] = {"data",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_data)) return 0;
  Py_INCREF(__pyx_v_data);
  __pyx_v_n = Py_None; Py_INCREF(Py_None);
  __pyx_v_format_from = Py_None; Py_INCREF(Py_None);
  __pyx_v_format_to = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":410 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_1 = PyObject_Length(__pyx_v_data); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 410; goto __pyx_L1;}
  if (!((__pyx_1 % (sizeof(int))) == 0)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 410; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":411 */
  __pyx_1 = PyObject_Length(__pyx_v_data); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 411; goto __pyx_L1;}
  __pyx_2 = PyInt_FromSsize_t((__pyx_1 / (sizeof(int)))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 411; goto __pyx_L1;}
  Py_DECREF(__pyx_v_n);
  __pyx_v_n = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":412 */
  __pyx_2 = PyNumber_Multiply(__pyx_n_i, __pyx_v_n); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 412; goto __pyx_L1;}
  __pyx_3 = PyNumber_Add(__pyx_k186p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 412; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_format_from);
  __pyx_v_format_from = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":413 */
  __pyx_2 = PyNumber_Multiply(__pyx_n_l, __pyx_v_n); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 413; goto __pyx_L1;}
  __pyx_3 = PyNumber_Add(__pyx_k188p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 413; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_format_to);
  __pyx_v_format_to = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":414 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_struct); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_pack); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_INCREF(__pyx_v_format_to);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_format_to);
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_struct); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  __pyx_5 = PyObject_GetAttr(__pyx_4, __pyx_n_unpack); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_INCREF(__pyx_v_format_from);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_format_from);
  Py_INCREF(__pyx_v_data);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_data);
  __pyx_6 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_5 = PySequence_Tuple(__pyx_6); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  __pyx_4 = PyNumber_Add(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_6 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 414; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_r = __pyx_6;
  __pyx_6 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._munge_packed_ints_to_longs");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_n);
  Py_DECREF(__pyx_v_format_from);
  Py_DECREF(__pyx_v_format_to);
  Py_DECREF(__pyx_v_data);
  return __pyx_r;
}

static PyObject *__pyx_n__munge_packed_ints_to_longs;
static PyObject *__pyx_n_get_xwindow;
static PyObject *__pyx_n_get_xatom;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XChangeProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_8wimpiggy_8lowlevel_8bindings_XChangeProperty[] = "Set a property on a window.";
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XChangeProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_property = 0;
  PyObject *__pyx_v_value = 0;
  PyObject *__pyx_v_type;
  PyObject *__pyx_v_format;
  PyObject *__pyx_v_data;
  PyObject *__pyx_v_nitems;
  char *__pyx_v_data_str;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  int __pyx_5;
  Py_ssize_t __pyx_6;
  char *__pyx_7;
  Display *__pyx_8;
  Window __pyx_9;
  Atom __pyx_10;
  Atom __pyx_11;
  int __pyx_12;
  static char *__pyx_argnames[] = {"pywindow","property","value",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_property, &__pyx_v_value)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  Py_INCREF(__pyx_v_value);
  __pyx_v_type = Py_None; Py_INCREF(Py_None);
  __pyx_v_format = Py_None; Py_INCREF(Py_None);
  __pyx_v_data = Py_None; Py_INCREF(Py_None);
  __pyx_v_nitems = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":418 */
  __pyx_1 = PyObject_GetIter(__pyx_v_value); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 418; goto __pyx_L1;}
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 418; goto __pyx_L1;}
  Py_DECREF(__pyx_v_type);
  __pyx_v_type = __pyx_2;
  __pyx_2 = 0;
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 418; goto __pyx_L1;}
  Py_DECREF(__pyx_v_format);
  __pyx_v_format = __pyx_2;
  __pyx_2 = 0;
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 418; goto __pyx_L1;}
  Py_DECREF(__pyx_v_data);
  __pyx_v_data = __pyx_2;
  __pyx_2 = 0;
  if (__Pyx_EndUnpack(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 418; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":419 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_2 = PyInt_FromLong(8); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong(16); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(32); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_2);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_1);
  PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
  __pyx_2 = 0;
  __pyx_1 = 0;
  __pyx_3 = 0;
  __pyx_5 = PySequence_Contains(__pyx_4, __pyx_v_format); if (__pyx_5 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (!__pyx_5) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 419; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":420 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_6 = PyObject_Length(__pyx_v_data); if (__pyx_6 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  __pyx_2 = PyInt_FromSsize_t(__pyx_6); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong(8); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  __pyx_3 = PyNumber_Divide(__pyx_v_format, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyNumber_Remainder(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_4, __pyx_1, &__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  __pyx_5 = __pyx_5 == 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (!__pyx_5) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 420; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":421 */
  __pyx_6 = PyObject_Length(__pyx_v_data); if (__pyx_6 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 421; goto __pyx_L1;}
  __pyx_2 = PyInt_FromSsize_t(__pyx_6); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 421; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(8); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 421; goto __pyx_L1;}
  __pyx_4 = PyNumber_Divide(__pyx_v_format, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 421; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyNumber_Divide(__pyx_2, __pyx_4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 421; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_v_nitems);
  __pyx_v_nitems = __pyx_1;
  __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":422 */
  __pyx_3 = PyInt_FromLong(32); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 422; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_format, __pyx_3, &__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 422; goto __pyx_L1;}
  __pyx_5 = __pyx_5 == 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_5) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__munge_packed_ints_to_longs); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 423; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 423; goto __pyx_L1;}
    Py_INCREF(__pyx_v_data);
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_data);
    __pyx_1 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 423; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_v_data);
    __pyx_v_data = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":425 */
  __pyx_7 = PyString_AsString(__pyx_v_data); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 425; goto __pyx_L1;}
  __pyx_v_data_str = __pyx_7;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":426 */
  __pyx_8 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_8 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 426; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 427; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 427; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 427; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_9 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 427; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 428; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 428; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_property);
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 428; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_10 = PyInt_AsUnsignedLongMask(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 428; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 429; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 429; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_pywindow);
  Py_INCREF(__pyx_v_type);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_type);
  __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 429; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_11 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 429; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsLong(__pyx_v_format); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 430; goto __pyx_L1;}
  __pyx_12 = PyInt_AsLong(__pyx_v_nitems); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 433; goto __pyx_L1;}
  XChangeProperty(__pyx_8,__pyx_9,__pyx_10,__pyx_11,__pyx_5,PropModeReplace,((unsigned char *)__pyx_v_data_str),__pyx_12);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XChangeProperty");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_type);
  Py_DECREF(__pyx_v_format);
  Py_DECREF(__pyx_v_data);
  Py_DECREF(__pyx_v_nitems);
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_property);
  Py_DECREF(__pyx_v_value);
  return __pyx_r;
}

static PyObject *__pyx_k190p;
static PyObject *__pyx_k192p;

static char __pyx_k190[] = "@";
static char __pyx_k192[] = "@";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_longs_to_ints(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_longs_to_ints(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_data = 0;
  PyObject *__pyx_v_n;
  PyObject *__pyx_v_format_from;
  PyObject *__pyx_v_format_to;
  PyObject *__pyx_r;
  Py_ssize_t __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  static char *__pyx_argnames[] = {"data",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_data)) return 0;
  Py_INCREF(__pyx_v_data);
  __pyx_v_n = Py_None; Py_INCREF(Py_None);
  __pyx_v_format_from = Py_None; Py_INCREF(Py_None);
  __pyx_v_format_to = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":436 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_1 = PyObject_Length(__pyx_v_data); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 436; goto __pyx_L1;}
  if (!((__pyx_1 % (sizeof(long))) == 0)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 436; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":437 */
  __pyx_1 = PyObject_Length(__pyx_v_data); if (__pyx_1 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 437; goto __pyx_L1;}
  __pyx_2 = PyInt_FromSsize_t((__pyx_1 / (sizeof(long)))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 437; goto __pyx_L1;}
  Py_DECREF(__pyx_v_n);
  __pyx_v_n = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":438 */
  __pyx_2 = PyNumber_Multiply(__pyx_n_l, __pyx_v_n); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 438; goto __pyx_L1;}
  __pyx_3 = PyNumber_Add(__pyx_k190p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 438; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_format_from);
  __pyx_v_format_from = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":439 */
  __pyx_2 = PyNumber_Multiply(__pyx_n_i, __pyx_v_n); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 439; goto __pyx_L1;}
  __pyx_3 = PyNumber_Add(__pyx_k192p, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 439; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_format_to);
  __pyx_v_format_to = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":440 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_struct); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_pack); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_INCREF(__pyx_v_format_to);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_format_to);
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_struct); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  __pyx_5 = PyObject_GetAttr(__pyx_4, __pyx_n_unpack); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_INCREF(__pyx_v_format_from);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_format_from);
  Py_INCREF(__pyx_v_data);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_data);
  __pyx_6 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_5 = PySequence_Tuple(__pyx_6); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  __pyx_4 = PyNumber_Add(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_6 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 440; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_r = __pyx_6;
  __pyx_6 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._munge_packed_longs_to_ints");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_n);
  Py_DECREF(__pyx_v_format_from);
  Py_DECREF(__pyx_v_format_to);
  Py_DECREF(__pyx_v_data);
  return __pyx_r;
}

static PyObject *__pyx_n__munge_packed_longs_to_ints;

static PyObject *__pyx_k194p;

static char __pyx_k194[] = "no such window";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XGetWindowProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XGetWindowProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_property = 0;
  PyObject *__pyx_v_req_type = 0;
  PyObject *__pyx_v_buffer_size;
  Atom __pyx_v_xactual_type;
  int __pyx_v_actual_format;
  unsigned long __pyx_v_nitems;
  unsigned long __pyx_v_bytes_after;
  unsigned char *__pyx_v_prop;
  Status __pyx_v_status;
  PyObject *__pyx_v_xreq_type;
  PyObject *__pyx_v_bytes_per_item;
  PyObject *__pyx_v_nbytes;
  PyObject *__pyx_v_data;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  Atom __pyx_6;
  long __pyx_7;
  Bool __pyx_8;
  Atom __pyx_9;
  int __pyx_10;
  unsigned long __pyx_11;
  static char *__pyx_argnames[] = {"pywindow","property","req_type",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_property, &__pyx_v_req_type)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  Py_INCREF(__pyx_v_req_type);
  __pyx_v_buffer_size = Py_None; Py_INCREF(Py_None);
  __pyx_v_xreq_type = Py_None; Py_INCREF(Py_None);
  __pyx_v_bytes_per_item = Py_None; Py_INCREF(Py_None);
  __pyx_v_nbytes = Py_None; Py_INCREF(Py_None);
  __pyx_v_data = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":455 */
  __pyx_1 = PyInt_FromLong(((64 * 1024) * 5)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 455; goto __pyx_L1;}
  Py_DECREF(__pyx_v_buffer_size);
  __pyx_v_buffer_size = __pyx_1;
  __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":461 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 461; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 461; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  Py_INCREF(__pyx_v_req_type);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_req_type);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 461; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_xreq_type);
  __pyx_v_xreq_type = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":465 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 465; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 466; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 466; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 466; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 466; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 467; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 467; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_property);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 467; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_6 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 467; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyInt_FromLong(4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  __pyx_2 = PyNumber_Divide(__pyx_v_buffer_size, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_7 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_8 = PyInt_AsLong(Py_False); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 472; goto __pyx_L1;}
  __pyx_9 = PyInt_AsUnsignedLongMask(__pyx_v_xreq_type); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 473; goto __pyx_L1;}
  __pyx_v_status = XGetWindowProperty(__pyx_4,__pyx_5,__pyx_6,0,__pyx_7,__pyx_8,__pyx_9,(&__pyx_v_xactual_type),(&__pyx_v_actual_format),(&__pyx_v_nitems),(&__pyx_v_bytes_after),(&__pyx_v_prop));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":475 */
  __pyx_10 = (__pyx_v_status != Success);
  if (__pyx_10) {
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_PropertyError); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 476; goto __pyx_L1;}
    __Pyx_Raise(__pyx_3, __pyx_k194p, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 476; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":477 */
  __pyx_10 = (__pyx_v_xactual_type == None);
  if (__pyx_10) {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_NoSuchProperty); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 478; goto __pyx_L1;}
    __Pyx_Raise(__pyx_1, __pyx_v_property, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 478; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":479 */
  __pyx_2 = __pyx_v_xreq_type;
  Py_INCREF(__pyx_2);
  __pyx_10 = PyObject_IsTrue(__pyx_2); if (__pyx_10 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 479; goto __pyx_L1;}
  if (__pyx_10) {
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_xactual_type); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 479; goto __pyx_L1;}
    if (PyObject_Cmp(__pyx_v_xreq_type, __pyx_3, &__pyx_10) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 479; goto __pyx_L1;}
    __pyx_10 = __pyx_10 != 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_2 = PyInt_FromLong(__pyx_10); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 479; goto __pyx_L1;}
  }
  __pyx_10 = PyObject_IsTrue(__pyx_2); if (__pyx_10 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 479; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_10) {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_BadPropertyType); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
    __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_xactual_type); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
    __Pyx_Raise(__pyx_1, __pyx_3, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":482 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  __pyx_10 = __pyx_v_bytes_after;
  if (__pyx_10) {
    __pyx_10 = (!__pyx_v_nitems);
  }
  if (!(!__pyx_10)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 482; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":488 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (!(__pyx_v_actual_format > 0)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; goto __pyx_L1;}
  }
  #endif

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":489 */
  __pyx_10 = (__pyx_v_actual_format == 8);
  if (__pyx_10) {
    __pyx_2 = PyInt_FromLong(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 490; goto __pyx_L1;}
    Py_DECREF(__pyx_v_bytes_per_item);
    __pyx_v_bytes_per_item = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L5;
  }
  __pyx_10 = (__pyx_v_actual_format == 16);
  if (__pyx_10) {
    __pyx_1 = PyInt_FromLong((sizeof(short))); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; goto __pyx_L1;}
    Py_DECREF(__pyx_v_bytes_per_item);
    __pyx_v_bytes_per_item = __pyx_1;
    __pyx_1 = 0;
    goto __pyx_L5;
  }
  __pyx_10 = (__pyx_v_actual_format == 32);
  if (__pyx_10) {
    __pyx_3 = PyInt_FromLong((sizeof(long))); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; goto __pyx_L1;}
    Py_DECREF(__pyx_v_bytes_per_item);
    __pyx_v_bytes_per_item = __pyx_3;
    __pyx_3 = 0;
    goto __pyx_L5;
  }
  /*else*/ {
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_10 = PyObject_IsTrue(Py_False); if (__pyx_10 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 496; goto __pyx_L1;}
    if (!__pyx_10) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 496; goto __pyx_L1;}
    }
    #endif
  }
  __pyx_L5:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":497 */
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_nitems); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 497; goto __pyx_L1;}
  __pyx_1 = PyNumber_Multiply(__pyx_v_bytes_per_item, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 497; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_nbytes);
  __pyx_v_nbytes = __pyx_1;
  __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":498 */
  __pyx_11 = __pyx_v_bytes_after;
  if (__pyx_11) {
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_PropertyOverflow); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 499; goto __pyx_L1;}
    __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_bytes_after); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 499; goto __pyx_L1;}
    __pyx_1 = PyNumber_Add(__pyx_v_nbytes, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 499; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(__pyx_3, __pyx_1, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 499; goto __pyx_L1;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":500 */
  __pyx_10 = PyInt_AsLong(__pyx_v_nbytes); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 500; goto __pyx_L1;}
  __pyx_2 = PyString_FromStringAndSize(((char *)__pyx_v_prop),__pyx_10); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 500; goto __pyx_L1;}
  Py_DECREF(__pyx_v_data);
  __pyx_v_data = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":501 */
  XFree(__pyx_v_prop);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":502 */
  __pyx_10 = (__pyx_v_actual_format == 32);
  if (__pyx_10) {
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__munge_packed_longs_to_ints); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
    Py_INCREF(__pyx_v_data);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_data);
    __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 503; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L7;
  }
  /*else*/ {
    Py_INCREF(__pyx_v_data);
    __pyx_r = __pyx_v_data;
    goto __pyx_L0;
  }
  __pyx_L7:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XGetWindowProperty");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_buffer_size);
  Py_DECREF(__pyx_v_xreq_type);
  Py_DECREF(__pyx_v_bytes_per_item);
  Py_DECREF(__pyx_v_nbytes);
  Py_DECREF(__pyx_v_data);
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_property);
  Py_DECREF(__pyx_v_req_type);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XDeleteProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XDeleteProperty(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_property = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  Atom __pyx_6;
  static char *__pyx_argnames[] = {"pywindow","property",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_property)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 508; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 510; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 510; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  Py_INCREF(__pyx_v_property);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_property);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 510; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_6 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 510; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XDeleteProperty(__pyx_1,__pyx_5,__pyx_6);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XDeleteProperty");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_property);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XAddToSaveSet(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XAddToSaveSet(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 514; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 515; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XAddToSaveSet(__pyx_1,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XAddToSaveSet");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XRemoveFromSaveSet(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XRemoveFromSaveSet(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 518; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XRemoveFromSaveSet(__pyx_1,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XRemoveFromSaveSet");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_get_pywindow;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__query_tree(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__query_tree(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  Window __pyx_v_root;
  Window __pyx_v_parent;
  Window *__pyx_v_children;
  unsigned int __pyx_v_nchildren;
  PyObject *__pyx_v_pychildren;
  PyObject *__pyx_v_i;
  PyObject *__pyx_v_pyparent;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  int __pyx_6;
  long __pyx_7;
  Py_ssize_t __pyx_8;
  PyObject *__pyx_9 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_v_pychildren = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);
  __pyx_v_pyparent = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":526 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 526; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 527; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 527; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 527; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 527; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_6 = (!XQueryTree(__pyx_1,__pyx_5,(&__pyx_v_root),(&__pyx_v_parent),(&__pyx_v_children),(&__pyx_v_nchildren)));
  if (__pyx_6) {
    __pyx_2 = PyList_New(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; goto __pyx_L1;}
    Py_INCREF(Py_None);
    PyTuple_SET_ITEM(__pyx_3, 0, Py_None);
    PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
    __pyx_2 = 0;
    __pyx_r = __pyx_3;
    __pyx_3 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":530 */
  __pyx_4 = PyList_New(0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 530; goto __pyx_L1;}
  Py_DECREF(__pyx_v_pychildren);
  __pyx_v_pychildren = __pyx_4;
  __pyx_4 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":531 */
  for (__pyx_7 = 0; __pyx_7 < __pyx_v_nchildren; ++__pyx_7) {
    __pyx_2 = PyInt_FromLong(__pyx_7); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 531; goto __pyx_L1;}
    Py_DECREF(__pyx_v_i);
    __pyx_v_i = __pyx_2;
    __pyx_2 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_v_pychildren, __pyx_n_append); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_pywindow); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    __pyx_8 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    __pyx_2 = PyLong_FromUnsignedLong((__pyx_v_children[__pyx_8])); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    __pyx_9 = PyTuple_New(2); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    Py_INCREF(__pyx_v_pywindow);
    PyTuple_SET_ITEM(__pyx_9, 0, __pyx_v_pywindow);
    PyTuple_SET_ITEM(__pyx_9, 1, __pyx_2);
    __pyx_2 = 0;
    __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_9); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_9); __pyx_9 = 0;
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_2);
    __pyx_2 = 0;
    __pyx_9 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 532; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_9); __pyx_9 = 0;
  }

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":536 */
  __pyx_6 = (__pyx_v_nchildren > 0);
  if (__pyx_6) {
    __pyx_6 = (__pyx_v_children != NULL);
  }
  if (__pyx_6) {
    XFree(__pyx_v_children);
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":538 */
  __pyx_6 = (__pyx_v_parent != None);
  if (__pyx_6) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_pywindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 539; goto __pyx_L1;}
    __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_parent); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 539; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 539; goto __pyx_L1;}
    Py_INCREF(__pyx_v_pywindow);
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_pywindow);
    PyTuple_SET_ITEM(__pyx_4, 1, __pyx_3);
    __pyx_3 = 0;
    __pyx_9 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 539; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_v_pyparent);
    __pyx_v_pyparent = __pyx_9;
    __pyx_9 = 0;
    goto __pyx_L6;
  }
  /*else*/ {
    Py_INCREF(Py_None);
    Py_DECREF(__pyx_v_pyparent);
    __pyx_v_pyparent = Py_None;
  }
  __pyx_L6:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":542 */
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 542; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pyparent);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pyparent);
  Py_INCREF(__pyx_v_pychildren);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_pychildren);
  __pyx_r = __pyx_3;
  __pyx_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_9);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._query_tree");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pychildren);
  Py_DECREF(__pyx_v_i);
  Py_DECREF(__pyx_v_pyparent);
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n__query_tree;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_children(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_children(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_pyparent;
  PyObject *__pyx_v_pychildren;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_v_pyparent = Py_None; Py_INCREF(Py_None);
  __pyx_v_pychildren = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":545 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__query_tree); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyObject_GetIter(__pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_DECREF(__pyx_v_pyparent);
  __pyx_v_pyparent = __pyx_2;
  __pyx_2 = 0;
  __pyx_3 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_DECREF(__pyx_v_pychildren);
  __pyx_v_pychildren = __pyx_3;
  __pyx_3 = 0;
  if (__Pyx_EndUnpack(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 545; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":546 */
  Py_INCREF(__pyx_v_pychildren);
  __pyx_r = __pyx_v_pychildren;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_children");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pyparent);
  Py_DECREF(__pyx_v_pychildren);
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_parent(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_parent(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_pyparent;
  PyObject *__pyx_v_pychildren;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_v_pyparent = Py_None; Py_INCREF(Py_None);
  __pyx_v_pychildren = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":549 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__query_tree); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyObject_GetIter(__pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_2 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_DECREF(__pyx_v_pyparent);
  __pyx_v_pyparent = __pyx_2;
  __pyx_2 = 0;
  __pyx_3 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_DECREF(__pyx_v_pychildren);
  __pyx_v_pychildren = __pyx_3;
  __pyx_3 = 0;
  if (__Pyx_EndUnpack(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 549; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":550 */
  Py_INCREF(__pyx_v_pyparent);
  __pyx_r = __pyx_v_pyparent;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_parent");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pyparent);
  Py_DECREF(__pyx_v_pychildren);
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_is_mapped(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_is_mapped(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  XWindowAttributes __pyx_v_attrs;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":555 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 555; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 556; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 556; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 556; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 556; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XGetWindowAttributes(__pyx_1,__pyx_5,(&__pyx_v_attrs));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":558 */
  __pyx_2 = PyInt_FromLong((__pyx_v_attrs.map_state != IsUnmapped)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 558; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.is_mapped");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_is_override_redirect(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_is_override_redirect(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  XWindowAttributes __pyx_v_attrs;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":563 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 563; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 564; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 564; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 564; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 564; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XGetWindowAttributes(__pyx_1,__pyx_5,(&__pyx_v_attrs));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":566 */
  __pyx_2 = PyInt_FromLong(__pyx_v_attrs.override_redirect); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 566; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.is_override_redirect");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_geometry_with_border(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_geometry_with_border(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  XWindowAttributes __pyx_v_attrs;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  PyObject *__pyx_8 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":570 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 570; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 571; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 571; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 571; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 571; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XGetWindowAttributes(__pyx_1,__pyx_5,(&__pyx_v_attrs));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":573 */
  __pyx_2 = PyInt_FromLong(__pyx_v_attrs.x); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  __pyx_3 = PyInt_FromLong(__pyx_v_attrs.y); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  __pyx_4 = PyInt_FromLong(__pyx_v_attrs.width); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  __pyx_6 = PyInt_FromLong(__pyx_v_attrs.height); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  __pyx_7 = PyInt_FromLong(__pyx_v_attrs.border_width); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  __pyx_8 = PyTuple_New(5); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 573; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_8, 0, __pyx_2);
  PyTuple_SET_ITEM(__pyx_8, 1, __pyx_3);
  PyTuple_SET_ITEM(__pyx_8, 2, __pyx_4);
  PyTuple_SET_ITEM(__pyx_8, 3, __pyx_6);
  PyTuple_SET_ITEM(__pyx_8, 4, __pyx_7);
  __pyx_2 = 0;
  __pyx_3 = 0;
  __pyx_4 = 0;
  __pyx_6 = 0;
  __pyx_7 = 0;
  __pyx_r = __pyx_8;
  __pyx_8 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  Py_XDECREF(__pyx_8);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.geometry_with_border");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_printFocus;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XSetInputFocus(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XSetInputFocus(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_time = 0;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  Display *__pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  Window __pyx_6;
  Time __pyx_7;
  static char *__pyx_argnames[] = {"pywindow","time",0};
  __pyx_v_time = __pyx_k161;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_time)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_time);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":578 */
  __pyx_1 = __pyx_v_time == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyLong_FromUnsignedLong(CurrentTime); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 579; goto __pyx_L1;}
    Py_DECREF(__pyx_v_time);
    __pyx_v_time = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":580 */
  __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_3 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 580; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 581; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 581; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_pywindow);
  __pyx_5 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 581; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_6 = PyInt_AsUnsignedLongMask(__pyx_5); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 581; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_7 = PyInt_AsUnsignedLongMask(__pyx_v_time); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 583; goto __pyx_L1;}
  XSetInputFocus(__pyx_3,__pyx_6,RevertToParent,__pyx_7);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":584 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_printFocus); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_pywindow);
  __pyx_5 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 584; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XSetInputFocus");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_time);
  return __pyx_r;
}

static PyObject *__pyx_n_hex;

static PyObject *__pyx_k195p;

static char __pyx_k195[] = "Current focus: %s, %s";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_printFocus(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_printFocus(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  Window __pyx_v_w;
  int __pyx_v_revert_to;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"display_source",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_display_source)) return 0;
  Py_INCREF(__pyx_v_display_source);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":590 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 590; goto __pyx_L1;}
  XGetInputFocus(__pyx_1,(&__pyx_v_w),(&__pyx_v_revert_to));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":591 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_b, __pyx_n_hex); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_w); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_4);
  __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_3 = PyInt_FromLong(__pyx_v_revert_to); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  __pyx_5 = PyTuple_New(3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  Py_INCREF(__pyx_k195p);
  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k195p);
  PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
  PyTuple_SET_ITEM(__pyx_5, 2, __pyx_3);
  __pyx_4 = 0;
  __pyx_3 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 591; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.printFocus");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  return __pyx_r;
}

static PyObject *__pyx_n_max_size;
static PyObject *__pyx_n_HINT_MAX_SIZE;
static PyObject *__pyx_n_min_size;
static PyObject *__pyx_n_HINT_MIN_SIZE;
static PyObject *__pyx_n_base_size;
static PyObject *__pyx_n_HINT_BASE_SIZE;
static PyObject *__pyx_n_resize_inc;
static PyObject *__pyx_n_HINT_RESIZE_INC;
static PyObject *__pyx_n_min_aspect;
static PyObject *__pyx_n_max_aspect;
static PyObject *__pyx_n_HINT_ASPECT;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_calc_constrained_size(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_calc_constrained_size(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_width = 0;
  PyObject *__pyx_v_height = 0;
  PyObject *__pyx_v_hints = 0;
  GdkGeometry __pyx_v_geom;
  int __pyx_v_new_width;
  int __pyx_v_new_height;
  PyObject *__pyx_v_flags;
  PyObject *__pyx_v_vis_width;
  PyObject *__pyx_v_vis_height;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  double __pyx_4;
  unsigned int __pyx_5;
  int __pyx_6;
  PyObject *__pyx_7 = 0;
  static char *__pyx_argnames[] = {"width","height","hints",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_width, &__pyx_v_height, &__pyx_v_hints)) return 0;
  Py_INCREF(__pyx_v_width);
  Py_INCREF(__pyx_v_height);
  Py_INCREF(__pyx_v_hints);
  __pyx_v_flags = Py_None; Py_INCREF(Py_None);
  __pyx_v_vis_width = Py_None; Py_INCREF(Py_None);
  __pyx_v_vis_height = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":605 */
  __pyx_1 = __pyx_v_hints == Py_None;
  if (__pyx_1) {
    __pyx_2 = PyTuple_New(4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 606; goto __pyx_L1;}
    Py_INCREF(__pyx_v_width);
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_width);
    Py_INCREF(__pyx_v_height);
    PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_height);
    Py_INCREF(__pyx_v_width);
    PyTuple_SET_ITEM(__pyx_2, 2, __pyx_v_width);
    Py_INCREF(__pyx_v_height);
    PyTuple_SET_ITEM(__pyx_2, 3, __pyx_v_height);
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":610 */
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 610; goto __pyx_L1;}
  Py_DECREF(__pyx_v_flags);
  __pyx_v_flags = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":612 */
  __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_max_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 612; goto __pyx_L1;}
  __pyx_1 = __pyx_2 != Py_None;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":613 */
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}
    __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_gdk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_HINT_MAX_SIZE); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyNumber_Or(__pyx_v_flags, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 613; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_v_flags);
    __pyx_v_flags = __pyx_3;
    __pyx_3 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":614 */
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_max_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    __pyx_3 = PyObject_GetIter(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = __Pyx_UnpackItem(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_v_geom.max_width = __pyx_1;
    __pyx_2 = __Pyx_UnpackItem(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_v_geom.max_height = __pyx_1;
    if (__Pyx_EndUnpack(__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 614; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":615 */
  __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_min_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 615; goto __pyx_L1;}
  __pyx_1 = __pyx_2 != Py_None;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":616 */
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 616; goto __pyx_L1;}
    __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 616; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_HINT_MIN_SIZE); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 616; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyNumber_Or(__pyx_v_flags, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 616; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_v_flags);
    __pyx_v_flags = __pyx_2;
    __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":617 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_min_size); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    __pyx_2 = PyObject_GetIter(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = __Pyx_UnpackItem(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_v_geom.min_width = __pyx_1;
    __pyx_3 = __Pyx_UnpackItem(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_v_geom.min_height = __pyx_1;
    if (__Pyx_EndUnpack(__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 617; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":618 */
  __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_base_size); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 618; goto __pyx_L1;}
  __pyx_1 = __pyx_3 != Py_None;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":619 */
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_gdk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_HINT_BASE_SIZE); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyNumber_Or(__pyx_v_flags, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 619; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_v_flags);
    __pyx_v_flags = __pyx_3;
    __pyx_3 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":620 */
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_base_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    __pyx_3 = PyObject_GetIter(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = __Pyx_UnpackItem(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_v_geom.base_width = __pyx_1;
    __pyx_2 = __Pyx_UnpackItem(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_v_geom.base_height = __pyx_1;
    if (__Pyx_EndUnpack(__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 620; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    goto __pyx_L5;
  }
  __pyx_L5:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":621 */
  __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_resize_inc); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 621; goto __pyx_L1;}
  __pyx_1 = __pyx_2 != Py_None;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":622 */
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 622; goto __pyx_L1;}
    __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 622; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_HINT_RESIZE_INC); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 622; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyNumber_Or(__pyx_v_flags, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 622; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_v_flags);
    __pyx_v_flags = __pyx_2;
    __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":623 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_resize_inc); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    __pyx_2 = PyObject_GetIter(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = __Pyx_UnpackItem(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_v_geom.width_inc = __pyx_1;
    __pyx_3 = __Pyx_UnpackItem(__pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    __pyx_1 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_v_geom.height_inc = __pyx_1;
    if (__Pyx_EndUnpack(__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 623; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L6;
  }
  __pyx_L6:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":624 */
  __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_min_aspect); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 624; goto __pyx_L1;}
  __pyx_1 = __pyx_3 != Py_None;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":625 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_max_aspect); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 625; goto __pyx_L1;}
    __pyx_1 = __pyx_2 != Py_None;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (!__pyx_1) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 625; goto __pyx_L1;}
    }
    #endif

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":626 */
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 626; goto __pyx_L1;}
    __pyx_2 = PyObject_GetAttr(__pyx_3, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 626; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_HINT_ASPECT); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 626; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyNumber_Or(__pyx_v_flags, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 626; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_v_flags);
    __pyx_v_flags = __pyx_2;
    __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":627 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_min_aspect); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 627; goto __pyx_L1;}
    __pyx_4 = PyFloat_AsDouble(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 627; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_v_geom.min_aspect = __pyx_4;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":628 */
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_max_aspect); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 628; goto __pyx_L1;}
    __pyx_4 = PyFloat_AsDouble(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 628; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_v_geom.max_aspect = __pyx_4;
    goto __pyx_L7;
  }
  __pyx_L7:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":629 */
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_v_flags); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
  __pyx_1 = PyInt_AsLong(__pyx_v_width); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
  __pyx_6 = PyInt_AsLong(__pyx_v_height); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 629; goto __pyx_L1;}
  gdk_window_constrain_size((&__pyx_v_geom),__pyx_5,__pyx_1,__pyx_6,(&__pyx_v_new_width),(&__pyx_v_new_height));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":632 */
  __pyx_3 = PyInt_FromLong(__pyx_v_new_width); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 632; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_new_height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 632; goto __pyx_L1;}
  Py_DECREF(__pyx_v_vis_width);
  __pyx_v_vis_width = __pyx_3;
  __pyx_3 = 0;
  Py_DECREF(__pyx_v_vis_height);
  __pyx_v_vis_height = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":633 */
  __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_resize_inc); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 633; goto __pyx_L1;}
  __pyx_1 = __pyx_3 != Py_None;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_1) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":634 */
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_base_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 634; goto __pyx_L1;}
    __pyx_6 = __pyx_2 != Py_None;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (__pyx_6) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":635 */
      __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_base_size); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 635; goto __pyx_L1;}
      __pyx_2 = __Pyx_GetItemInt(__pyx_3, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 635; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyNumber_Subtract(__pyx_v_vis_width, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 635; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_v_vis_width);
      __pyx_v_vis_width = __pyx_3;
      __pyx_3 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":636 */
      __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_base_size); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 636; goto __pyx_L1;}
      __pyx_3 = __Pyx_GetItemInt(__pyx_2, 1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 636; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      __pyx_2 = PyNumber_Subtract(__pyx_v_vis_height, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 636; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_v_vis_height);
      __pyx_v_vis_height = __pyx_2;
      __pyx_2 = 0;
      goto __pyx_L9;
    }
    __pyx_L9:;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":637 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_resize_inc); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 637; goto __pyx_L1;}
    __pyx_2 = __Pyx_GetItemInt(__pyx_3, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 637; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyNumber_Divide(__pyx_v_vis_width, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 637; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_v_vis_width);
    __pyx_v_vis_width = __pyx_3;
    __pyx_3 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":638 */
    __pyx_2 = PyObject_GetAttr(__pyx_v_hints, __pyx_n_resize_inc); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 638; goto __pyx_L1;}
    __pyx_3 = __Pyx_GetItemInt(__pyx_2, 1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 638; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __pyx_2 = PyNumber_Divide(__pyx_v_vis_height, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 638; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_v_vis_height);
    __pyx_v_vis_height = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L8;
  }
  __pyx_L8:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":640 */
  __pyx_3 = PyInt_FromLong(__pyx_v_new_width); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 640; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_new_height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 640; goto __pyx_L1;}
  __pyx_7 = PyTuple_New(4); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 640; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_7, 0, __pyx_3);
  PyTuple_SET_ITEM(__pyx_7, 1, __pyx_2);
  Py_INCREF(__pyx_v_vis_width);
  PyTuple_SET_ITEM(__pyx_7, 2, __pyx_v_vis_width);
  Py_INCREF(__pyx_v_vis_height);
  PyTuple_SET_ITEM(__pyx_7, 3, __pyx_v_vis_height);
  __pyx_3 = 0;
  __pyx_2 = 0;
  __pyx_r = __pyx_7;
  __pyx_7 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_7);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.calc_constrained_size");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_flags);
  Py_DECREF(__pyx_v_vis_width);
  Py_DECREF(__pyx_v_vis_height);
  Py_DECREF(__pyx_v_width);
  Py_DECREF(__pyx_v_height);
  Py_DECREF(__pyx_v_hints);
  return __pyx_r;
}

static PyObject *__pyx_n_Region;

static PyObject *__pyx_k196p;

static char __pyx_k196[] = "empty region";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_rectangle_from_region(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_rectangle_from_region(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_region = 0;
  GdkRegion *__pyx_v_cregion;
  GdkRectangle *__pyx_v_rectangles;
  int __pyx_v_count;
  PyObject *__pyx_v_x;
  PyObject *__pyx_v_y;
  PyObject *__pyx_v_w;
  PyObject *__pyx_v_h;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"region",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_region)) return 0;
  Py_INCREF(__pyx_v_region);
  __pyx_v_x = Py_None; Py_INCREF(Py_None);
  __pyx_v_y = Py_None; Py_INCREF(Py_None);
  __pyx_v_w = Py_None; Py_INCREF(Py_None);
  __pyx_v_h = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":656 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 656; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_gdk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 656; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_Region); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 656; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_v_cregion = ((GdkRegion *)__pyx_f_8wimpiggy_8lowlevel_8bindings_unwrap_boxed(__pyx_v_region,__pyx_1));
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":657 */
  gdk_region_get_rectangles(__pyx_v_cregion,(&__pyx_v_rectangles),(&__pyx_v_count));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":658 */
  __pyx_3 = (__pyx_v_count == 0);
  if (__pyx_3) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":659 */
    g_free(__pyx_v_rectangles);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":660 */
    __Pyx_Raise(PyExc_ValueError, __pyx_k196p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 660; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":661 */
  __pyx_2 = PyInt_FromLong((__pyx_v_rectangles[0]).x); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 661; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong((__pyx_v_rectangles[0]).y); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 661; goto __pyx_L1;}
  __pyx_4 = PyInt_FromLong((__pyx_v_rectangles[0]).width); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 662; goto __pyx_L1;}
  __pyx_5 = PyInt_FromLong((__pyx_v_rectangles[0]).height); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 662; goto __pyx_L1;}
  Py_DECREF(__pyx_v_x);
  __pyx_v_x = __pyx_2;
  __pyx_2 = 0;
  Py_DECREF(__pyx_v_y);
  __pyx_v_y = __pyx_1;
  __pyx_1 = 0;
  Py_DECREF(__pyx_v_w);
  __pyx_v_w = __pyx_4;
  __pyx_4 = 0;
  Py_DECREF(__pyx_v_h);
  __pyx_v_h = __pyx_5;
  __pyx_5 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":663 */
  g_free(__pyx_v_rectangles);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":664 */
  __pyx_2 = PyTuple_New(4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 664; goto __pyx_L1;}
  Py_INCREF(__pyx_v_x);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_x);
  Py_INCREF(__pyx_v_y);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_y);
  Py_INCREF(__pyx_v_w);
  PyTuple_SET_ITEM(__pyx_2, 2, __pyx_v_w);
  Py_INCREF(__pyx_v_h);
  PyTuple_SET_ITEM(__pyx_2, 3, __pyx_v_h);
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_rectangle_from_region");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_w);
  Py_DECREF(__pyx_v_h);
  Py_DECREF(__pyx_v_region);
  return __pyx_r;
}

static PyObject *__pyx_n_range;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_modifier_map(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_get_modifier_map(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  XModifierKeymap *__pyx_v_xmodmap;
  PyObject *__pyx_v_keycode_array;
  PyObject *__pyx_v_i;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Py_ssize_t __pyx_5;
  PyObject *__pyx_6 = 0;
  static char *__pyx_argnames[] = {"display_source",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_display_source)) return 0;
  Py_INCREF(__pyx_v_display_source);
  __pyx_v_keycode_array = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":672 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 672; goto __pyx_L1;}
  __pyx_v_xmodmap = XGetModifierMapping(__pyx_1);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":673 */
  /*try:*/ {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":674 */
    __pyx_2 = PyList_New(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 674; goto __pyx_L3;}
    Py_DECREF(__pyx_v_keycode_array);
    __pyx_v_keycode_array = __pyx_2;
    __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":675 */
    __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_range); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
    __pyx_3 = PyInt_FromLong((8 * __pyx_v_xmodmap->max_keypermod)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_2 = PyObject_GetIter(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    for (;;) {
      __pyx_4 = PyIter_Next(__pyx_2);
      if (!__pyx_4) {
        if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 675; goto __pyx_L3;}
        break;
      }
      Py_DECREF(__pyx_v_i);
      __pyx_v_i = __pyx_4;
      __pyx_4 = 0;
      __pyx_3 = PyObject_GetAttr(__pyx_v_keycode_array, __pyx_n_append); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L3;}
      __pyx_5 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L3;}
      __pyx_4 = PyInt_FromLong((__pyx_v_xmodmap->modifiermap[__pyx_5])); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L3;}
      __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L3;}
      PyTuple_SET_ITEM(__pyx_6, 0, __pyx_4);
      __pyx_4 = 0;
      __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_6); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 676; goto __pyx_L3;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_6); __pyx_6 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
    }
    Py_DECREF(__pyx_2); __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":677 */
    __pyx_3 = PyInt_FromLong(__pyx_v_xmodmap->max_keypermod); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 677; goto __pyx_L3;}
    __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 677; goto __pyx_L3;}
    PyTuple_SET_ITEM(__pyx_6, 0, __pyx_3);
    Py_INCREF(__pyx_v_keycode_array);
    PyTuple_SET_ITEM(__pyx_6, 1, __pyx_v_keycode_array);
    __pyx_3 = 0;
    __pyx_r = __pyx_6;
    __pyx_6 = 0;
    goto __pyx_L2;
  }
  /*finally:*/ {
    int __pyx_why;
    PyObject *__pyx_exc_type, *__pyx_exc_value, *__pyx_exc_tb;
    int __pyx_exc_lineno;
    __pyx_why = 0; goto __pyx_L4;
    __pyx_L2: __pyx_why = 3; goto __pyx_L4;
    __pyx_L3: {
      __pyx_why = 4;
      Py_XDECREF(__pyx_4); __pyx_4 = 0;
      Py_XDECREF(__pyx_2); __pyx_2 = 0;
      Py_XDECREF(__pyx_3); __pyx_3 = 0;
      Py_XDECREF(__pyx_6); __pyx_6 = 0;
      PyErr_Fetch(&__pyx_exc_type, &__pyx_exc_value, &__pyx_exc_tb);
      __pyx_exc_lineno = __pyx_lineno;
      goto __pyx_L4;
    }
    __pyx_L4:;
    XFreeModifiermap(__pyx_v_xmodmap);
    switch (__pyx_why) {
      case 3: goto __pyx_L0;
      case 4: {
        PyErr_Restore(__pyx_exc_type, __pyx_exc_value, __pyx_exc_tb);
        __pyx_lineno = __pyx_exc_lineno;
        __pyx_exc_type = 0;
        __pyx_exc_value = 0;
        __pyx_exc_tb = 0;
        goto __pyx_L1;
      }
    }
  }

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.get_modifier_map");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_keycode_array);
  Py_DECREF(__pyx_v_i);
  Py_DECREF(__pyx_v_display_source);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_grab_key(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_grab_key(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_keycode = 0;
  PyObject *__pyx_v_modifiers = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  int __pyx_2;
  unsigned int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  Window __pyx_7;
  Bool __pyx_8;
  static char *__pyx_argnames[] = {"pywindow","keycode","modifiers",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_keycode, &__pyx_v_modifiers)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_keycode);
  Py_INCREF(__pyx_v_modifiers);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 682; goto __pyx_L1;}
  __pyx_2 = PyInt_AsLong(__pyx_v_keycode); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 682; goto __pyx_L1;}
  __pyx_3 = PyInt_AsUnsignedLongMask(__pyx_v_modifiers); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 682; goto __pyx_L1;}
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 683; goto __pyx_L1;}
  __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 683; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_pywindow);
  __pyx_6 = PyObject_CallObject(__pyx_4, __pyx_5); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 683; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  __pyx_7 = PyInt_AsUnsignedLongMask(__pyx_6); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 683; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  __pyx_8 = PyInt_AsLong(Py_False); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 685; goto __pyx_L1;}
  XGrabKey(__pyx_1,__pyx_2,__pyx_3,__pyx_7,__pyx_8,GrabModeAsync,GrabModeAsync);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.grab_key");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_keycode);
  Py_DECREF(__pyx_v_modifiers);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_ungrab_all_keys(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_ungrab_all_keys(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 694; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 695; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 695; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 695; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 695; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XUngrabKey(__pyx_1,AnyKey,AnyModifier,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.ungrab_all_keys");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XKillClient(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_XKillClient(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  XID __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 702; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 702; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 702; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 702; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 702; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XKillClient(__pyx_1,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.XKillClient");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_unmap_with_serial(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_unmap_with_serial(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_serial;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_v_serial = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":709 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 709; goto __pyx_L1;}
  __pyx_2 = PyLong_FromUnsignedLong(NextRequest(__pyx_1)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 709; goto __pyx_L1;}
  Py_DECREF(__pyx_v_serial);
  __pyx_v_serial = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":710 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 710; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 710; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 710; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 710; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 710; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XUnmapWindow(__pyx_1,__pyx_5);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":711 */
  Py_INCREF(__pyx_v_serial);
  __pyx_r = __pyx_v_serial;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.unmap_with_serial");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_serial);
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_show_unraised_without_extra_stupid_stuff(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_show_unraised_without_extra_stupid_stuff(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 719; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 719; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 719; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 719; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 719; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XMapWindow(__pyx_1,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.show_unraised_without_extra_stupid_stuff");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_get_data;
static PyObject *__pyx_n_set_data;

static PyObject *__pyx_k197p;
static PyObject *__pyx_k198p;
static PyObject *__pyx_k199p;
static PyObject *__pyx_k200p;

static char __pyx_k197[] = "XTest-support";
static char __pyx_k198[] = "XTest-support";
static char __pyx_k199[] = "XTest-support";
static char __pyx_k200[] = "XTest not supported";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XTest_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XTest_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_display;
  int __pyx_v_ignored;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  Display *__pyx_5;
  int __pyx_6;
  static char *__pyx_argnames[] = {"display_source",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_display_source)) return 0;
  Py_INCREF(__pyx_v_display_source);
  __pyx_v_display = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":734 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_display_for); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 734; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 734; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 734; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_display);
  __pyx_v_display = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":736 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_display, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 736; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 736; goto __pyx_L1;}
  Py_INCREF(__pyx_k197p);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k197p);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 736; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_4 = __pyx_3 == Py_None;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_4) {
    __pyx_1 = PyObject_GetAttr(__pyx_v_display, __pyx_n_set_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 737; goto __pyx_L1;}
    __pyx_5 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display); if (__pyx_5 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 738; goto __pyx_L1;}
    __pyx_2 = PyInt_FromLong(XTestQueryExtension(__pyx_5,(&__pyx_v_ignored),(&__pyx_v_ignored),(&__pyx_v_ignored),(&__pyx_v_ignored))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 738; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 737; goto __pyx_L1;}
    Py_INCREF(__pyx_k198p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k198p);
    PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
    __pyx_2 = 0;
    __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 737; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":741 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_display, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 741; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 741; goto __pyx_L1;}
  Py_INCREF(__pyx_k199p);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k199p);
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 741; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_4 = PyObject_IsTrue(__pyx_2); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 741; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_6 = (!__pyx_4);
  if (__pyx_6) {
    __Pyx_Raise(PyExc_ValueError, __pyx_k200p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 742; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._ensure_XTest_support");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display);
  Py_DECREF(__pyx_v_display_source);
  return __pyx_r;
}

static PyObject *__pyx_n__ensure_XTest_support;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_key(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_key(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_keycode = 0;
  PyObject *__pyx_v_is_press = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  unsigned int __pyx_5;
  Bool __pyx_6;
  static char *__pyx_argnames[] = {"display_source","keycode","is_press",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_keycode, &__pyx_v_is_press)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_keycode);
  Py_INCREF(__pyx_v_is_press);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":745 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XTest_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 745; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 745; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 745; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":746 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 746; goto __pyx_L1;}
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_v_keycode); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 746; goto __pyx_L1;}
  __pyx_6 = PyInt_AsLong(__pyx_v_is_press); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 746; goto __pyx_L1;}
  XTestFakeKeyEvent(__pyx_4,__pyx_5,__pyx_6,0);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xtest_fake_key");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_keycode);
  Py_DECREF(__pyx_v_is_press);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_button(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_button(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_button = 0;
  PyObject *__pyx_v_is_press = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  unsigned int __pyx_5;
  Bool __pyx_6;
  static char *__pyx_argnames[] = {"display_source","button","is_press",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_button, &__pyx_v_is_press)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_button);
  Py_INCREF(__pyx_v_is_press);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":749 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XTest_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 749; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 749; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 749; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":750 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 750; goto __pyx_L1;}
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_v_button); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 750; goto __pyx_L1;}
  __pyx_6 = PyInt_AsLong(__pyx_v_is_press); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 750; goto __pyx_L1;}
  XTestFakeButtonEvent(__pyx_4,__pyx_5,__pyx_6,0);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xtest_fake_button");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_button);
  Py_DECREF(__pyx_v_is_press);
  return __pyx_r;
}

static PyObject *__pyx_k201p;
static PyObject *__pyx_k202p;
static PyObject *__pyx_k203p;
static PyObject *__pyx_k204p;
static PyObject *__pyx_k205p;

static char __pyx_k201[] = "-support";
static char __pyx_k202[] = "-event-base";
static char __pyx_k203[] = "%s v%s.%s not supported; required: v%s.%s";
static char __pyx_k204[] = "X server does not support required extension %s";
static char __pyx_k205[] = "insufficient %s support in server";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_extension_support(PyObject *__pyx_v_display_source,PyObject *__pyx_v_major,PyObject *__pyx_v_minor,PyObject *__pyx_v_extension,Bool (*__pyx_v_query_extension)(Display *,int *,int *),Status (*__pyx_v_query_version)(Display *,int *,int *)) {
  int __pyx_v_event_base;
  int __pyx_v_ignored;
  int __pyx_v_cmajor;
  int __pyx_v_cminor;
  PyObject *__pyx_v_display;
  PyObject *__pyx_v_key;
  PyObject *__pyx_v_event_key;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  Display *__pyx_5;
  Bool __pyx_6;
  Status __pyx_7;
  int __pyx_8;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_major);
  Py_INCREF(__pyx_v_minor);
  Py_INCREF(__pyx_v_extension);
  __pyx_v_display = Py_None; Py_INCREF(Py_None);
  __pyx_v_key = Py_None; Py_INCREF(Py_None);
  __pyx_v_event_key = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":768 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_display_for); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 768; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 768; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 768; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_display);
  __pyx_v_display = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":769 */
  __pyx_1 = PyNumber_Add(__pyx_v_extension, __pyx_k201p); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 769; goto __pyx_L1;}
  Py_DECREF(__pyx_v_key);
  __pyx_v_key = __pyx_1;
  __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":770 */
  __pyx_2 = PyNumber_Add(__pyx_v_extension, __pyx_k202p); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 770; goto __pyx_L1;}
  Py_DECREF(__pyx_v_event_key);
  __pyx_v_event_key = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":771 */
  __pyx_3 = PyObject_GetAttr(__pyx_v_display, __pyx_n_get_data); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 771; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 771; goto __pyx_L1;}
  Py_INCREF(__pyx_v_key);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_key);
  __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 771; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = __pyx_2 == Py_None;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_4) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":773 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_display, __pyx_n_set_data); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 773; goto __pyx_L1;}
    __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 773; goto __pyx_L1;}
    Py_INCREF(__pyx_v_key);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_key);
    Py_INCREF(Py_False);
    PyTuple_SET_ITEM(__pyx_1, 1, Py_False);
    __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 773; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":774 */
    __pyx_5 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display); if (__pyx_5 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 774; goto __pyx_L1;}
    __pyx_6 = __pyx_v_query_extension(__pyx_5,(&__pyx_v_event_base),(&__pyx_v_ignored));
    if (__pyx_6) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":776 */
      __pyx_3 = PyObject_GetAttr(__pyx_v_display, __pyx_n_set_data); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 776; goto __pyx_L1;}
      __pyx_1 = PyInt_FromLong(__pyx_v_event_base); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 776; goto __pyx_L1;}
      __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 776; goto __pyx_L1;}
      Py_INCREF(__pyx_v_event_key);
      PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_event_key);
      PyTuple_SET_ITEM(__pyx_2, 1, __pyx_1);
      __pyx_1 = 0;
      __pyx_1 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 776; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_1); __pyx_1 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":777 */
      __pyx_4 = PyInt_AsLong(__pyx_v_major); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 777; goto __pyx_L1;}
      __pyx_v_cmajor = __pyx_4;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":778 */
      __pyx_4 = PyInt_AsLong(__pyx_v_minor); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 778; goto __pyx_L1;}
      __pyx_v_cminor = __pyx_4;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":779 */
      __pyx_5 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display); if (__pyx_5 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 779; goto __pyx_L1;}
      __pyx_7 = __pyx_v_query_version(__pyx_5,(&__pyx_v_cmajor),(&__pyx_v_cminor));
      if (__pyx_7) {
        __pyx_3 = PyInt_FromLong(__pyx_v_cmajor); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 781; goto __pyx_L1;}
        if (PyObject_Cmp(__pyx_v_major, __pyx_3, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 781; goto __pyx_L1;}
        __pyx_4 = __pyx_4 == 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        if (__pyx_4) {
          __pyx_2 = PyInt_FromLong(__pyx_v_cminor); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 781; goto __pyx_L1;}
          if (PyObject_Cmp(__pyx_v_minor, __pyx_2, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 781; goto __pyx_L1;}
          __pyx_4 = __pyx_4 <= 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
        }
        if (__pyx_4) {
          __pyx_1 = PyObject_GetAttr(__pyx_v_display, __pyx_n_set_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 782; goto __pyx_L1;}
          __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 782; goto __pyx_L1;}
          Py_INCREF(__pyx_v_key);
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_key);
          Py_INCREF(Py_True);
          PyTuple_SET_ITEM(__pyx_3, 1, Py_True);
          __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 782; goto __pyx_L1;}
          Py_DECREF(__pyx_1); __pyx_1 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          goto __pyx_L5;
        }
        /*else*/ {
          __pyx_1 = PyInt_FromLong(__pyx_v_cmajor); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 785; goto __pyx_L1;}
          __pyx_3 = PyInt_FromLong(__pyx_v_cminor); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 785; goto __pyx_L1;}
          __pyx_2 = PyTuple_New(5); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 785; goto __pyx_L1;}
          Py_INCREF(__pyx_v_extension);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_extension);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_1);
          PyTuple_SET_ITEM(__pyx_2, 2, __pyx_3);
          Py_INCREF(__pyx_v_major);
          PyTuple_SET_ITEM(__pyx_2, 3, __pyx_v_major);
          Py_INCREF(__pyx_v_minor);
          PyTuple_SET_ITEM(__pyx_2, 4, __pyx_v_minor);
          __pyx_1 = 0;
          __pyx_3 = 0;
          __pyx_1 = PyNumber_Remainder(__pyx_k203p, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 785; goto __pyx_L1;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 784; goto __pyx_L1;}
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
          __pyx_1 = 0;
          __pyx_2 = PyObject_CallObject(PyExc_ValueError, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 784; goto __pyx_L1;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          __Pyx_Raise(__pyx_2, 0, 0);
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          {__pyx_filename = __pyx_f[0]; __pyx_lineno = 784; goto __pyx_L1;}
        }
        __pyx_L5:;
        goto __pyx_L4;
      }
      __pyx_L4:;
      goto __pyx_L3;
    }
    /*else*/ {
      __pyx_1 = PyNumber_Remainder(__pyx_k204p, __pyx_v_extension); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 788; goto __pyx_L1;}
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 787; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
      __pyx_1 = 0;
      __pyx_2 = PyObject_CallObject(PyExc_ValueError, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 787; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __Pyx_Raise(__pyx_2, 0, 0);
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 787; goto __pyx_L1;}
    }
    __pyx_L3:;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":789 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_display, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 789; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 789; goto __pyx_L1;}
  Py_INCREF(__pyx_v_key);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_key);
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 789; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_4 = PyObject_IsTrue(__pyx_2); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 789; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_8 = (!__pyx_4);
  if (__pyx_8) {
    __pyx_1 = PyNumber_Remainder(__pyx_k205p, __pyx_v_extension); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 790; goto __pyx_L1;}
    __Pyx_Raise(PyExc_ValueError, __pyx_1, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 790; goto __pyx_L1;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._ensure_extension_support");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display);
  Py_DECREF(__pyx_v_key);
  Py_DECREF(__pyx_v_event_key);
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_major);
  Py_DECREF(__pyx_v_minor);
  Py_DECREF(__pyx_v_extension);
  return __pyx_r;
}

static PyObject *__pyx_n_Composite;


static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XComposite_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XComposite_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"display_source",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_display_source)) return 0;
  Py_INCREF(__pyx_v_display_source);
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 814; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 814; goto __pyx_L1;}
  __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_extension_support(__pyx_v_display_source,__pyx_1,__pyx_2,__pyx_n_Composite,XCompositeQueryExtension,XCompositeQueryVersion); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 814; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._ensure_XComposite_support");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  return __pyx_r;
}

static PyObject *__pyx_n__ensure_XComposite_support;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_window(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_window(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":819 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XComposite_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 819; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":820 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 820; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  XCompositeRedirectWindow(__pyx_4,__pyx_5,CompositeRedirectManual);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xcomposite_redirect_window");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_subwindows(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_subwindows(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":824 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XComposite_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 824; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 824; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 824; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":825 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 825; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  XCompositeRedirectSubwindows(__pyx_4,__pyx_5,CompositeRedirectManual);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xcomposite_redirect_subwindows");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_window(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_window(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":829 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XComposite_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 829; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 829; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 829; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":830 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 830; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 830; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 830; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 830; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 830; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  XCompositeUnredirectWindow(__pyx_4,__pyx_5,CompositeRedirectManual);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xcomposite_unredirect_window");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_subwindows(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_subwindows(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":834 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XComposite_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 834; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 834; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 834; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":835 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 835; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  XCompositeUnredirectSubwindows(__pyx_4,__pyx_5,CompositeRedirectManual);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xcomposite_unredirect_subwindows");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_n_pixmap;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___init__ = {"__init__", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pixmap = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"self","pixmap",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_self, &__pyx_v_pixmap)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_pixmap);
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_pixmap, __pyx_v_pixmap) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 841; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._PixmapCleanupHandler.__init__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_pixmap);
  return __pyx_r;
}

static PyObject *__pyx_n_xid;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___del__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___del__ = {"__del__", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___del__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___del__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  Display *__pyx_3;
  PyObject *__pyx_4 = 0;
  Pixmap __pyx_5;
  static char *__pyx_argnames[] = {"self",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_self)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_pixmap); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 844; goto __pyx_L1;}
  __pyx_2 = __pyx_1 != Py_None;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":845 */
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_pixmap); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_1); if (__pyx_3 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_pixmap); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    __pyx_4 = PyObject_GetAttr(__pyx_1, __pyx_n_xid); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 845; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    XFreePixmap(__pyx_3,__pyx_5);

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":846 */
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_pixmap, Py_None) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 846; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._PixmapCleanupHandler.__del__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_pixmap_foreign_new_for_display;
static PyObject *__pyx_n_set_colormap;
static PyObject *__pyx_n_get_colormap;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_name_window_pixmap(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_name_window_pixmap(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_v_xpixmap;
  PyObject *__pyx_v_gpixmap;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Window __pyx_5;
  PyObject *__pyx_6 = 0;
  int __pyx_7;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);
  __pyx_v_xpixmap = Py_None; Py_INCREF(Py_None);
  __pyx_v_gpixmap = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":849 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XComposite_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 849; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":850 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 850; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 851; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 851; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 851; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 851; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(XCompositeNameWindowPixmap(__pyx_4,__pyx_5)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 850; goto __pyx_L1;}
  Py_DECREF(__pyx_v_xpixmap);
  __pyx_v_xpixmap = __pyx_1;
  __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":852 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_2, __pyx_n_gdk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_3, __pyx_n_pixmap_foreign_new_for_display); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_display_for); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_window);
  __pyx_6 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_6);
  Py_INCREF(__pyx_v_xpixmap);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_xpixmap);
  __pyx_6 = 0;
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 852; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_gpixmap);
  __pyx_v_gpixmap = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":854 */
  __pyx_7 = __pyx_v_gpixmap == Py_None;
  if (__pyx_7) {
    Py_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":862 */
    __pyx_6 = PyObject_GetAttr(__pyx_v_gpixmap, __pyx_n_set_colormap); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 862; goto __pyx_L1;}
    __pyx_1 = PyObject_GetAttr(__pyx_v_window, __pyx_n_get_colormap); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 862; goto __pyx_L1;}
    __pyx_2 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 862; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 862; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
    __pyx_2 = 0;
    __pyx_1 = PyObject_CallObject(__pyx_6, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 862; goto __pyx_L1;}
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":863 */
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__PixmapCleanupHandler); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 863; goto __pyx_L1;}
    __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 863; goto __pyx_L1;}
    Py_INCREF(__pyx_v_gpixmap);
    PyTuple_SET_ITEM(__pyx_6, 0, __pyx_v_gpixmap);
    __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_6); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 863; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    __pyx_r = __pyx_3;
    __pyx_3 = 0;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xcomposite_name_window_pixmap");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_xpixmap);
  Py_DECREF(__pyx_v_gpixmap);
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_n_DAMAGE;


static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XDamage_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XDamage_support(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"display_source",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_display_source)) return 0;
  Py_INCREF(__pyx_v_display_source);
  __pyx_1 = PyInt_FromLong(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 897; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 897; goto __pyx_L1;}
  __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_extension_support(__pyx_v_display_source,__pyx_1,__pyx_2,__pyx_n_DAMAGE,XDamageQueryExtension,XDamageQueryVersion); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 897; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._ensure_XDamage_support");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  return __pyx_r;
}

static PyObject *__pyx_n__ensure_XDamage_support;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_start(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_start(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Drawable __pyx_5;
  static char *__pyx_argnames[] = {"window",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_window)) return 0;
  Py_INCREF(__pyx_v_window);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":902 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XDamage_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 902; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 902; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 902; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":903 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_window); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  Py_INCREF(__pyx_v_window);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_window);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(XDamageCreate(__pyx_4,__pyx_5,XDamageReportDeltaRectangles)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 903; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xdamage_start");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_window);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_stop(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_stop(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_handle = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  Display *__pyx_4;
  Damage __pyx_5;
  static char *__pyx_argnames[] = {"display_source","handle",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_handle)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_handle);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":907 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ensure_XDamage_support); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 907; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 907; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_display_source);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 907; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":908 */
  __pyx_4 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_4 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 908; goto __pyx_L1;}
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_v_handle); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 908; goto __pyx_L1;}
  XDamageDestroy(__pyx_4,__pyx_5);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xdamage_stop");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_handle);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_acknowledge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_acknowledge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_handle = 0;
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_width = 0;
  PyObject *__pyx_v_height = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  Damage __pyx_2;
  static char *__pyx_argnames[] = {"display_source","handle","x","y","width","height",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOOOO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_handle, &__pyx_v_x, &__pyx_v_y, &__pyx_v_width, &__pyx_v_height)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_handle);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_width);
  Py_INCREF(__pyx_v_height);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 931; goto __pyx_L1;}
  __pyx_2 = PyInt_AsUnsignedLongMask(__pyx_v_handle); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 931; goto __pyx_L1;}
  XDamageSubtract(__pyx_1,__pyx_2,None,None);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.xdamage_acknowledge");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_handle);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_width);
  Py_DECREF(__pyx_v_height);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_myGetSelectionOwner(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_myGetSelectionOwner(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display_source = 0;
  PyObject *__pyx_v_pyatom = 0;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Atom __pyx_5;
  static char *__pyx_argnames[] = {"display_source","pyatom",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display_source, &__pyx_v_pyatom)) return 0;
  Py_INCREF(__pyx_v_display_source);
  Py_INCREF(__pyx_v_pyatom);
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_display_source); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 938; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display_source);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_display_source);
  Py_INCREF(__pyx_v_pyatom);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_pyatom);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 939; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(XGetSelectionOwner(__pyx_1,__pyx_5)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 938; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.myGetSelectionOwner");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display_source);
  Py_DECREF(__pyx_v_pyatom);
  return __pyx_r;
}

static PyObject *__pyx_k208p;
static PyObject *__pyx_k209p;

static char __pyx_k208[] = "sending message to %s";
static char __pyx_k209[] = "failed to serialize ClientMessage";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_sendClientMessage(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_sendClientMessage(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_target = 0;
  PyObject *__pyx_v_propagate = 0;
  PyObject *__pyx_v_event_mask = 0;
  PyObject *__pyx_v_message_type = 0;
  PyObject *__pyx_v_data0 = 0;
  PyObject *__pyx_v_data1 = 0;
  PyObject *__pyx_v_data2 = 0;
  PyObject *__pyx_v_data3 = 0;
  PyObject *__pyx_v_data4 = 0;
  Display *__pyx_v_display;
  Window __pyx_v_w;
  XEvent __pyx_v_e;
  Status __pyx_v_s;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  PyObject *__pyx_6 = 0;
  Atom __pyx_7;
  long __pyx_8;
  Bool __pyx_9;
  int __pyx_10;
  static char *__pyx_argnames[] = {"target","propagate","event_mask","message_type","data0","data1","data2","data3","data4",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOOOOOOO", __pyx_argnames, &__pyx_v_target, &__pyx_v_propagate, &__pyx_v_event_mask, &__pyx_v_message_type, &__pyx_v_data0, &__pyx_v_data1, &__pyx_v_data2, &__pyx_v_data3, &__pyx_v_data4)) return 0;
  Py_INCREF(__pyx_v_target);
  Py_INCREF(__pyx_v_propagate);
  Py_INCREF(__pyx_v_event_mask);
  Py_INCREF(__pyx_v_message_type);
  Py_INCREF(__pyx_v_data0);
  Py_INCREF(__pyx_v_data1);
  Py_INCREF(__pyx_v_data2);
  Py_INCREF(__pyx_v_data3);
  Py_INCREF(__pyx_v_data4);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":947 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_target); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 947; goto __pyx_L1;}
  __pyx_v_display = __pyx_1;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":949 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 949; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 949; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_target);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 949; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 949; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_v_w = __pyx_5;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":950 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_b, __pyx_n_hex); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_w); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_6, 0, __pyx_4);
  __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_6); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  Py_INCREF(__pyx_k208p);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k208p);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_4);
  __pyx_4 = 0;
  __pyx_6 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 950; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_6); __pyx_6 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":952 */
  __pyx_v_e.type = ClientMessage;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":953 */
  __pyx_v_e.xany.display = __pyx_v_display;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":954 */
  __pyx_v_e.xany.window = __pyx_v_w;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":955 */
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 955; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 955; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_message_type);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_message_type);
  __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 955; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_7 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 955; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_v_e.xclient.message_type = __pyx_7;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":956 */
  __pyx_v_e.xclient.format = 32;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":957 */
  __pyx_6 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_data0);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_data0);
  __pyx_2 = PyObject_CallObject(__pyx_6, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_8 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 957; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  (__pyx_v_e.xclient.data.l[0]) = __pyx_8;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":958 */
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 958; goto __pyx_L1;}
  __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 958; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_6, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_data1);
  PyTuple_SET_ITEM(__pyx_6, 1, __pyx_v_data1);
  __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_6); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 958; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  __pyx_8 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 958; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  (__pyx_v_e.xclient.data.l[1]) = __pyx_8;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":959 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 959; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 959; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_data2);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_data2);
  __pyx_6 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 959; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_8 = PyInt_AsLong(__pyx_6); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 959; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  (__pyx_v_e.xclient.data.l[2]) = __pyx_8;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":960 */
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 960; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 960; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_data3);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_data3);
  __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 960; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_8 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 960; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  (__pyx_v_e.xclient.data.l[3]) = __pyx_8;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":961 */
  __pyx_6 = __Pyx_GetName(__pyx_m, __pyx_n_get_xatom); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 961; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 961; goto __pyx_L1;}
  Py_INCREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_target);
  Py_INCREF(__pyx_v_data4);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_data4);
  __pyx_2 = PyObject_CallObject(__pyx_6, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 961; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_8 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 961; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  (__pyx_v_e.xclient.data.l[4]) = __pyx_8;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":963 */
  __pyx_9 = PyInt_AsLong(__pyx_v_propagate); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 963; goto __pyx_L1;}
  __pyx_8 = PyInt_AsLong(__pyx_v_event_mask); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 963; goto __pyx_L1;}
  __pyx_v_s = XSendEvent(__pyx_v_display,__pyx_v_w,__pyx_9,__pyx_8,(&__pyx_v_e));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":964 */
  __pyx_10 = (__pyx_v_s == 0);
  if (__pyx_10) {
    __Pyx_Raise(PyExc_ValueError, __pyx_k209p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 965; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_6);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.sendClientMessage");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_target);
  Py_DECREF(__pyx_v_propagate);
  Py_DECREF(__pyx_v_event_mask);
  Py_DECREF(__pyx_v_message_type);
  Py_DECREF(__pyx_v_data0);
  Py_DECREF(__pyx_v_data1);
  Py_DECREF(__pyx_v_data2);
  Py_DECREF(__pyx_v_data3);
  Py_DECREF(__pyx_v_data4);
  return __pyx_r;
}

static PyObject *__pyx_n_get_default_root_window;

static PyObject *__pyx_k210p;
static PyObject *__pyx_k211p;

static char __pyx_k210[] = "couldn't TranslateCoordinates (maybe window is gone)";
static char __pyx_k211[] = "failed to serialize ConfigureNotify";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_sendConfigureNotify(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_sendConfigureNotify(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  Display *__pyx_v_display;
  Window __pyx_v_window;
  XWindowAttributes __pyx_v_attrs;
  int __pyx_v_dest_x;
  int __pyx_v_dest_y;
  Window __pyx_v_child;
  XEvent __pyx_v_e;
  Status __pyx_v_s;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  int __pyx_6;
  Bool __pyx_7;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":969 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 969; goto __pyx_L1;}
  __pyx_v_display = __pyx_1;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":971 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 971; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 971; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 971; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 971; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_v_window = __pyx_5;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":975 */
  XGetWindowAttributes(__pyx_v_display,__pyx_v_window,(&__pyx_v_attrs));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":980 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  __pyx_4 = PyObject_GetAttr(__pyx_3, __pyx_n_gdk); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyObject_GetAttr(__pyx_4, __pyx_n_get_default_root_window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_3, 0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_4);
  __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 981; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_6 = (!XTranslateCoordinates(__pyx_v_display,__pyx_v_window,__pyx_5,0,0,(&__pyx_v_dest_x),(&__pyx_v_dest_y),(&__pyx_v_child)));
  if (__pyx_6) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":985 */
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 985; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 985; goto __pyx_L1;}
    Py_INCREF(__pyx_k210p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k210p);
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 985; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":986 */
    __pyx_r = Py_None; Py_INCREF(Py_None);
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":990 */
  __pyx_v_e.type = ConfigureNotify;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":991 */
  __pyx_v_e.xconfigure.event = __pyx_v_window;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":992 */
  __pyx_v_e.xconfigure.window = __pyx_v_window;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":993 */
  __pyx_v_e.xconfigure.x = __pyx_v_dest_x;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":994 */
  __pyx_v_e.xconfigure.y = __pyx_v_dest_y;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":995 */
  __pyx_v_e.xconfigure.width = __pyx_v_attrs.width;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":996 */
  __pyx_v_e.xconfigure.height = __pyx_v_attrs.height;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":997 */
  __pyx_v_e.xconfigure.border_width = __pyx_v_attrs.border_width;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":998 */
  __pyx_v_e.xconfigure.above = None;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":999 */
  __pyx_v_e.xconfigure.override_redirect = __pyx_v_attrs.override_redirect;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1002 */
  __pyx_7 = PyInt_AsLong(Py_False); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1002; goto __pyx_L1;}
  __pyx_v_s = XSendEvent(__pyx_v_display,__pyx_v_window,__pyx_7,StructureNotifyMask,(&__pyx_v_e));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1003 */
  __pyx_6 = (__pyx_v_s == 0);
  if (__pyx_6) {
    __Pyx_Raise(PyExc_ValueError, __pyx_k211p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1004; goto __pyx_L1;}
    goto __pyx_L3;
  }
  __pyx_L3:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.sendConfigureNotify");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_sendConfigureNotify;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_configureAndNotify(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_configureAndNotify(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_width = 0;
  PyObject *__pyx_v_height = 0;
  PyObject *__pyx_v_fields = 0;
  Display *__pyx_v_display;
  Window __pyx_v_window;
  PyObject *__pyx_v_all_optional_fields_we_know;
  XWindowChanges __pyx_v_changes;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  int __pyx_6;
  unsigned int __pyx_7;
  static char *__pyx_argnames[] = {"pywindow","x","y","width","height","fields",0};
  __pyx_v_fields = __pyx_k164;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOOOO|O", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_x, &__pyx_v_y, &__pyx_v_width, &__pyx_v_height, &__pyx_v_fields)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_x);
  Py_INCREF(__pyx_v_y);
  Py_INCREF(__pyx_v_width);
  Py_INCREF(__pyx_v_height);
  Py_INCREF(__pyx_v_fields);
  __pyx_v_all_optional_fields_we_know = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1008 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1008; goto __pyx_L1;}
  __pyx_v_display = __pyx_1;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1010 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1010; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1010; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1010; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1010; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_v_window = __pyx_5;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1021 */
  __pyx_2 = PyLong_FromUnsignedLong((((CWX | CWY) | CWWidth) | CWHeight)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1021; goto __pyx_L1;}
  Py_DECREF(__pyx_v_all_optional_fields_we_know);
  __pyx_v_all_optional_fields_we_know = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1022 */
  __pyx_6 = __pyx_v_fields == Py_None;
  if (__pyx_6) {
    Py_INCREF(__pyx_v_all_optional_fields_we_know);
    Py_DECREF(__pyx_v_fields);
    __pyx_v_fields = __pyx_v_all_optional_fields_we_know;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_3 = PyNumber_And(__pyx_v_fields, __pyx_v_all_optional_fields_we_know); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1025; goto __pyx_L1;}
    Py_DECREF(__pyx_v_fields);
    __pyx_v_fields = __pyx_3;
    __pyx_3 = 0;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1027 */
  __pyx_4 = PyLong_FromUnsignedLong(CWBorderWidth); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1027; goto __pyx_L1;}
  __pyx_2 = PyNumber_Or(__pyx_v_fields, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1027; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_v_fields);
  __pyx_v_fields = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1030 */
  __pyx_6 = PyInt_AsLong(__pyx_v_x); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1030; goto __pyx_L1;}
  __pyx_v_changes.x = __pyx_6;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1031 */
  __pyx_6 = PyInt_AsLong(__pyx_v_y); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1031; goto __pyx_L1;}
  __pyx_v_changes.y = __pyx_6;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1032 */
  __pyx_6 = PyInt_AsLong(__pyx_v_width); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1032; goto __pyx_L1;}
  __pyx_v_changes.width = __pyx_6;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1033 */
  __pyx_6 = PyInt_AsLong(__pyx_v_height); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1033; goto __pyx_L1;}
  __pyx_v_changes.height = __pyx_6;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1034 */
  __pyx_v_changes.border_width = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1035 */
  __pyx_7 = PyInt_AsUnsignedLongMask(__pyx_v_fields); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1035; goto __pyx_L1;}
  XConfigureWindow(__pyx_v_display,__pyx_v_window,__pyx_7,(&__pyx_v_changes));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1037 */
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_sendConfigureNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1037; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1037; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_pywindow);
  __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1037; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.configureAndNotify");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_all_optional_fields_we_know);
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_y);
  Py_DECREF(__pyx_v_width);
  Py_DECREF(__pyx_v_height);
  Py_DECREF(__pyx_v_fields);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_addXSelectInput(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_addXSelectInput(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_v_add_mask = 0;
  XWindowAttributes __pyx_v_curr;
  PyObject *__pyx_v_mask;
  PyObject *__pyx_r;
  Display *__pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  Window __pyx_5;
  long __pyx_6;
  static char *__pyx_argnames[] = {"pywindow","add_mask",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_pywindow, &__pyx_v_add_mask)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  Py_INCREF(__pyx_v_add_mask);
  __pyx_v_mask = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1098 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1098; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1099; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1099; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1099; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1099; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  XGetWindowAttributes(__pyx_1,__pyx_5,(&__pyx_v_curr));

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1101 */
  __pyx_2 = PyInt_FromLong(__pyx_v_curr.your_event_mask); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1101; goto __pyx_L1;}
  Py_DECREF(__pyx_v_mask);
  __pyx_v_mask = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1102 */
  __pyx_3 = PyNumber_Or(__pyx_v_mask, __pyx_v_add_mask); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1102; goto __pyx_L1;}
  Py_DECREF(__pyx_v_mask);
  __pyx_v_mask = __pyx_3;
  __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1103 */
  __pyx_1 = __pyx_f_8wimpiggy_8lowlevel_8bindings_get_xdisplay_for(__pyx_v_pywindow); if (__pyx_1 == NULL && PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1103; goto __pyx_L1;}
  __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_get_xwindow); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1104; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1104; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pywindow);
  __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1104; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_5 = PyInt_AsUnsignedLongMask(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1104; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_6 = PyInt_AsLong(__pyx_v_mask); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1105; goto __pyx_L1;}
  XSelectInput(__pyx_1,__pyx_5,__pyx_6);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.addXSelectInput");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_mask);
  Py_DECREF(__pyx_v_pywindow);
  Py_DECREF(__pyx_v_add_mask);
  return __pyx_r;
}

static PyObject *__pyx_n_addXSelectInput;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_substructureRedirect(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_8wimpiggy_8lowlevel_8bindings_substructureRedirect[] = "Enable SubstructureRedirect on the given window.\n\n    This enables reception of MapRequest and ConfigureRequest events.  At the\n    X level, it also enables the reception of CirculateRequest events, but\n    those are pretty useless, so we just ignore such events unconditionally\n    rather than routing them anywhere.  (The circulate request appears to be\n    in the protocol just so simple window managers have an easy way to\n    implement the equivalent of alt-tab; I can\'t imagine how it\'d be useful\n    these days.  Metacity and KWin do not support it; GTK+/GDK and Qt4 provide\n    no way to actually send it.)";
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_substructureRedirect(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_addXSelectInput); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; goto __pyx_L1;}
  __pyx_2 = PyLong_FromUnsignedLong(SubstructureRedirectMask); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.substructureRedirect");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_selectFocusChange(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_selectFocusChange(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_pywindow = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"pywindow",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_pywindow)) return 0;
  Py_INCREF(__pyx_v_pywindow);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_addXSelectInput); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1121; goto __pyx_L1;}
  __pyx_2 = PyLong_FromUnsignedLong(FocusChangeMask); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1121; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1121; goto __pyx_L1;}
  Py_INCREF(__pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_pywindow);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1121; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.selectFocusChange");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_pywindow);
  return __pyx_r;
}

static PyObject *__pyx_n_set;
static PyObject *__pyx_n_add;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_add_event_receiver(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_add_event_receiver(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_v_receiver = 0;
  PyObject *__pyx_v_receivers;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  static char *__pyx_argnames[] = {"window","receiver",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_window, &__pyx_v_receiver)) return 0;
  Py_INCREF(__pyx_v_window);
  Py_INCREF(__pyx_v_receiver);
  __pyx_v_receivers = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1130 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_window, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__ev_receiver_key); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_receivers);
  __pyx_v_receivers = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1131 */
  __pyx_4 = __pyx_v_receivers == Py_None;
  if (__pyx_4) {
    __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_set); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1132; goto __pyx_L1;}
    __pyx_3 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1132; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_v_receivers);
    __pyx_v_receivers = __pyx_3;
    __pyx_3 = 0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1133 */
  __pyx_4 = PySequence_Contains(__pyx_v_receivers, __pyx_v_receiver); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1133; goto __pyx_L1;}
  __pyx_4 = !__pyx_4;
  if (__pyx_4) {
    __pyx_2 = PyObject_GetAttr(__pyx_v_receivers, __pyx_n_add); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; goto __pyx_L1;}
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; goto __pyx_L1;}
    Py_INCREF(__pyx_v_receiver);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_receiver);
    __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1135 */
  __pyx_2 = PyObject_GetAttr(__pyx_v_window, __pyx_n_set_data); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1135; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n__ev_receiver_key); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1135; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1135; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  Py_INCREF(__pyx_v_receivers);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_receivers);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1135; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.add_event_receiver");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_receivers);
  Py_DECREF(__pyx_v_window);
  Py_DECREF(__pyx_v_receiver);
  return __pyx_r;
}

static PyObject *__pyx_n_discard;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_remove_event_receiver(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings_remove_event_receiver(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_v_receiver = 0;
  PyObject *__pyx_v_receivers;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  int __pyx_5;
  static char *__pyx_argnames[] = {"window","receiver",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_window, &__pyx_v_receiver)) return 0;
  Py_INCREF(__pyx_v_window);
  Py_INCREF(__pyx_v_receiver);
  __pyx_v_receivers = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1138 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_window, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1138; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__ev_receiver_key); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1138; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1138; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1138; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_receivers);
  __pyx_v_receivers = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1139 */
  __pyx_4 = __pyx_v_receivers == Py_None;
  if (__pyx_4) {
    __pyx_r = Py_None; Py_INCREF(Py_None);
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1141 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_receivers, __pyx_n_discard); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1141; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1141; goto __pyx_L1;}
  Py_INCREF(__pyx_v_receiver);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_receiver);
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1141; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1142 */
  __pyx_4 = PyObject_IsTrue(__pyx_v_receivers); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1142; goto __pyx_L1;}
  __pyx_5 = (!__pyx_4);
  if (__pyx_5) {
    Py_INCREF(Py_None);
    Py_DECREF(__pyx_v_receivers);
    __pyx_v_receivers = Py_None;
    goto __pyx_L3;
  }
  __pyx_L3:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1144 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_window, __pyx_n_set_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1144; goto __pyx_L1;}
  __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__ev_receiver_key); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1144; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1144; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
  Py_INCREF(__pyx_v_receivers);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_receivers);
  __pyx_3 = 0;
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.remove_event_receiver");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_receivers);
  Py_DECREF(__pyx_v_window);
  Py_DECREF(__pyx_v_receiver);
  return __pyx_r;
}

static PyObject *__pyx_n_signal_list_names;
static PyObject *__pyx_n___name__;
static PyObject *__pyx_n_emit;

static PyObject *__pyx_k212p;
static PyObject *__pyx_k213p;
static PyObject *__pyx_k214p;
static PyObject *__pyx_k215p;

static char __pyx_k212[] = "  forwarding event to a %s handler's %s signal";
static char __pyx_k213[] = "  forwarded";
static char __pyx_k214[] = "  not forwarding to %s handler, it has no %s signal";
static char __pyx_k215[] = "  no handler registered for this window, ignoring event";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__maybe_send_event(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__maybe_send_event(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_window = 0;
  PyObject *__pyx_v_signal = 0;
  PyObject *__pyx_v_event = 0;
  PyObject *__pyx_v_handlers;
  PyObject *__pyx_v_handler;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"window","signal","event",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_window, &__pyx_v_signal, &__pyx_v_event)) return 0;
  Py_INCREF(__pyx_v_window);
  Py_INCREF(__pyx_v_signal);
  Py_INCREF(__pyx_v_event);
  __pyx_v_handlers = Py_None; Py_INCREF(Py_None);
  __pyx_v_handler = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1147 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_window, __pyx_n_get_data); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1147; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__ev_receiver_key); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1147; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1147; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1147; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_v_handlers);
  __pyx_v_handlers = __pyx_2;
  __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1148 */
  __pyx_4 = __pyx_v_handlers != Py_None;
  if (__pyx_4) {
    __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1151; goto __pyx_L1;}
    Py_INCREF(__pyx_v_handlers);
    PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_handlers);
    __pyx_3 = PyObject_CallObject(((PyObject *)(&PyList_Type)), __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1151; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __pyx_2 = PyObject_GetIter(__pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1151; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    for (;;) {
      __pyx_1 = PyIter_Next(__pyx_2);
      if (!__pyx_1) {
        if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1151; goto __pyx_L1;}
        break;
      }
      Py_DECREF(__pyx_v_handler);
      __pyx_v_handler = __pyx_1;
      __pyx_1 = 0;
      __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gobject); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1152; goto __pyx_L1;}
      __pyx_1 = PyObject_GetAttr(__pyx_3, __pyx_n_signal_list_names); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1152; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1152; goto __pyx_L1;}
      Py_INCREF(__pyx_v_handler);
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_handler);
      __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1152; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_4 = PySequence_Contains(__pyx_5, __pyx_v_signal); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1152; goto __pyx_L1;}
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      if (__pyx_4) {

        /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1153 */
        __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1153; goto __pyx_L1;}
        __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1154; goto __pyx_L1;}
        Py_INCREF(__pyx_v_handler);
        PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_handler);
        __pyx_5 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1154; goto __pyx_L1;}
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        __pyx_3 = PyObject_GetAttr(__pyx_5, __pyx_n___name__); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1154; goto __pyx_L1;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        __pyx_5 = PyTuple_New(3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1153; goto __pyx_L1;}
        Py_INCREF(__pyx_k212p);
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k212p);
        PyTuple_SET_ITEM(__pyx_5, 1, __pyx_3);
        Py_INCREF(__pyx_v_signal);
        PyTuple_SET_ITEM(__pyx_5, 2, __pyx_v_signal);
        __pyx_3 = 0;
        __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1153; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;

        /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1155 */
        __pyx_1 = PyObject_GetAttr(__pyx_v_handler, __pyx_n_emit); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1155; goto __pyx_L1;}
        __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1155; goto __pyx_L1;}
        Py_INCREF(__pyx_v_signal);
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_signal);
        Py_INCREF(__pyx_v_event);
        PyTuple_SET_ITEM(__pyx_5, 1, __pyx_v_event);
        __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1155; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;

        /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1156 */
        __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1156; goto __pyx_L1;}
        __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1156; goto __pyx_L1;}
        Py_INCREF(__pyx_k213p);
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k213p);
        __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1156; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        goto __pyx_L5;
      }
      /*else*/ {
        __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1158; goto __pyx_L1;}
        __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1159; goto __pyx_L1;}
        Py_INCREF(__pyx_v_handler);
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_handler);
        __pyx_3 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1159; goto __pyx_L1;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        __pyx_5 = PyObject_GetAttr(__pyx_3, __pyx_n___name__); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1159; goto __pyx_L1;}
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        __pyx_3 = PyTuple_New(3); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1158; goto __pyx_L1;}
        Py_INCREF(__pyx_k214p);
        PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k214p);
        PyTuple_SET_ITEM(__pyx_3, 1, __pyx_5);
        Py_INCREF(__pyx_v_signal);
        PyTuple_SET_ITEM(__pyx_3, 2, __pyx_v_signal);
        __pyx_5 = 0;
        __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1158; goto __pyx_L1;}
        Py_DECREF(__pyx_1); __pyx_1 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
      }
      __pyx_L5:;
    }
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1161; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1161; goto __pyx_L1;}
    Py_INCREF(__pyx_k215p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k215p);
    __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1161; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._maybe_send_event");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_handlers);
  Py_DECREF(__pyx_v_handler);
  Py_DECREF(__pyx_v_window);
  Py_DECREF(__pyx_v_signal);
  Py_DECREF(__pyx_v_event);
  return __pyx_r;
}

static PyObject *__pyx_n_window;
static PyObject *__pyx_n_type;
static PyObject *__pyx_n_UNMAP;
static PyObject *__pyx_n_DESTROY;
static PyObject *__pyx_n_delivered_to;
static PyObject *__pyx_n__maybe_send_event;

static PyObject *__pyx_k216p;
static PyObject *__pyx_k217p;
static PyObject *__pyx_k218p;
static PyObject *__pyx_k219p;
static PyObject *__pyx_k220p;

static char __pyx_k216[] = "  event.window is None, ignoring";
static char __pyx_k217[] = "  event was delivered to window itself";
static char __pyx_k218[] = "  received event on window itself but have no signal for that";
static char __pyx_k219[] = "  event was delivered to parent window";
static char __pyx_k220[] = "  received event on a parent window but have no parent signal";

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__route_event(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__route_event(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_event = 0;
  PyObject *__pyx_v_signal = 0;
  PyObject *__pyx_v_parent_signal = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"event","signal","parent_signal",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OOO", __pyx_argnames, &__pyx_v_event, &__pyx_v_signal, &__pyx_v_parent_signal)) return 0;
  Py_INCREF(__pyx_v_event);
  Py_INCREF(__pyx_v_signal);
  Py_INCREF(__pyx_v_parent_signal);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1169 */
  __pyx_1 = PyObject_GetAttr(__pyx_v_event, __pyx_n_window); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1169; goto __pyx_L1;}
  __pyx_2 = __pyx_1 == Py_None;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1170 */
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1170; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1170; goto __pyx_L1;}
    Py_INCREF(__pyx_k216p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k216p);
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1170; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1171 */
    #ifndef PYREX_WITHOUT_ASSERTIONS
    __pyx_1 = PyObject_GetAttr(__pyx_v_event, __pyx_n_type); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    __pyx_4 = PyObject_GetAttr(__pyx_3, __pyx_n_gdk); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __pyx_3 = PyObject_GetAttr(__pyx_4, __pyx_n_UNMAP); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_gtk); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    __pyx_5 = PyObject_GetAttr(__pyx_4, __pyx_n_gdk); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_4 = PyObject_GetAttr(__pyx_5, __pyx_n_DESTROY); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
    PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
    __pyx_3 = 0;
    __pyx_4 = 0;
    __pyx_2 = PySequence_Contains(__pyx_5, __pyx_1); if (__pyx_2 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    if (!__pyx_2) {
      PyErr_SetNone(PyExc_AssertionError);
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1171; goto __pyx_L1;}
    }
    #endif

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1172 */
    __pyx_r = Py_None; Py_INCREF(Py_None);
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1173 */
  __pyx_3 = PyObject_GetAttr(__pyx_v_event, __pyx_n_window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1173; goto __pyx_L1;}
  __pyx_4 = PyObject_GetAttr(__pyx_v_event, __pyx_n_delivered_to); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1173; goto __pyx_L1;}
  __pyx_2 = __pyx_3 == __pyx_4;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (__pyx_2) {
    __pyx_2 = __pyx_v_signal != Py_None;
    if (__pyx_2) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1175 */
      __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1175; goto __pyx_L1;}
      __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1175; goto __pyx_L1;}
      Py_INCREF(__pyx_k217p);
      PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k217p);
      __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1175; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1176 */
      __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__maybe_send_event); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1176; goto __pyx_L1;}
      __pyx_1 = PyObject_GetAttr(__pyx_v_event, __pyx_n_window); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1176; goto __pyx_L1;}
      __pyx_5 = PyTuple_New(3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1176; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_5, 0, __pyx_1);
      Py_INCREF(__pyx_v_signal);
      PyTuple_SET_ITEM(__pyx_5, 1, __pyx_v_signal);
      Py_INCREF(__pyx_v_event);
      PyTuple_SET_ITEM(__pyx_5, 2, __pyx_v_event);
      __pyx_1 = 0;
      __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1176; goto __pyx_L1;}
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      goto __pyx_L4;
    }
    /*else*/ {
      __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1178; goto __pyx_L1;}
      __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1178; goto __pyx_L1;}
      Py_INCREF(__pyx_k218p);
      PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k218p);
      __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1178; goto __pyx_L1;}
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_5); __pyx_5 = 0;
    }
    __pyx_L4:;
    goto __pyx_L3;
  }
  /*else*/ {
    __pyx_2 = __pyx_v_parent_signal != Py_None;
    if (__pyx_2) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1181 */
      __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1181; goto __pyx_L1;}
      __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1181; goto __pyx_L1;}
      Py_INCREF(__pyx_k219p);
      PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k219p);
      __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1181; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1182 */
      __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n__maybe_send_event); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1182; goto __pyx_L1;}
      __pyx_3 = PyObject_GetAttr(__pyx_v_event, __pyx_n_delivered_to); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1182; goto __pyx_L1;}
      __pyx_1 = PyTuple_New(3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1182; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
      Py_INCREF(__pyx_v_parent_signal);
      PyTuple_SET_ITEM(__pyx_1, 1, __pyx_v_parent_signal);
      Py_INCREF(__pyx_v_event);
      PyTuple_SET_ITEM(__pyx_1, 2, __pyx_v_event);
      __pyx_3 = 0;
      __pyx_4 = PyObject_CallObject(__pyx_5, __pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1182; goto __pyx_L1;}
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_1); __pyx_1 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      goto __pyx_L5;
    }
    /*else*/ {
      __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1184; goto __pyx_L1;}
      __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1184; goto __pyx_L1;}
      Py_INCREF(__pyx_k220p);
      PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k220p);
      __pyx_1 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1184; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_1); __pyx_1 = 0;
    }
    __pyx_L5:;
  }
  __pyx_L3:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._route_event");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_event);
  Py_DECREF(__pyx_v_signal);
  Py_DECREF(__pyx_v_parent_signal);
  return __pyx_r;
}

static PyObject *__pyx_n_call_synced;

static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__gw(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8wimpiggy_8lowlevel_8bindings__gw(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display = 0;
  PyObject *__pyx_v_xwin = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"display","xwin",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_display, &__pyx_v_xwin)) return 0;
  Py_INCREF(__pyx_v_display);
  Py_INCREF(__pyx_v_xwin);
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_trap); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1203; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_call_synced); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1203; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_get_pywindow); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1203; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(3); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1203; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  Py_INCREF(__pyx_v_display);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_v_display);
  Py_INCREF(__pyx_v_xwin);
  PyTuple_SET_ITEM(__pyx_3, 2, __pyx_v_xwin);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1203; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings._gw");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_display);
  Py_DECREF(__pyx_v_xwin);
  return __pyx_r;
}

static PyObject *__pyx_n_send_event;
static PyObject *__pyx_n_display;
static PyObject *__pyx_n__gw;
static PyObject *__pyx_n_x;
static PyObject *__pyx_n_y;
static PyObject *__pyx_n_width;
static PyObject *__pyx_n_height;
static PyObject *__pyx_n_border_width;
static PyObject *__pyx_n_above;
static PyObject *__pyx_n_detail;
static PyObject *__pyx_n_value_mask;
static PyObject *__pyx_n_mode;
static PyObject *__pyx_n_warn;
static PyObject *__pyx_n_get_pyatom;
static PyObject *__pyx_n_message_type;
static PyObject *__pyx_n_format;
static PyObject *__pyx_n_data;
static PyObject *__pyx_n_override_redirect;
static PyObject *__pyx_n_serial;
static PyObject *__pyx_n_atom;
static PyObject *__pyx_n_hardware_keycode;
static PyObject *__pyx_n_state;
static PyObject *__pyx_n_damage;
static PyObject *__pyx_n__route_event;
static PyObject *__pyx_n_exc_info;

static PyObject *__pyx_k221p;
static PyObject *__pyx_k222p;
static PyObject *__pyx_k224p;
static PyObject *__pyx_k225p;
static PyObject *__pyx_k226p;
static PyObject *__pyx_k227p;
static PyObject *__pyx_k228p;
static PyObject *__pyx_k229p;
static PyObject *__pyx_k230p;
static PyObject *__pyx_k231p;
static PyObject *__pyx_k232p;
static PyObject *__pyx_k233p;
static PyObject *__pyx_k234p;
static PyObject *__pyx_k235p;
static PyObject *__pyx_k236p;
static PyObject *__pyx_k237p;
static PyObject *__pyx_k238p;
static PyObject *__pyx_k239p;
static PyObject *__pyx_k240p;
static PyObject *__pyx_k241p;
static PyObject *__pyx_k242p;
static PyObject *__pyx_k243p;
static PyObject *__pyx_k244p;

static char __pyx_k221[] = "DAMAGE-event-base";
static char __pyx_k222[] = "DAMAGE-event-base";
static char __pyx_k224[] = "MapRequest received";
static char __pyx_k225[] = "ConfigureRequest received";
static char __pyx_k226[] = "FocusIn/FocusOut received";
static char __pyx_k227[] = "ClientMessage received";
static char __pyx_k228[] = "Xlib claims that this ClientEvent's 32-bit ";
static char __pyx_k229[] = "message_type is %s.  ";
static char __pyx_k230[] = "Note that this is >2^32.  ";
static char __pyx_k231[] = "This makes no sense, so I'm ignoring it.";
static char __pyx_k232[] = "Ignoring ClientMessage with format != 32";
static char __pyx_k233[] = "MapNotify event received";
static char __pyx_k234[] = "UnmapNotify event received";
static char __pyx_k235[] = "DestroyNotify event received";
static char __pyx_k236[] = "PropertyNotify event received";
static char __pyx_k237[] = "ConfigureNotify event received";
static char __pyx_k238[] = "ReparentNotify event received";
static char __pyx_k239[] = "KeyPress event received";
static char __pyx_k240[] = "DamageNotify received";
static char __pyx_k241[] = "Some window in our event disappeared before we could ";
static char __pyx_k242[] = "handle the event; so I'm just ignoring it instead.";
static char __pyx_k243[] = "exiting on KeyboardInterrupt/SystemExit";
static char __pyx_k244[] = "Unhandled exception in x_event_filter:";

static GdkFilterReturn __pyx_f_8wimpiggy_8lowlevel_8bindings_x_event_filter(GdkXEvent *__pyx_v_e_gdk,GdkEvent *__pyx_v_gdk_event,void *__pyx_v_userdata) {
  XEvent *__pyx_v_e;
  XDamageNotifyEvent *__pyx_v_damage_e;
  PyObject *__pyx_v_d;
  PyObject *__pyx_v_my_events;
  PyObject *__pyx_v_damage_type;
  PyObject *__pyx_v_pyev;
  PyObject *__pyx_v_pieces;
  PyObject *__pyx_v_i;
  GdkFilterReturn __pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  Py_ssize_t __pyx_6;
  PyObject *__pyx_7 = 0;
  PyObject *__pyx_8 = 0;
  PyObject *__pyx_9 = 0;
  __pyx_v_d = Py_None; Py_INCREF(Py_None);
  __pyx_v_my_events = Py_None; Py_INCREF(Py_None);
  __pyx_v_damage_type = Py_None; Py_INCREF(Py_None);
  __pyx_v_pyev = Py_None; Py_INCREF(Py_None);
  __pyx_v_pieces = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1210 */
  __pyx_v_e = ((XEvent *)__pyx_v_e_gdk);

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1211 */
  __pyx_1 = __pyx_v_e->xany.send_event;
  if (__pyx_1) {
    __pyx_2 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1211; goto __pyx_L1;}
    __pyx_3 = PyLong_FromUnsignedLong(ClientMessage); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1211; goto __pyx_L1;}
    __pyx_4 = PyLong_FromUnsignedLong(UnmapNotify); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1211; goto __pyx_L1;}
    __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1211; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
    PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
    __pyx_3 = 0;
    __pyx_4 = 0;
    __pyx_1 = PySequence_Contains(__pyx_5, __pyx_2); if (__pyx_1 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1211; goto __pyx_L1;}
    __pyx_1 = !__pyx_1;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
  }
  if (__pyx_1) {
    __pyx_r = GDK_FILTER_CONTINUE;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1213 */
  /*try:*/ {

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1214 */
    __pyx_3 = __pyx_f_8wimpiggy_8lowlevel_8bindings_wrap(((GObject *)gdk_x11_lookup_xdisplay(__pyx_v_e->xany.display))); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1214; goto __pyx_L3;}
    Py_DECREF(__pyx_v_d);
    __pyx_v_d = __pyx_3;
    __pyx_3 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1215 */
    __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__x_event_signals); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1215; goto __pyx_L3;}
    __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1215; goto __pyx_L3;}
    PyTuple_SET_ITEM(__pyx_2, 0, __pyx_4);
    __pyx_4 = 0;
    __pyx_5 = PyObject_CallObject(((PyObject *)(&PyDict_Type)), __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1215; goto __pyx_L3;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_v_my_events);
    __pyx_v_my_events = __pyx_5;
    __pyx_5 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1216 */
    __pyx_3 = PyObject_GetAttr(__pyx_v_d, __pyx_n_get_data); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1216; goto __pyx_L3;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1216; goto __pyx_L3;}
    Py_INCREF(__pyx_k221p);
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k221p);
    __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1216; goto __pyx_L3;}
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_1 = __pyx_2 != Py_None;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (__pyx_1) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1217 */
      __pyx_5 = PyObject_GetAttr(__pyx_v_d, __pyx_n_get_data); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1217; goto __pyx_L3;}
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1217; goto __pyx_L3;}
      Py_INCREF(__pyx_k222p);
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k222p);
      __pyx_4 = PyObject_CallObject(__pyx_5, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1217; goto __pyx_L3;}
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_2 = PyLong_FromUnsignedLong(XDamageNotify); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1217; goto __pyx_L3;}
      __pyx_5 = PyNumber_Add(__pyx_4, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1217; goto __pyx_L3;}
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_v_damage_type);
      __pyx_v_damage_type = __pyx_5;
      __pyx_5 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1218 */
      __pyx_3 = PyObject_GetItem(__pyx_v_my_events, __pyx_n_XDamageNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1218; goto __pyx_L3;}
      if (PyObject_SetItem(__pyx_v_my_events, __pyx_v_damage_type, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1218; goto __pyx_L3;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      goto __pyx_L5;
    }
    /*else*/ {
      __pyx_4 = PyInt_FromLong((-1)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1220; goto __pyx_L3;}
      Py_DECREF(__pyx_v_damage_type);
      __pyx_v_damage_type = __pyx_4;
      __pyx_4 = 0;
    }
    __pyx_L5:;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1221 */
    __pyx_2 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1221; goto __pyx_L3;}
    __pyx_1 = PySequence_Contains(__pyx_v_my_events, __pyx_2); if (__pyx_1 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1221; goto __pyx_L3;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    if (__pyx_1) {

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1222 */
      __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_LameStruct); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1222; goto __pyx_L3;}
      __pyx_3 = PyObject_CallObject(__pyx_5, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1222; goto __pyx_L3;}
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      Py_DECREF(__pyx_v_pyev);
      __pyx_v_pyev = __pyx_3;
      __pyx_3 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1223 */
      __pyx_4 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1223; goto __pyx_L3;}
      if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_type, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1223; goto __pyx_L3;}
      Py_DECREF(__pyx_4); __pyx_4 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1224 */
      __pyx_2 = PyInt_FromLong(__pyx_v_e->xany.send_event); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1224; goto __pyx_L3;}
      if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_send_event, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1224; goto __pyx_L3;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1225 */
      if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_display, __pyx_v_d) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1225; goto __pyx_L3;}

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1227 */
      /*try:*/ {

        /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1228 */
        __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1228; goto __pyx_L7;}
        __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xany.window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1228; goto __pyx_L7;}
        __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1228; goto __pyx_L7;}
        Py_INCREF(__pyx_v_d);
        PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_d);
        PyTuple_SET_ITEM(__pyx_4, 1, __pyx_3);
        __pyx_3 = 0;
        __pyx_2 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1228; goto __pyx_L7;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_delivered_to, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1228; goto __pyx_L7;}
        Py_DECREF(__pyx_2); __pyx_2 = 0;

        /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1229 */
        __pyx_1 = (__pyx_v_e->type == MapRequest);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1230 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1230; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1230; goto __pyx_L7;}
          Py_INCREF(__pyx_k224p);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k224p);
          __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1230; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1231 */
          __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1231; goto __pyx_L7;}
          __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xmaprequest.window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1231; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1231; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 1, __pyx_3);
          __pyx_3 = 0;
          __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1231; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1231; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == ConfigureRequest);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1233 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1233; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1233; goto __pyx_L7;}
          Py_INCREF(__pyx_k225p);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k225p);
          __pyx_5 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1233; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1234 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1234; goto __pyx_L7;}
          __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xconfigurerequest.window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1234; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1234; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_3);
          __pyx_3 = 0;
          __pyx_5 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1234; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1234; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1235 */
          __pyx_3 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.x); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1235; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_x, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1235; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1236 */
          __pyx_4 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.y); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1236; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_y, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1236; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1237 */
          __pyx_2 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.width); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1237; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_width, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1237; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1238 */
          __pyx_5 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.height); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1238; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_height, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1238; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1239 */
          __pyx_3 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.border_width); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1239; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_border_width, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1239; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1240 */
          /*try:*/ {
            __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1247; goto __pyx_L10;}
            __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_e->xconfigurerequest.above); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1247; goto __pyx_L10;}
            __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1247; goto __pyx_L10;}
            Py_INCREF(__pyx_v_d);
            PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_d);
            PyTuple_SET_ITEM(__pyx_5, 1, __pyx_2);
            __pyx_2 = 0;
            __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1247; goto __pyx_L10;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            Py_DECREF(__pyx_5); __pyx_5 = 0;
            if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_above, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1247; goto __pyx_L10;}
            Py_DECREF(__pyx_3); __pyx_3 = 0;
          }
          goto __pyx_L11;
          __pyx_L10:;
          Py_XDECREF(__pyx_2); __pyx_2 = 0;
          Py_XDECREF(__pyx_4); __pyx_4 = 0;
          Py_XDECREF(__pyx_5); __pyx_5 = 0;
          Py_XDECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1248 */
          __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_XError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1248; goto __pyx_L7;}
          __pyx_1 = PyErr_ExceptionMatches(__pyx_2);
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (__pyx_1) {
            __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.x_event_filter");
            if (__Pyx_GetException(&__pyx_4, &__pyx_5, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1248; goto __pyx_L7;}
            if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_above, Py_None) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1249; goto __pyx_L7;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            Py_DECREF(__pyx_5); __pyx_5 = 0;
            Py_DECREF(__pyx_3); __pyx_3 = 0;
            goto __pyx_L11;
          }
          goto __pyx_L7;
          __pyx_L11:;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1250 */
          __pyx_2 = PyInt_FromLong(__pyx_v_e->xconfigurerequest.detail); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1250; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_detail, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1250; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1251 */
          __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_e->xconfigurerequest.value_mask); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1251; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_value_mask, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1251; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          goto __pyx_L9;
        }
        __pyx_5 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1252; goto __pyx_L7;}
        __pyx_3 = PyLong_FromUnsignedLong(FocusIn); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1252; goto __pyx_L7;}
        __pyx_2 = PyLong_FromUnsignedLong(FocusOut); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1252; goto __pyx_L7;}
        __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1252; goto __pyx_L7;}
        PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
        PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
        __pyx_3 = 0;
        __pyx_2 = 0;
        __pyx_1 = PySequence_Contains(__pyx_4, __pyx_5); if (__pyx_1 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1252; goto __pyx_L7;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1253 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1253; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1253; goto __pyx_L7;}
          Py_INCREF(__pyx_k226p);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k226p);
          __pyx_5 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1253; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1254 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1254; goto __pyx_L7;}
          __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xfocus.window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1254; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1254; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_3);
          __pyx_3 = 0;
          __pyx_5 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1254; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1254; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1255 */
          __pyx_3 = PyInt_FromLong(__pyx_v_e->xfocus.mode); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1255; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_mode, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1255; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1256 */
          __pyx_4 = PyInt_FromLong(__pyx_v_e->xfocus.detail); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1256; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_detail, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1256; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == ClientMessage);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1258 */
          __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1258; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1258; goto __pyx_L7;}
          Py_INCREF(__pyx_k227p);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k227p);
          __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1258; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1259 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1259; goto __pyx_L7;}
          __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_e->xany.window); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1259; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1259; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 1, __pyx_2);
          __pyx_2 = 0;
          __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1259; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1259; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1260 */
          __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_e->xclient.message_type); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_2);
          __pyx_2 = 0;
          __pyx_5 = PyObject_CallObject(((PyObject *)(&PyLong_Type)), __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          __pyx_3 = PyInt_FromLong(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
          __pyx_3 = 0;
          __pyx_4 = PyObject_CallObject(((PyObject *)(&PyLong_Type)), __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          __pyx_3 = PyInt_FromLong(32); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          __pyx_2 = PyNumber_Power(__pyx_4, __pyx_3, Py_None); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          if (PyObject_Cmp(__pyx_5, __pyx_2, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1260; goto __pyx_L7;}
          __pyx_1 = __pyx_1 > 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (__pyx_1) {

            /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1261 */
            __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1261; goto __pyx_L7;}
            __pyx_3 = PyObject_GetAttr(__pyx_4, __pyx_n_warn); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1261; goto __pyx_L7;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            __pyx_5 = PyNumber_Add(__pyx_k228p, __pyx_k229p); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1262; goto __pyx_L7;}
            __pyx_2 = PyNumber_Add(__pyx_5, __pyx_k230p); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1263; goto __pyx_L7;}
            Py_DECREF(__pyx_5); __pyx_5 = 0;
            __pyx_4 = PyNumber_Add(__pyx_2, __pyx_k231p); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1264; goto __pyx_L7;}
            Py_DECREF(__pyx_2); __pyx_2 = 0;
            __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xclient.message_type); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1265; goto __pyx_L7;}
            __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1261; goto __pyx_L7;}
            PyTuple_SET_ITEM(__pyx_2, 0, __pyx_4);
            PyTuple_SET_ITEM(__pyx_2, 1, __pyx_5);
            __pyx_4 = 0;
            __pyx_5 = 0;
            __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1261; goto __pyx_L7;}
            Py_DECREF(__pyx_3); __pyx_3 = 0;
            Py_DECREF(__pyx_2); __pyx_2 = 0;
            Py_DECREF(__pyx_4); __pyx_4 = 0;

            /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1266 */
            __pyx_r = GDK_FILTER_CONTINUE;
            goto __pyx_L0;
            goto __pyx_L12;
          }
          __pyx_L12:;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1267 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_get_pyatom); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1267; goto __pyx_L7;}
          __pyx_3 = PyObject_GetAttr(__pyx_v_pyev, __pyx_n_display); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1267; goto __pyx_L7;}
          __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_e->xclient.message_type); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1268; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1267; goto __pyx_L7;}
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
          PyTuple_SET_ITEM(__pyx_4, 1, __pyx_2);
          __pyx_3 = 0;
          __pyx_2 = 0;
          __pyx_3 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1267; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_message_type, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1267; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1269 */
          __pyx_2 = PyInt_FromLong(__pyx_v_e->xclient.format); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1269; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_format, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1269; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1271 */
          __pyx_5 = PyObject_GetAttr(__pyx_v_pyev, __pyx_n_format); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1271; goto __pyx_L7;}
          __pyx_4 = PyInt_FromLong(32); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1271; goto __pyx_L7;}
          if (PyObject_Cmp(__pyx_5, __pyx_4, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1271; goto __pyx_L7;}
          __pyx_1 = __pyx_1 != 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          if (__pyx_1) {

            /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1272 */
            __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1272; goto __pyx_L7;}
            __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1272; goto __pyx_L7;}
            Py_INCREF(__pyx_k232p);
            PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k232p);
            __pyx_5 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1272; goto __pyx_L7;}
            Py_DECREF(__pyx_3); __pyx_3 = 0;
            Py_DECREF(__pyx_2); __pyx_2 = 0;
            Py_DECREF(__pyx_5); __pyx_5 = 0;

            /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1273 */
            __pyx_r = GDK_FILTER_CONTINUE;
            goto __pyx_L0;
            goto __pyx_L13;
          }
          __pyx_L13:;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1274 */
          __pyx_4 = PyList_New(0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1274; goto __pyx_L7;}
          Py_DECREF(__pyx_v_pieces);
          __pyx_v_pieces = __pyx_4;
          __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1275 */
          __pyx_3 = PyInt_FromLong(5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1275; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1275; goto __pyx_L7;}
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
          __pyx_3 = 0;
          __pyx_5 = PyObject_CallObject(((PyObject *)(&PyRange_Type)), __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1275; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          __pyx_4 = PyObject_GetIter(__pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1275; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          for (;;) {
            __pyx_3 = PyIter_Next(__pyx_4);
            if (!__pyx_3) {
              if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1275; goto __pyx_L7;}
              break;
            }
            Py_DECREF(__pyx_v_i);
            __pyx_v_i = __pyx_3;
            __pyx_3 = 0;
            __pyx_2 = PyObject_GetAttr(__pyx_v_pieces, __pyx_n_append); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            __pyx_5 = PyInt_FromLong((__pyx_v_e->xclient.data.l[__pyx_6])); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            PyTuple_SET_ITEM(__pyx_3, 0, __pyx_5);
            __pyx_5 = 0;
            __pyx_5 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            Py_DECREF(__pyx_3); __pyx_3 = 0;
            __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            PyTuple_SET_ITEM(__pyx_3, 0, __pyx_5);
            __pyx_5 = 0;
            __pyx_5 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1276; goto __pyx_L7;}
            Py_DECREF(__pyx_2); __pyx_2 = 0;
            Py_DECREF(__pyx_3); __pyx_3 = 0;
            Py_DECREF(__pyx_5); __pyx_5 = 0;
          }
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1277 */
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1277; goto __pyx_L7;}
          Py_INCREF(__pyx_v_pieces);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_pieces);
          __pyx_3 = PyObject_CallObject(((PyObject *)(&PyTuple_Type)), __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1277; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_data, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1277; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == MapNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1279 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1279; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1279; goto __pyx_L7;}
          Py_INCREF(__pyx_k233p);
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k233p);
          __pyx_2 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1279; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1280 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1280; goto __pyx_L7;}
          __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xmap.window); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1280; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1280; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_4, 1, __pyx_5);
          __pyx_5 = 0;
          __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1280; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1280; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1281 */
          __pyx_5 = PyInt_FromLong(__pyx_v_e->xmap.override_redirect); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1281; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_override_redirect, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1281; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == UnmapNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1283 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1283; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1283; goto __pyx_L7;}
          Py_INCREF(__pyx_k234p);
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k234p);
          __pyx_2 = PyObject_CallObject(__pyx_3, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1283; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1284 */
          __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xany.serial); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1284; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_serial, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1284; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1285 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1285; goto __pyx_L7;}
          __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_e->xunmap.window); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1285; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1285; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_4);
          __pyx_4 = 0;
          __pyx_5 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1285; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1285; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == DestroyNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1287 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1287; goto __pyx_L7;}
          __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1287; goto __pyx_L7;}
          Py_INCREF(__pyx_k235p);
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k235p);
          __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1287; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1288 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1288; goto __pyx_L7;}
          __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_e->xdestroywindow.window); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1288; goto __pyx_L7;}
          __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1288; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_3, 1, __pyx_4);
          __pyx_4 = 0;
          __pyx_2 = PyObject_CallObject(__pyx_5, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1288; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1288; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == PropertyNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1290 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1290; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1290; goto __pyx_L7;}
          Py_INCREF(__pyx_k236p);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k236p);
          __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1290; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1291 */
          __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1291; goto __pyx_L7;}
          __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_e->xany.window); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1291; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1291; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
          __pyx_4 = 0;
          __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1291; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1291; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1292 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n_trap); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          __pyx_2 = PyObject_GetAttr(__pyx_4, __pyx_n_call_synced); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_get_pyatom); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xproperty.atom); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1293; goto __pyx_L7;}
          __pyx_4 = PyTuple_New(3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_5);
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_4, 2, __pyx_3);
          __pyx_5 = 0;
          __pyx_3 = 0;
          __pyx_5 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_atom, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1292; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == ConfigureNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1295 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1295; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1295; goto __pyx_L7;}
          Py_INCREF(__pyx_k237p);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k237p);
          __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1295; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1296 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1296; goto __pyx_L7;}
          __pyx_3 = PyLong_FromUnsignedLong(__pyx_v_e->xconfigure.window); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1296; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1296; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_3);
          __pyx_3 = 0;
          __pyx_4 = PyObject_CallObject(__pyx_5, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1296; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1296; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1297 */
          __pyx_3 = PyInt_FromLong(__pyx_v_e->xconfigure.x); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1297; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_x, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1297; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1298 */
          __pyx_5 = PyInt_FromLong(__pyx_v_e->xconfigure.y); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1298; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_y, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1298; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1299 */
          __pyx_2 = PyInt_FromLong(__pyx_v_e->xconfigure.width); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1299; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_width, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1299; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1300 */
          __pyx_4 = PyInt_FromLong(__pyx_v_e->xconfigure.height); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1300; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_height, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1300; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1301 */
          __pyx_3 = PyInt_FromLong(__pyx_v_e->xconfigure.border_width); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1301; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_border_width, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1301; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == ReparentNotify);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1303 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1303; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1303; goto __pyx_L7;}
          Py_INCREF(__pyx_k238p);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k238p);
          __pyx_4 = PyObject_CallObject(__pyx_5, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1303; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1304 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1304; goto __pyx_L7;}
          __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xreparent.window); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1304; goto __pyx_L7;}
          __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1304; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_2, 1, __pyx_5);
          __pyx_5 = 0;
          __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1304; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1304; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          goto __pyx_L9;
        }
        __pyx_1 = (__pyx_v_e->type == KeyPress);
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1306 */
          __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1306; goto __pyx_L7;}
          __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1306; goto __pyx_L7;}
          Py_INCREF(__pyx_k239p);
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k239p);
          __pyx_2 = PyObject_CallObject(__pyx_5, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1306; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1307 */
          __pyx_4 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1307; goto __pyx_L7;}
          __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xany.window); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1307; goto __pyx_L7;}
          __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1307; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_3, 1, __pyx_5);
          __pyx_5 = 0;
          __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1307; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1307; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1308 */
          __pyx_5 = PyLong_FromUnsignedLong(__pyx_v_e->xkey.keycode); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1308; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_hardware_keycode, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1308; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1309 */
          __pyx_4 = PyLong_FromUnsignedLong(__pyx_v_e->xkey.state); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1309; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_state, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1309; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;
          goto __pyx_L9;
        }
        __pyx_3 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1310; goto __pyx_L7;}
        if (PyObject_Cmp(__pyx_3, __pyx_v_damage_type, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1310; goto __pyx_L7;}
        __pyx_1 = __pyx_1 == 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        if (__pyx_1) {

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1311 */
          __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1311; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1311; goto __pyx_L7;}
          Py_INCREF(__pyx_k240p);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_k240p);
          __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1311; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1312 */
          __pyx_v_damage_e = ((XDamageNotifyEvent *)__pyx_v_e);

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1313 */
          __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__gw); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1313; goto __pyx_L7;}
          __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_e->xany.window); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1313; goto __pyx_L7;}
          __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1313; goto __pyx_L7;}
          Py_INCREF(__pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_v_d);
          PyTuple_SET_ITEM(__pyx_5, 1, __pyx_2);
          __pyx_2 = 0;
          __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1313; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_window, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1313; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1314 */
          __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_damage_e->damage); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1314; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_damage, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1314; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1315 */
          __pyx_3 = PyInt_FromLong(__pyx_v_damage_e->area.x); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1315; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_x, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1315; goto __pyx_L7;}
          Py_DECREF(__pyx_3); __pyx_3 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1316 */
          __pyx_5 = PyInt_FromLong(__pyx_v_damage_e->area.y); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1316; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_y, __pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1316; goto __pyx_L7;}
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1317 */
          __pyx_4 = PyInt_FromLong(__pyx_v_damage_e->area.width); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1317; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_width, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1317; goto __pyx_L7;}
          Py_DECREF(__pyx_4); __pyx_4 = 0;

          /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1318 */
          __pyx_2 = PyInt_FromLong(__pyx_v_damage_e->area.height); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1318; goto __pyx_L7;}
          if (PyObject_SetAttr(__pyx_v_pyev, __pyx_n_height, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1318; goto __pyx_L7;}
          Py_DECREF(__pyx_2); __pyx_2 = 0;
          goto __pyx_L9;
        }
        __pyx_L9:;
      }
      /*else:*/ {
        __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n__route_event); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        __pyx_8 = PyTuple_New(1); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_INCREF(__pyx_v_pyev);
        PyTuple_SET_ITEM(__pyx_8, 0, __pyx_v_pyev);
        __pyx_7 = PyInt_FromLong(__pyx_v_e->type); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_7);
        __pyx_7 = 0;
        __pyx_4 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        __pyx_2 = PyObject_GetItem(__pyx_v_my_events, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        __pyx_7 = PySequence_Tuple(__pyx_2); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_DECREF(__pyx_2); __pyx_2 = 0;
        __pyx_5 = PyNumber_Add(__pyx_8, __pyx_7); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_DECREF(__pyx_8); __pyx_8 = 0;
        Py_DECREF(__pyx_7); __pyx_7 = 0;
        __pyx_4 = PyObject_CallObject(__pyx_3, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1328; goto __pyx_L3;}
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_4); __pyx_4 = 0;
      }
      goto __pyx_L8;
      __pyx_L7:;
      Py_XDECREF(__pyx_3); __pyx_3 = 0;
      Py_XDECREF(__pyx_5); __pyx_5 = 0;
      Py_XDECREF(__pyx_4); __pyx_4 = 0;
      Py_XDECREF(__pyx_2); __pyx_2 = 0;

      /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1319 */
      __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_XError); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1319; goto __pyx_L3;}
      __pyx_1 = PyErr_ExceptionMatches(__pyx_3);
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      if (__pyx_1) {
        __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.x_event_filter");
        if (__Pyx_GetException(&__pyx_5, &__pyx_4, &__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1319; goto __pyx_L3;}
        __pyx_v_e = ((XEvent *)__pyx_4);
        __pyx_3 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1320; goto __pyx_L3;}
        __pyx_7 = PyNumber_Add(__pyx_k241p, __pyx_k242p); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1321; goto __pyx_L3;}
        __pyx_8 = PyTuple_New(1); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1320; goto __pyx_L3;}
        PyTuple_SET_ITEM(__pyx_8, 0, __pyx_7);
        __pyx_7 = 0;
        __pyx_7 = PyObject_CallObject(__pyx_3, __pyx_8); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1320; goto __pyx_L3;}
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        Py_DECREF(__pyx_8); __pyx_8 = 0;
        Py_DECREF(__pyx_7); __pyx_7 = 0;
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        Py_DECREF(__pyx_2); __pyx_2 = 0;
        goto __pyx_L8;
      }
      goto __pyx_L3;
      __pyx_L8:;
      goto __pyx_L6;
    }
    __pyx_L6:;
  }
  goto __pyx_L4;
  __pyx_L3:;
  Py_XDECREF(__pyx_2); __pyx_2 = 0;
  Py_XDECREF(__pyx_8); __pyx_8 = 0;
  Py_XDECREF(__pyx_7); __pyx_7 = 0;
  Py_XDECREF(__pyx_3); __pyx_3 = 0;
  Py_XDECREF(__pyx_5); __pyx_5 = 0;
  Py_XDECREF(__pyx_4); __pyx_4 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1329 */
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1329; goto __pyx_L1;}
  Py_INCREF(PyExc_KeyboardInterrupt);
  PyTuple_SET_ITEM(__pyx_2, 0, PyExc_KeyboardInterrupt);
  Py_INCREF(PyExc_SystemExit);
  PyTuple_SET_ITEM(__pyx_2, 1, PyExc_SystemExit);
  __pyx_1 = PyErr_ExceptionMatches(__pyx_2);
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_1) {
    __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.x_event_filter");
    if (__Pyx_GetException(&__pyx_8, &__pyx_7, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1329; goto __pyx_L1;}

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1330 */
    __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1330; goto __pyx_L1;}
    __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1330; goto __pyx_L1;}
    Py_INCREF(__pyx_k243p);
    PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k243p);
    __pyx_2 = PyObject_CallObject(__pyx_5, __pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1330; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;

    /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1331 */
    __pyx_5 = __Pyx_GetName(__pyx_m, __pyx_n_gtk_main_quit_really); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1331; goto __pyx_L1;}
    __pyx_4 = PyObject_CallObject(__pyx_5, 0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1331; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    Py_DECREF(__pyx_8); __pyx_8 = 0;
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    goto __pyx_L4;
  }

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1332 */
  /*except:*/ {
    __Pyx_AddTraceback("wimpiggy.lowlevel.bindings.x_event_filter");
    if (__Pyx_GetException(&__pyx_2, &__pyx_5, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1332; goto __pyx_L1;}
    __pyx_8 = __Pyx_GetName(__pyx_m, __pyx_n_log); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    __pyx_7 = PyObject_GetAttr(__pyx_8, __pyx_n_warn); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    Py_DECREF(__pyx_8); __pyx_8 = 0;
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    Py_INCREF(__pyx_k244p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k244p);
    __pyx_8 = PyDict_New(); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_8, __pyx_n_exc_info, Py_True) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    __pyx_9 = PyEval_CallObjectWithKeywords(__pyx_7, __pyx_3, __pyx_8); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1333; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    Py_DECREF(__pyx_8); __pyx_8 = 0;
    Py_DECREF(__pyx_9); __pyx_9 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    goto __pyx_L4;
  }
  __pyx_L4:;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1334 */
  __pyx_r = GDK_FILTER_CONTINUE;
  goto __pyx_L0;

  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_7);
  Py_XDECREF(__pyx_8);
  Py_XDECREF(__pyx_9);
  __Pyx_WriteUnraisable("wimpiggy.lowlevel.bindings.x_event_filter");
  __pyx_L0:;
  Py_DECREF(__pyx_v_d);
  Py_DECREF(__pyx_v_my_events);
  Py_DECREF(__pyx_v_damage_type);
  Py_DECREF(__pyx_v_pyev);
  Py_DECREF(__pyx_v_pieces);
  Py_DECREF(__pyx_v_i);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_Above, "Above"},
  {&__pyx_n_AnyKey, "AnyKey"},
  {&__pyx_n_AnyModifier, "AnyModifier"},
  {&__pyx_n_BadAccess, "BadAccess"},
  {&__pyx_n_BadAlloc, "BadAlloc"},
  {&__pyx_n_BadAtom, "BadAtom"},
  {&__pyx_n_BadColor, "BadColor"},
  {&__pyx_n_BadCursor, "BadCursor"},
  {&__pyx_n_BadDrawable, "BadDrawable"},
  {&__pyx_n_BadFont, "BadFont"},
  {&__pyx_n_BadGC, "BadGC"},
  {&__pyx_n_BadIDChoice, "BadIDChoice"},
  {&__pyx_n_BadImplementation, "BadImplementation"},
  {&__pyx_n_BadLength, "BadLength"},
  {&__pyx_n_BadMatch, "BadMatch"},
  {&__pyx_n_BadName, "BadName"},
  {&__pyx_n_BadPixmap, "BadPixmap"},
  {&__pyx_n_BadPropertyType, "BadPropertyType"},
  {&__pyx_n_BadRequest, "BadRequest"},
  {&__pyx_n_BadValue, "BadValue"},
  {&__pyx_n_BadWindow, "BadWindow"},
  {&__pyx_n_Below, "Below"},
  {&__pyx_n_BottomIf, "BottomIf"},
  {&__pyx_n_Button1MotionMask, "Button1MotionMask"},
  {&__pyx_n_Button2MotionMask, "Button2MotionMask"},
  {&__pyx_n_Button3MotionMask, "Button3MotionMask"},
  {&__pyx_n_Button4MotionMask, "Button4MotionMask"},
  {&__pyx_n_Button5MotionMask, "Button5MotionMask"},
  {&__pyx_n_ButtonMotionMask, "ButtonMotionMask"},
  {&__pyx_n_ButtonPress, "ButtonPress"},
  {&__pyx_n_ButtonPressMask, "ButtonPressMask"},
  {&__pyx_n_ButtonRelease, "ButtonRelease"},
  {&__pyx_n_ButtonReleaseMask, "ButtonReleaseMask"},
  {&__pyx_n_CWBorderWidth, "CWBorderWidth"},
  {&__pyx_n_CWHeight, "CWHeight"},
  {&__pyx_n_CWSibling, "CWSibling"},
  {&__pyx_n_CWStackMode, "CWStackMode"},
  {&__pyx_n_CWWidth, "CWWidth"},
  {&__pyx_n_CWX, "CWX"},
  {&__pyx_n_CWY, "CWY"},
  {&__pyx_n_CirculateNotify, "CirculateNotify"},
  {&__pyx_n_CirculateRequest, "CirculateRequest"},
  {&__pyx_n_ClientMessage, "ClientMessage"},
  {&__pyx_n_Clipboard, "Clipboard"},
  {&__pyx_n_ColormapChangeMask, "ColormapChangeMask"},
  {&__pyx_n_ColormapNotify, "ColormapNotify"},
  {&__pyx_n_Composite, "Composite"},
  {&__pyx_n_ConfigureNotify, "ConfigureNotify"},
  {&__pyx_n_ConfigureRequest, "ConfigureRequest"},
  {&__pyx_n_CreateNotify, "CreateNotify"},
  {&__pyx_n_CurrentTime, "CurrentTime"},
  {&__pyx_n_DAMAGE, "DAMAGE"},
  {&__pyx_n_DESTROY, "DESTROY"},
  {&__pyx_n_DestroyNotify, "DestroyNotify"},
  {&__pyx_n_Display, "Display"},
  {&__pyx_n_Drawable, "Drawable"},
  {&__pyx_n_EnterNotify, "EnterNotify"},
  {&__pyx_n_EnterWindowMask, "EnterWindowMask"},
  {&__pyx_n_Expose, "Expose"},
  {&__pyx_n_ExposureMask, "ExposureMask"},
  {&__pyx_n_FirstExtensionError, "FirstExtensionError"},
  {&__pyx_n_FocusChangeMask, "FocusChangeMask"},
  {&__pyx_n_FocusIn, "FocusIn"},
  {&__pyx_n_FocusOut, "FocusOut"},
  {&__pyx_n_GBoxed, "GBoxed"},
  {&__pyx_n_GObject, "GObject"},
  {&__pyx_n_GrabModeAsync, "GrabModeAsync"},
  {&__pyx_n_GrabModeSync, "GrabModeSync"},
  {&__pyx_n_GraphicsExpose, "GraphicsExpose"},
  {&__pyx_n_GravityNotify, "GravityNotify"},
  {&__pyx_n_HINT_ASPECT, "HINT_ASPECT"},
  {&__pyx_n_HINT_BASE_SIZE, "HINT_BASE_SIZE"},
  {&__pyx_n_HINT_MAX_SIZE, "HINT_MAX_SIZE"},
  {&__pyx_n_HINT_MIN_SIZE, "HINT_MIN_SIZE"},
  {&__pyx_n_HINT_RESIZE_INC, "HINT_RESIZE_INC"},
  {&__pyx_n_IconMaskHint, "IconMaskHint"},
  {&__pyx_n_IconPixmapHint, "IconPixmapHint"},
  {&__pyx_n_IconPositionHint, "IconPositionHint"},
  {&__pyx_n_IconWindowHint, "IconWindowHint"},
  {&__pyx_n_IconicState, "IconicState"},
  {&__pyx_n_InputFocus, "InputFocus"},
  {&__pyx_n_InputHint, "InputHint"},
  {&__pyx_n_IsUnmapped, "IsUnmapped"},
  {&__pyx_n_IsUnviewable, "IsUnviewable"},
  {&__pyx_n_IsViewable, "IsViewable"},
  {&__pyx_n_KeyPress, "KeyPress"},
  {&__pyx_n_KeyPressMask, "KeyPressMask"},
  {&__pyx_n_KeyRelease, "KeyRelease"},
  {&__pyx_n_KeyReleaseMask, "KeyReleaseMask"},
  {&__pyx_n_KeymapNotify, "KeymapNotify"},
  {&__pyx_n_KeymapStateMask, "KeymapStateMask"},
  {&__pyx_n_LASTEvent, "LASTEvent"},
  {&__pyx_n_LameStruct, "LameStruct"},
  {&__pyx_n_LastExtensionError, "LastExtensionError"},
  {&__pyx_n_LeaveNotify, "LeaveNotify"},
  {&__pyx_n_LeaveWindowMask, "LeaveWindowMask"},
  {&__pyx_n_Logger, "Logger"},
  {&__pyx_n_MapNotify, "MapNotify"},
  {&__pyx_n_MapRequest, "MapRequest"},
  {&__pyx_n_MappingNotify, "MappingNotify"},
  {&__pyx_n_MotionNotify, "MotionNotify"},
  {&__pyx_n_NoEventMask, "NoEventMask"},
  {&__pyx_n_NoExpose, "NoExpose"},
  {&__pyx_n_NoSuchProperty, "NoSuchProperty"},
  {&__pyx_n_NormalState, "NormalState"},
  {&__pyx_n_NotifyAncestor, "NotifyAncestor"},
  {&__pyx_n_NotifyDetailNone, "NotifyDetailNone"},
  {&__pyx_n_NotifyGrab, "NotifyGrab"},
  {&__pyx_n_NotifyInferior, "NotifyInferior"},
  {&__pyx_n_NotifyNonlinear, "NotifyNonlinear"},
  {&__pyx_n_NotifyNonlinearVirtual, "NotifyNonlinearVirtual"},
  {&__pyx_n_NotifyNormal, "NotifyNormal"},
  {&__pyx_n_NotifyPointer, "NotifyPointer"},
  {&__pyx_n_NotifyPointerRoot, "NotifyPointerRoot"},
  {&__pyx_n_NotifyUngrab, "NotifyUngrab"},
  {&__pyx_n_NotifyVirtual, "NotifyVirtual"},
  {&__pyx_n_Opposite, "Opposite"},
  {&__pyx_n_OwnerGrabButtonMask, "OwnerGrabButtonMask"},
  {&__pyx_n_PAspect, "PAspect"},
  {&__pyx_n_PBaseSize, "PBaseSize"},
  {&__pyx_n_PMaxSize, "PMaxSize"},
  {&__pyx_n_PMinSize, "PMinSize"},
  {&__pyx_n_PPosition, "PPosition"},
  {&__pyx_n_PResizeInc, "PResizeInc"},
  {&__pyx_n_PSize, "PSize"},
  {&__pyx_n_PWinGravity, "PWinGravity"},
  {&__pyx_n_PointerMotionHintMask, "PointerMotionHintMask"},
  {&__pyx_n_PointerMotionMask, "PointerMotionMask"},
  {&__pyx_n_PointerRoot, "PointerRoot"},
  {&__pyx_n_PointerWindow, "PointerWindow"},
  {&__pyx_n_PropModeAppend, "PropModeAppend"},
  {&__pyx_n_PropModePrepend, "PropModePrepend"},
  {&__pyx_n_PropModeReplace, "PropModeReplace"},
  {&__pyx_n_PropertyChangeMask, "PropertyChangeMask"},
  {&__pyx_n_PropertyError, "PropertyError"},
  {&__pyx_n_PropertyNotify, "PropertyNotify"},
  {&__pyx_n_PropertyOverflow, "PropertyOverflow"},
  {&__pyx_n_Region, "Region"},
  {&__pyx_n_ReparentNotify, "ReparentNotify"},
  {&__pyx_n_ResizeRedirectMask, "ResizeRedirectMask"},
  {&__pyx_n_ResizeRequest, "ResizeRequest"},
  {&__pyx_n_RevertToNone, "RevertToNone"},
  {&__pyx_n_RevertToParent, "RevertToParent"},
  {&__pyx_n_RevertToPointerRoot, "RevertToPointerRoot"},
  {&__pyx_n_SelectionClear, "SelectionClear"},
  {&__pyx_n_SelectionNotify, "SelectionNotify"},
  {&__pyx_n_SelectionRequest, "SelectionRequest"},
  {&__pyx_n_StateHint, "StateHint"},
  {&__pyx_n_StructureNotifyMask, "StructureNotifyMask"},
  {&__pyx_n_SubstructureNotifyMask, "SubstructureNotifyMask"},
  {&__pyx_n_SubstructureRedirectMask, "SubstructureRedirectMask"},
  {&__pyx_n_Success, "Success"},
  {&__pyx_n_TopIf, "TopIf"},
  {&__pyx_n_UNMAP, "UNMAP"},
  {&__pyx_n_USPosition, "USPosition"},
  {&__pyx_n_USSize, "USSize"},
  {&__pyx_n_UnmapNotify, "UnmapNotify"},
  {&__pyx_n_VisibilityChangeMask, "VisibilityChangeMask"},
  {&__pyx_n_VisibilityNotify, "VisibilityNotify"},
  {&__pyx_n_Widget, "Widget"},
  {&__pyx_n_Window, "Window"},
  {&__pyx_n_WindowGroupHint, "WindowGroupHint"},
  {&__pyx_n_WithdrawnState, "WithdrawnState"},
  {&__pyx_n_XDamageNotify, "XDamageNotify"},
  {&__pyx_n_XError, "XError"},
  {&__pyx_n_XNone, "XNone"},
  {&__pyx_n_XUrgencyHint, "XUrgencyHint"},
  {&__pyx_n__PixmapCleanupHandler, "_PixmapCleanupHandler"},
  {&__pyx_n___del__, "__del__"},
  {&__pyx_n___init__, "__init__"},
  {&__pyx_n___name__, "__name__"},
  {&__pyx_n__ensure_XComposite_support, "_ensure_XComposite_support"},
  {&__pyx_n__ensure_XDamage_support, "_ensure_XDamage_support"},
  {&__pyx_n__ensure_XTest_support, "_ensure_XTest_support"},
  {&__pyx_n__ev_receiver_key, "_ev_receiver_key"},
  {&__pyx_n__gw, "_gw"},
  {&__pyx_n__maybe_send_event, "_maybe_send_event"},
  {&__pyx_n__munge_packed_ints_to_longs, "_munge_packed_ints_to_longs"},
  {&__pyx_n__munge_packed_longs_to_ints, "_munge_packed_longs_to_ints"},
  {&__pyx_n__query_tree, "_query_tree"},
  {&__pyx_n__route_event, "_route_event"},
  {&__pyx_n__x_event_signals, "_x_event_signals"},
  {&__pyx_n_above, "above"},
  {&__pyx_n_add, "add"},
  {&__pyx_n_addXSelectInput, "addXSelectInput"},
  {&__pyx_n_append, "append"},
  {&__pyx_n_atom, "atom"},
  {&__pyx_n_atom_intern, "atom_intern"},
  {&__pyx_n_base_size, "base_size"},
  {&__pyx_n_border_width, "border_width"},
  {&__pyx_n_call_synced, "call_synced"},
  {&__pyx_n_const, "const"},
  {&__pyx_n_damage, "damage"},
  {&__pyx_n_data, "data"},
  {&__pyx_n_delivered_to, "delivered_to"},
  {&__pyx_n_detail, "detail"},
  {&__pyx_n_discard, "discard"},
  {&__pyx_n_display, "display"},
  {&__pyx_n_dump_exc, "dump_exc"},
  {&__pyx_n_emit, "emit"},
  {&__pyx_n_exc_info, "exc_info"},
  {&__pyx_n_format, "format"},
  {&__pyx_n_gdk, "gdk"},
  {&__pyx_n_get_colormap, "get_colormap"},
  {&__pyx_n_get_data, "get_data"},
  {&__pyx_n_get_default_root_window, "get_default_root_window"},
  {&__pyx_n_get_display, "get_display"},
  {&__pyx_n_get_display_for, "get_display_for"},
  {&__pyx_n_get_pyatom, "get_pyatom"},
  {&__pyx_n_get_pywindow, "get_pywindow"},
  {&__pyx_n_get_xatom, "get_xatom"},
  {&__pyx_n_get_xwindow, "get_xwindow"},
  {&__pyx_n_gobject, "gobject"},
  {&__pyx_n_gtk, "gtk"},
  {&__pyx_n_gtk_main_quit_really, "gtk_main_quit_really"},
  {&__pyx_n_hardware_keycode, "hardware_keycode"},
  {&__pyx_n_height, "height"},
  {&__pyx_n_hex, "hex"},
  {&__pyx_n_i, "i"},
  {&__pyx_n_l, "l"},
  {&__pyx_n_log, "log"},
  {&__pyx_n_max_aspect, "max_aspect"},
  {&__pyx_n_max_size, "max_size"},
  {&__pyx_n_message_type, "message_type"},
  {&__pyx_n_min_aspect, "min_aspect"},
  {&__pyx_n_min_size, "min_size"},
  {&__pyx_n_mode, "mode"},
  {&__pyx_n_object, "object"},
  {&__pyx_n_override_redirect, "override_redirect"},
  {&__pyx_n_pack, "pack"},
  {&__pyx_n_pixmap, "pixmap"},
  {&__pyx_n_pixmap_foreign_new_for_display, "pixmap_foreign_new_for_display"},
  {&__pyx_n_printFocus, "printFocus"},
  {&__pyx_n_range, "range"},
  {&__pyx_n_resize_inc, "resize_inc"},
  {&__pyx_n_sendConfigureNotify, "sendConfigureNotify"},
  {&__pyx_n_send_event, "send_event"},
  {&__pyx_n_serial, "serial"},
  {&__pyx_n_set, "set"},
  {&__pyx_n_set_colormap, "set_colormap"},
  {&__pyx_n_set_data, "set_data"},
  {&__pyx_n_signal_list_names, "signal_list_names"},
  {&__pyx_n_state, "state"},
  {&__pyx_n_struct, "struct"},
  {&__pyx_n_trap, "trap"},
  {&__pyx_n_type, "type"},
  {&__pyx_n_unpack, "unpack"},
  {&__pyx_n_value_mask, "value_mask"},
  {&__pyx_n_warn, "warn"},
  {&__pyx_n_width, "width"},
  {&__pyx_n_window, "window"},
  {&__pyx_n_window_foreign_new_for_display, "window_foreign_new_for_display"},
  {&__pyx_n_x, "x"},
  {&__pyx_n_xid, "xid"},
  {&__pyx_n_y, "y"},
  {0, 0}
};

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_k4p, __pyx_k4, sizeof(__pyx_k4)},
  {&__pyx_k5p, __pyx_k5, sizeof(__pyx_k5)},
  {&__pyx_k9p, __pyx_k9, sizeof(__pyx_k9)},
  {&__pyx_k12p, __pyx_k12, sizeof(__pyx_k12)},
  {&__pyx_k14p, __pyx_k14, sizeof(__pyx_k14)},
  {&__pyx_k163p, __pyx_k163, sizeof(__pyx_k163)},
  {&__pyx_k165p, __pyx_k165, sizeof(__pyx_k165)},
  {&__pyx_k166p, __pyx_k166, sizeof(__pyx_k166)},
  {&__pyx_k167p, __pyx_k167, sizeof(__pyx_k167)},
  {&__pyx_k168p, __pyx_k168, sizeof(__pyx_k168)},
  {&__pyx_k169p, __pyx_k169, sizeof(__pyx_k169)},
  {&__pyx_k170p, __pyx_k170, sizeof(__pyx_k170)},
  {&__pyx_k171p, __pyx_k171, sizeof(__pyx_k171)},
  {&__pyx_k172p, __pyx_k172, sizeof(__pyx_k172)},
  {&__pyx_k173p, __pyx_k173, sizeof(__pyx_k173)},
  {&__pyx_k174p, __pyx_k174, sizeof(__pyx_k174)},
  {&__pyx_k175p, __pyx_k175, sizeof(__pyx_k175)},
  {&__pyx_k176p, __pyx_k176, sizeof(__pyx_k176)},
  {&__pyx_k177p, __pyx_k177, sizeof(__pyx_k177)},
  {&__pyx_k178p, __pyx_k178, sizeof(__pyx_k178)},
  {&__pyx_k179p, __pyx_k179, sizeof(__pyx_k179)},
  {&__pyx_k181p, __pyx_k181, sizeof(__pyx_k181)},
  {&__pyx_k182p, __pyx_k182, sizeof(__pyx_k182)},
  {&__pyx_k183p, __pyx_k183, sizeof(__pyx_k183)},
  {&__pyx_k184p, __pyx_k184, sizeof(__pyx_k184)},
  {&__pyx_k185p, __pyx_k185, sizeof(__pyx_k185)},
  {&__pyx_k186p, __pyx_k186, sizeof(__pyx_k186)},
  {&__pyx_k188p, __pyx_k188, sizeof(__pyx_k188)},
  {&__pyx_k190p, __pyx_k190, sizeof(__pyx_k190)},
  {&__pyx_k192p, __pyx_k192, sizeof(__pyx_k192)},
  {&__pyx_k194p, __pyx_k194, sizeof(__pyx_k194)},
  {&__pyx_k195p, __pyx_k195, sizeof(__pyx_k195)},
  {&__pyx_k196p, __pyx_k196, sizeof(__pyx_k196)},
  {&__pyx_k197p, __pyx_k197, sizeof(__pyx_k197)},
  {&__pyx_k198p, __pyx_k198, sizeof(__pyx_k198)},
  {&__pyx_k199p, __pyx_k199, sizeof(__pyx_k199)},
  {&__pyx_k200p, __pyx_k200, sizeof(__pyx_k200)},
  {&__pyx_k201p, __pyx_k201, sizeof(__pyx_k201)},
  {&__pyx_k202p, __pyx_k202, sizeof(__pyx_k202)},
  {&__pyx_k203p, __pyx_k203, sizeof(__pyx_k203)},
  {&__pyx_k204p, __pyx_k204, sizeof(__pyx_k204)},
  {&__pyx_k205p, __pyx_k205, sizeof(__pyx_k205)},
  {&__pyx_k208p, __pyx_k208, sizeof(__pyx_k208)},
  {&__pyx_k209p, __pyx_k209, sizeof(__pyx_k209)},
  {&__pyx_k210p, __pyx_k210, sizeof(__pyx_k210)},
  {&__pyx_k211p, __pyx_k211, sizeof(__pyx_k211)},
  {&__pyx_k212p, __pyx_k212, sizeof(__pyx_k212)},
  {&__pyx_k213p, __pyx_k213, sizeof(__pyx_k213)},
  {&__pyx_k214p, __pyx_k214, sizeof(__pyx_k214)},
  {&__pyx_k215p, __pyx_k215, sizeof(__pyx_k215)},
  {&__pyx_k216p, __pyx_k216, sizeof(__pyx_k216)},
  {&__pyx_k217p, __pyx_k217, sizeof(__pyx_k217)},
  {&__pyx_k218p, __pyx_k218, sizeof(__pyx_k218)},
  {&__pyx_k219p, __pyx_k219, sizeof(__pyx_k219)},
  {&__pyx_k220p, __pyx_k220, sizeof(__pyx_k220)},
  {&__pyx_k221p, __pyx_k221, sizeof(__pyx_k221)},
  {&__pyx_k222p, __pyx_k222, sizeof(__pyx_k222)},
  {&__pyx_k224p, __pyx_k224, sizeof(__pyx_k224)},
  {&__pyx_k225p, __pyx_k225, sizeof(__pyx_k225)},
  {&__pyx_k226p, __pyx_k226, sizeof(__pyx_k226)},
  {&__pyx_k227p, __pyx_k227, sizeof(__pyx_k227)},
  {&__pyx_k228p, __pyx_k228, sizeof(__pyx_k228)},
  {&__pyx_k229p, __pyx_k229, sizeof(__pyx_k229)},
  {&__pyx_k230p, __pyx_k230, sizeof(__pyx_k230)},
  {&__pyx_k231p, __pyx_k231, sizeof(__pyx_k231)},
  {&__pyx_k232p, __pyx_k232, sizeof(__pyx_k232)},
  {&__pyx_k233p, __pyx_k233, sizeof(__pyx_k233)},
  {&__pyx_k234p, __pyx_k234, sizeof(__pyx_k234)},
  {&__pyx_k235p, __pyx_k235, sizeof(__pyx_k235)},
  {&__pyx_k236p, __pyx_k236, sizeof(__pyx_k236)},
  {&__pyx_k237p, __pyx_k237, sizeof(__pyx_k237)},
  {&__pyx_k238p, __pyx_k238, sizeof(__pyx_k238)},
  {&__pyx_k239p, __pyx_k239, sizeof(__pyx_k239)},
  {&__pyx_k240p, __pyx_k240, sizeof(__pyx_k240)},
  {&__pyx_k241p, __pyx_k241, sizeof(__pyx_k241)},
  {&__pyx_k242p, __pyx_k242, sizeof(__pyx_k242)},
  {&__pyx_k243p, __pyx_k243, sizeof(__pyx_k243)},
  {&__pyx_k244p, __pyx_k244, sizeof(__pyx_k244)},
  {0, 0, 0}
};

static struct PyMethodDef __pyx_methods[] = {
  {"premultiply_argb_in_place", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_premultiply_argb_in_place, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_xwindow", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xwindow, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_pywindow", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pywindow, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_display_for", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_display_for, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_xatom", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_xatom, METH_VARARGS|METH_KEYWORDS, __pyx_doc_8wimpiggy_8lowlevel_8bindings_get_xatom},
  {"get_pyatom", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_pyatom, METH_VARARGS|METH_KEYWORDS, 0},
  {"gdk_atom_objects_from_gdk_atom_array", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_gdk_atom_objects_from_gdk_atom_array, METH_VARARGS|METH_KEYWORDS, 0},
  {"_munge_packed_ints_to_longs", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_ints_to_longs, METH_VARARGS|METH_KEYWORDS, 0},
  {"XChangeProperty", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XChangeProperty, METH_VARARGS|METH_KEYWORDS, __pyx_doc_8wimpiggy_8lowlevel_8bindings_XChangeProperty},
  {"_munge_packed_longs_to_ints", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__munge_packed_longs_to_ints, METH_VARARGS|METH_KEYWORDS, 0},
  {"XGetWindowProperty", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XGetWindowProperty, METH_VARARGS|METH_KEYWORDS, 0},
  {"XDeleteProperty", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XDeleteProperty, METH_VARARGS|METH_KEYWORDS, 0},
  {"XAddToSaveSet", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XAddToSaveSet, METH_VARARGS|METH_KEYWORDS, 0},
  {"XRemoveFromSaveSet", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XRemoveFromSaveSet, METH_VARARGS|METH_KEYWORDS, 0},
  {"_query_tree", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__query_tree, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_children", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_children, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_parent", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_parent, METH_VARARGS|METH_KEYWORDS, 0},
  {"is_mapped", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_is_mapped, METH_VARARGS|METH_KEYWORDS, 0},
  {"is_override_redirect", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_is_override_redirect, METH_VARARGS|METH_KEYWORDS, 0},
  {"geometry_with_border", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_geometry_with_border, METH_VARARGS|METH_KEYWORDS, 0},
  {"XSetInputFocus", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XSetInputFocus, METH_VARARGS|METH_KEYWORDS, 0},
  {"printFocus", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_printFocus, METH_VARARGS|METH_KEYWORDS, 0},
  {"calc_constrained_size", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_calc_constrained_size, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_rectangle_from_region", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_rectangle_from_region, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_modifier_map", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_get_modifier_map, METH_VARARGS|METH_KEYWORDS, 0},
  {"grab_key", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_grab_key, METH_VARARGS|METH_KEYWORDS, 0},
  {"ungrab_all_keys", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_ungrab_all_keys, METH_VARARGS|METH_KEYWORDS, 0},
  {"XKillClient", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_XKillClient, METH_VARARGS|METH_KEYWORDS, 0},
  {"unmap_with_serial", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_unmap_with_serial, METH_VARARGS|METH_KEYWORDS, 0},
  {"show_unraised_without_extra_stupid_stuff", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_show_unraised_without_extra_stupid_stuff, METH_VARARGS|METH_KEYWORDS, 0},
  {"_ensure_XTest_support", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XTest_support, METH_VARARGS|METH_KEYWORDS, 0},
  {"xtest_fake_key", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_key, METH_VARARGS|METH_KEYWORDS, 0},
  {"xtest_fake_button", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xtest_fake_button, METH_VARARGS|METH_KEYWORDS, 0},
  {"_ensure_XComposite_support", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XComposite_support, METH_VARARGS|METH_KEYWORDS, 0},
  {"xcomposite_redirect_window", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_window, METH_VARARGS|METH_KEYWORDS, 0},
  {"xcomposite_redirect_subwindows", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_redirect_subwindows, METH_VARARGS|METH_KEYWORDS, 0},
  {"xcomposite_unredirect_window", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_window, METH_VARARGS|METH_KEYWORDS, 0},
  {"xcomposite_unredirect_subwindows", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_unredirect_subwindows, METH_VARARGS|METH_KEYWORDS, 0},
  {"xcomposite_name_window_pixmap", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xcomposite_name_window_pixmap, METH_VARARGS|METH_KEYWORDS, 0},
  {"_ensure_XDamage_support", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__ensure_XDamage_support, METH_VARARGS|METH_KEYWORDS, 0},
  {"xdamage_start", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_start, METH_VARARGS|METH_KEYWORDS, 0},
  {"xdamage_stop", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_stop, METH_VARARGS|METH_KEYWORDS, 0},
  {"xdamage_acknowledge", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_xdamage_acknowledge, METH_VARARGS|METH_KEYWORDS, 0},
  {"myGetSelectionOwner", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_myGetSelectionOwner, METH_VARARGS|METH_KEYWORDS, 0},
  {"sendClientMessage", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_sendClientMessage, METH_VARARGS|METH_KEYWORDS, 0},
  {"sendConfigureNotify", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_sendConfigureNotify, METH_VARARGS|METH_KEYWORDS, 0},
  {"configureAndNotify", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_configureAndNotify, METH_VARARGS|METH_KEYWORDS, 0},
  {"addXSelectInput", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_addXSelectInput, METH_VARARGS|METH_KEYWORDS, 0},
  {"substructureRedirect", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_substructureRedirect, METH_VARARGS|METH_KEYWORDS, __pyx_doc_8wimpiggy_8lowlevel_8bindings_substructureRedirect},
  {"selectFocusChange", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_selectFocusChange, METH_VARARGS|METH_KEYWORDS, 0},
  {"add_event_receiver", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_add_event_receiver, METH_VARARGS|METH_KEYWORDS, 0},
  {"remove_event_receiver", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings_remove_event_receiver, METH_VARARGS|METH_KEYWORDS, 0},
  {"_maybe_send_event", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__maybe_send_event, METH_VARARGS|METH_KEYWORDS, 0},
  {"_route_event", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__route_event, METH_VARARGS|METH_KEYWORDS, 0},
  {"_gw", (PyCFunction)__pyx_f_8wimpiggy_8lowlevel_8bindings__gw, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC initbindings(void); /*proto*/
PyMODINIT_FUNC initbindings(void) {
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("bindings", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;};

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":11 */
  __pyx_1 = __Pyx_Import(__pyx_n_struct, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_struct, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 11; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":13 */
  __pyx_1 = __Pyx_Import(__pyx_n_gobject, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 13; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_gobject, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 13; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":14 */
  __pyx_1 = __Pyx_Import(__pyx_n_gtk, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 14; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_gtk, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 14; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":15 */
  __pyx_1 = __Pyx_Import(__pyx_k4p, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 15; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_gtk, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 15; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":17 */
  __pyx_1 = PyList_New(3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_INCREF(__pyx_n_dump_exc);
  PyList_SET_ITEM(__pyx_1, 0, __pyx_n_dump_exc);
  Py_INCREF(__pyx_n_LameStruct);
  PyList_SET_ITEM(__pyx_1, 1, __pyx_n_LameStruct);
  Py_INCREF(__pyx_n_gtk_main_quit_really);
  PyList_SET_ITEM(__pyx_1, 2, __pyx_n_gtk_main_quit_really);
  __pyx_2 = __Pyx_Import(__pyx_k5p, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_dump_exc); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_dump_exc, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_LameStruct); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_LameStruct, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_gtk_main_quit_really); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_gtk_main_quit_really, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 17; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":18 */
  __pyx_2 = PyList_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_INCREF(__pyx_n_trap);
  PyList_SET_ITEM(__pyx_2, 0, __pyx_n_trap);
  Py_INCREF(__pyx_n_XError);
  PyList_SET_ITEM(__pyx_2, 1, __pyx_n_XError);
  __pyx_1 = __Pyx_Import(__pyx_k9p, __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_trap); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_trap, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_XError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_XError, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 18; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":20 */
  __pyx_1 = PyList_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  Py_INCREF(__pyx_n_Logger);
  PyList_SET_ITEM(__pyx_1, 0, __pyx_n_Logger);
  __pyx_2 = __Pyx_Import(__pyx_k12p, __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_Logger); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_Logger, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":21 */
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_Logger); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  Py_INCREF(__pyx_k14p);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k14p);
  __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_log, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 21; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":50 */
  init_pygobject();

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":54 */
  init_pygtk();

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/constants.pxi":144 */
  __pyx_2 = PyDict_New(); if (!__pyx_2) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  __pyx_1 = PyLong_FromUnsignedLong(None); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 145; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_XNone, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PointerWindow); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 146; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PointerWindow, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(InputFocus); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 147; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_InputFocus, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PointerRoot); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 148; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PointerRoot, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CurrentTime); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 149; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CurrentTime, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(IsUnmapped); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 150; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IsUnmapped, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(IsUnviewable); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 151; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IsUnviewable, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(IsViewable); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 152; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IsViewable, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NoEventMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 153; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NoEventMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(KeyPressMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 154; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeyPressMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(KeyReleaseMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 155; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeyReleaseMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ButtonPressMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 156; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ButtonPressMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ButtonReleaseMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 157; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ButtonReleaseMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(EnterWindowMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 158; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_EnterWindowMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(LeaveWindowMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 159; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_LeaveWindowMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PointerMotionMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 160; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PointerMotionMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PointerMotionHintMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 161; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PointerMotionHintMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(Button1MotionMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 162; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Button1MotionMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(Button2MotionMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 163; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Button2MotionMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(Button3MotionMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 164; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Button3MotionMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(Button4MotionMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 165; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Button4MotionMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(Button5MotionMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 166; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Button5MotionMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ButtonMotionMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 167; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ButtonMotionMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(KeymapStateMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 168; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeymapStateMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ExposureMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 169; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ExposureMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(VisibilityChangeMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 170; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_VisibilityChangeMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(StructureNotifyMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 171; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_StructureNotifyMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ResizeRedirectMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 172; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ResizeRedirectMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(SubstructureNotifyMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 173; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_SubstructureNotifyMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(SubstructureRedirectMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 174; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_SubstructureRedirectMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(FocusChangeMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 175; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_FocusChangeMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PropertyChangeMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 176; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PropertyChangeMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ColormapChangeMask); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 177; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ColormapChangeMask, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(OwnerGrabButtonMask); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 178; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_OwnerGrabButtonMask, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(KeyPress); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 179; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeyPress, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(KeyRelease); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 180; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeyRelease, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ButtonPress); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 181; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ButtonPress, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ButtonRelease); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 182; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ButtonRelease, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(MotionNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 183; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_MotionNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(EnterNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 184; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_EnterNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(LeaveNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 185; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_LeaveNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(FocusIn); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 186; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_FocusIn, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(FocusOut); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 187; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_FocusOut, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(KeymapNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 188; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_KeymapNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(Expose); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 189; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Expose, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(GraphicsExpose); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 190; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_GraphicsExpose, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NoExpose); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 191; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NoExpose, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(VisibilityNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 192; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_VisibilityNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CreateNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 193; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CreateNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(DestroyNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 194; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_DestroyNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(UnmapNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 195; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_UnmapNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(MapNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 196; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_MapNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(MapRequest); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 197; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_MapRequest, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ReparentNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 198; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ReparentNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ConfigureNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 199; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ConfigureNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ConfigureRequest); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 200; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ConfigureRequest, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(GravityNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 201; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_GravityNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ResizeRequest); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 202; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ResizeRequest, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CirculateNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 203; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CirculateNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(CirculateRequest); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 204; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CirculateRequest, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PropertyNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 205; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PropertyNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(SelectionClear); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 206; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_SelectionClear, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(SelectionRequest); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 207; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_SelectionRequest, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(SelectionNotify); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 208; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_SelectionNotify, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ColormapNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 209; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ColormapNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(ClientMessage); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 210; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_ClientMessage, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(MappingNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 211; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_MappingNotify, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(LASTEvent); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 212; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_LASTEvent, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PropModeReplace); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 213; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PropModeReplace, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PropModePrepend); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 214; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PropModePrepend, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PropModeAppend); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 215; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PropModeAppend, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(CWX); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 216; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWX, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CWY); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 217; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWY, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(CWWidth); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 218; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWWidth, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CWHeight); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 219; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWHeight, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(CWBorderWidth); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 220; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWBorderWidth, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(CWSibling); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 221; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWSibling, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(CWStackMode); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 222; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_CWStackMode, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(Above); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 223; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Above, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(Below); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 224; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Below, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BottomIf); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 225; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BottomIf, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(TopIf); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 226; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_TopIf, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(Opposite); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 227; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Opposite, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(Success); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 228; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_Success, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadRequest); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 229; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadRequest, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadValue); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 230; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadValue, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadWindow); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 231; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadWindow, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadPixmap); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 232; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadPixmap, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadAtom); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 233; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadAtom, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadCursor); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 234; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadCursor, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadFont); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 235; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadFont, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadMatch); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 236; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadMatch, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadDrawable); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 237; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadDrawable, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadAccess); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 238; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadAccess, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadAlloc); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 239; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadAlloc, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadColor); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 240; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadColor, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadGC); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 241; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadGC, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadIDChoice); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 242; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadIDChoice, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadName); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 243; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadName, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(BadLength); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 244; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadLength, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(BadImplementation); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 245; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_BadImplementation, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(FirstExtensionError); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 246; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_FirstExtensionError, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(LastExtensionError); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 247; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_LastExtensionError, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(USPosition); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 248; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_USPosition, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(USSize); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 249; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_USSize, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PPosition); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 250; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PPosition, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PSize); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 251; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PSize, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PMinSize); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 252; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PMinSize, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PMaxSize); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 253; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PMaxSize, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PResizeInc); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 254; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PResizeInc, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PAspect); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 255; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PAspect, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(PBaseSize); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 256; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PBaseSize, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PWinGravity); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 257; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_PWinGravity, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(InputHint); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 258; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_InputHint, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(StateHint); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 259; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_StateHint, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(IconPixmapHint); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 260; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IconPixmapHint, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(IconWindowHint); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 261; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IconWindowHint, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(IconPositionHint); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 262; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IconPositionHint, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(IconMaskHint); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 263; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IconMaskHint, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(WindowGroupHint); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 264; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_WindowGroupHint, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(XUrgencyHint); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 265; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_XUrgencyHint, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(WithdrawnState); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_WithdrawnState, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NormalState); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 267; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NormalState, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(IconicState); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 268; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_IconicState, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(RevertToParent); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 269; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_RevertToParent, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(RevertToPointerRoot); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 270; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_RevertToPointerRoot, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(RevertToNone); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 271; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_RevertToNone, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyNormal); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 272; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyNormal, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NotifyGrab); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 273; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyGrab, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyUngrab); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 274; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyUngrab, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NotifyAncestor); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 275; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyAncestor, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyVirtual); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 276; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyVirtual, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NotifyInferior); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 277; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyInferior, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyNonlinear); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 278; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyNonlinear, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NotifyNonlinearVirtual); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 279; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyNonlinearVirtual, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyPointer); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 280; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyPointer, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(NotifyPointerRoot); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 281; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyPointerRoot, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(NotifyDetailNone); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 282; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_NotifyDetailNone, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(GrabModeSync); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 283; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_GrabModeSync, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(GrabModeAsync); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 284; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_GrabModeAsync, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(AnyKey); if (!__pyx_1) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 285; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_AnyKey, __pyx_1) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyLong_FromUnsignedLong(AnyModifier); if (!__pyx_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 286; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_2, __pyx_n_AnyModifier, __pyx_3) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_const, __pyx_2) < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 144; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":442 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 442; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 442; goto __pyx_L1;}
  Py_INCREF(PyExc_Exception);
  PyTuple_SET_ITEM(__pyx_3, 0, PyExc_Exception);
  __pyx_2 = __Pyx_CreateClass(__pyx_3, __pyx_1, __pyx_n_PropertyError, "wimpiggy.lowlevel.bindings"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 442; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_PropertyError, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 442; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":444 */
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_PropertyError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = __Pyx_CreateClass(__pyx_1, __pyx_3, __pyx_n_BadPropertyType, "wimpiggy.lowlevel.bindings"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_BadPropertyType, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 444; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":446 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_PropertyError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = __Pyx_CreateClass(__pyx_3, __pyx_1, __pyx_n_PropertyOverflow, "wimpiggy.lowlevel.bindings"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_PropertyOverflow, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 446; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":448 */
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 448; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_PropertyError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 448; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 448; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = __Pyx_CreateClass(__pyx_1, __pyx_3, __pyx_n_NoSuchProperty, "wimpiggy.lowlevel.bindings"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 448; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_NoSuchProperty, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 448; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":576 */
  Py_INCREF(Py_None);
  __pyx_k161 = Py_None;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":838 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_object); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
  __pyx_2 = 0;
  if (PyDict_SetItemString(__pyx_1, "__doc__", __pyx_k163p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  __pyx_2 = __Pyx_CreateClass(__pyx_3, __pyx_1, __pyx_n__PixmapCleanupHandler, "wimpiggy.lowlevel.bindings"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":840 */
  __pyx_3 = PyCFunction_New(&__pyx_mdef_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___init__, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 840; goto __pyx_L1;}
  __pyx_4 = PyMethod_New(__pyx_3, 0, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 840; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_2, __pyx_n___init__, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 840; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":843 */
  __pyx_3 = PyCFunction_New(&__pyx_mdef_8wimpiggy_8lowlevel_8bindings_21_PixmapCleanupHandler___del__, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 843; goto __pyx_L1;}
  __pyx_4 = PyMethod_New(__pyx_3, 0, __pyx_2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 843; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_2, __pyx_n___del__, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 843; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n__PixmapCleanupHandler, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 838; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1006 */
  Py_INCREF(Py_None);
  __pyx_k164 = Py_None;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1128 */
  if (PyObject_SetAttr(__pyx_m, __pyx_n__ev_receiver_key, __pyx_k165p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1128; goto __pyx_L1;}

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1186 */
  __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  __pyx_4 = PyLong_FromUnsignedLong(MapRequest); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1187; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1187; goto __pyx_L1;}
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_2, 0, Py_None);
  Py_INCREF(__pyx_k166p);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_k166p);
  if (PyDict_SetItem(__pyx_3, __pyx_4, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ConfigureRequest); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1188; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1188; goto __pyx_L1;}
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_4, 0, Py_None);
  Py_INCREF(__pyx_k167p);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_k167p);
  if (PyDict_SetItem(__pyx_3, __pyx_1, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(FocusIn); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1189; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1189; goto __pyx_L1;}
  Py_INCREF(__pyx_k168p);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k168p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_1, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_2, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyLong_FromUnsignedLong(FocusOut); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1190; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1190; goto __pyx_L1;}
  Py_INCREF(__pyx_k169p);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k169p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_2, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_4, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(ClientMessage); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1191; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1191; goto __pyx_L1;}
  Py_INCREF(__pyx_k170p);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k170p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_4, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_1, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(MapNotify); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1192; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1192; goto __pyx_L1;}
  Py_INCREF(__pyx_k171p);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k171p);
  Py_INCREF(__pyx_k172p);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_k172p);
  if (PyDict_SetItem(__pyx_3, __pyx_2, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyLong_FromUnsignedLong(UnmapNotify); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1193; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1193; goto __pyx_L1;}
  Py_INCREF(__pyx_k173p);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k173p);
  Py_INCREF(__pyx_k174p);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_k174p);
  if (PyDict_SetItem(__pyx_3, __pyx_4, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(DestroyNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1194; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1194; goto __pyx_L1;}
  Py_INCREF(__pyx_k175p);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k175p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_4, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_1, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(ConfigureNotify); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1195; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1195; goto __pyx_L1;}
  Py_INCREF(__pyx_k176p);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k176p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_1, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_2, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyLong_FromUnsignedLong(ReparentNotify); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1196; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1196; goto __pyx_L1;}
  Py_INCREF(__pyx_k177p);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_k177p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_2, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_4, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_1 = PyLong_FromUnsignedLong(PropertyNotify); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1197; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1197; goto __pyx_L1;}
  Py_INCREF(__pyx_k178p);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k178p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_4, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_1, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(KeyPress); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1198; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1198; goto __pyx_L1;}
  Py_INCREF(__pyx_k179p);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_k179p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_1, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_2, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1199; goto __pyx_L1;}
  Py_INCREF(__pyx_k181p);
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_k181p);
  Py_INCREF(Py_None);
  PyTuple_SET_ITEM(__pyx_4, 1, Py_None);
  if (PyDict_SetItem(__pyx_3, __pyx_n_XDamageNotify, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n__x_event_signals, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1186; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/tmp/parti-all-0.0.6/wimpiggy/lowlevel/wimpiggy.lowlevel.bindings.pyx":1336 */
  gdk_window_add_filter(((GdkWindow *)0),__pyx_f_8wimpiggy_8lowlevel_8bindings_x_event_filter,((void *)0));
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("wimpiggy.lowlevel.bindings");
}

static char *__pyx_filenames[] = {
  "wimpiggy.lowlevel.bindings.pyx",
  "constants.pxi",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = PyObject_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunction(__import__, "OOOO",
        name, global_dict, empty_dict, list);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static PyObject *__Pyx_CreateClass(
    PyObject *bases, PyObject *dict, PyObject *name, char *modname)
{
    PyObject *py_modname;
    PyObject *result = 0;
    
    py_modname = PyString_FromString(modname);
    if (!py_modname)
        goto bad;
    if (PyDict_SetItemString(dict, "__module__", py_modname) < 0)
        goto bad;
    result = PyClass_New(bases, dict, name);
bad:
    Py_XDECREF(py_modname);
    return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    /* First, check the traceback argument, replacing None with NULL. */
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    /* Next, replace a missing value with None */
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    #if PY_VERSION_HEX < 0x02050000
    if (!PyClass_Check(type))
    #else
    if (!PyType_Check(type))
    #endif
    {
        /* Raising an instance.  The value should be a dummy. */
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        /* Normalize to raise <class>, <instance> */
        Py_DECREF(value);
        value = type;
        #if PY_VERSION_HEX < 0x02050000
            if (PyInstance_Check(type)) {
                type = (PyObject*) ((PyInstanceObject*)type)->in_class;
                Py_INCREF(type);
            }
            else {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception must be an old-style class or instance");
                goto raise_error;
            }
        #else
            type = (PyObject*) type->ob_type;
            Py_INCREF(type);
            if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception class must be a subclass of BaseException");
                goto raise_error;
            }
        #endif
    }
    PyErr_Restore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

static void __Pyx_WriteUnraisable(char *name) {
    PyObject *old_exc, *old_val, *old_tb;
    PyObject *ctx;
    PyErr_Fetch(&old_exc, &old_val, &old_tb);
    ctx = PyString_FromString(name);
    PyErr_Restore(old_exc, old_val, old_tb);
    if (!ctx)
        ctx = Py_None;
    PyErr_WriteUnraisable(ctx);
}

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i) {
    PyTypeObject *t = o->ob_type;
    PyObject *r;
    if (t->tp_as_sequence && t->tp_as_sequence->sq_item)
        r = PySequence_GetItem(o, i);
    else {
        PyObject *j = PyInt_FromLong(i);
        if (!j)
            return 0;
        r = PyObject_GetItem(o, j);
        Py_DECREF(j);
    }
    return r;
}

static int __Pyx_SetItemInt(PyObject *o, Py_ssize_t i, PyObject *v) {
    PyTypeObject *t = o->ob_type;
    int r;
    if (t->tp_as_sequence && t->tp_as_sequence->sq_item)
        r = PySequence_SetItem(o, i, v);
    else {
        PyObject *j = PyInt_FromLong(i);
        if (!j)
            return -1;
        r = PyObject_SetItem(o, j, v);
        Py_DECREF(j);
    }
    return r;
}

static void __Pyx_UnpackError(void) {
    PyErr_SetString(PyExc_ValueError, "unpack sequence of wrong size");
}

static PyObject *__Pyx_UnpackItem(PyObject *iter) {
    PyObject *item;
    if (!(item = PyIter_Next(iter))) {
        if (!PyErr_Occurred())
            __Pyx_UnpackError();
    }
    return item;
}

static int __Pyx_EndUnpack(PyObject *iter) {
    PyObject *item;
    if ((item = PyIter_Next(iter))) {
        Py_DECREF(item);
        __Pyx_UnpackError();
        return -1;
    }
    else if (!PyErr_Occurred())
        return 0;
    else
        return -1;
}

static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb) {
    PyThreadState *tstate = PyThreadState_Get();
    PyErr_Fetch(type, value, tb);
    PyErr_NormalizeException(type, value, tb);
    if (PyErr_Occurred())
        goto bad;
    Py_INCREF(*type);
    Py_INCREF(*value);
    Py_INCREF(*tb);
    Py_XDECREF(tstate->exc_type);
    Py_XDECREF(tstate->exc_value);
    Py_XDECREF(tstate->exc_traceback);
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    return 0;
bad:
    Py_XDECREF(*type);
    Py_XDECREF(*value);
    Py_XDECREF(*tb);
    return -1;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_tuple = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    py_funcname = PyString_FromString(funcname);
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_tuple = PyTuple_New(0);
    if (!empty_tuple) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        empty_tuple,  /*PyObject *consts,*/
        empty_tuple,  /*PyObject *names,*/
        empty_tuple,  /*PyObject *varnames,*/
        empty_tuple,  /*PyObject *freevars,*/
        empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_tuple);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}
