AC_INIT([ledborg-server], [0.2.1], [the.mighty.ug@gmail.com], [ledborg-server])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([dist-bzip2])
AM_MAINTAINER_MODE

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AM_PROG_CC_C_O
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

AC_PATH_PROG(VALAC, valac, valac)
AC_SUBST(VALAC)

AH_TEMPLATE([GETTEXT_PACKAGE], [Package name for gettext])
GETTEXT_PACKAGE=ledborg-server
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE")
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.35.0])


AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)


GLIB_REQUIRED=2.12.0

PKG_CHECK_MODULES(GLIB, [glib-2.0 >= $GLIB_REQUIRED])
PKG_CHECK_MODULES(GOBJECT, [gobject-2.0 >= $GLIB_REQUIRED])
PKG_CHECK_MODULES(GIO, [gio-2.0 >= $GLIB_REQUIRED])
PKG_CHECK_MODULES(LIBSOUP, [libsoup-2.4])

LEDBORG_SERVER_CFLAGS="$GLIB_CFLAGS $GOBJECT_CFLAGS $GIO_CFLAGS $LIBSOUP_CFLAGS"
LEDBORG_SERVER_LIBS="$GLIB_LIBS $GOBJECT_LIBS $GIO_LIBS $LIBSOUP_LIBS"
AC_SUBST(LEDBORG_SERVER_CFLAGS)
AC_SUBST(LEDBORG_SERVER_LIBS)


AC_ARG_ENABLE(applet,
  [  --disable-applet   Disable compilation of the gnome ledborg control applet],
  [case "${enableval}" in
     yes | no ) WITH_APPLET="${enableval}" ;;
     *) AC_MSG_ERROR(bad value ${enableval} for --disable-applet) ;;
   esac],
  [WITH_APPLET="yes"]
)
AM_CONDITIONAL([WITH_APPLET], [test "x$WITH_APPLET" = "xyes"])
if test "x$WITH_APPLET" = "xyes"; then
	AC_MSG_NOTICE([LedBorg control applet for gnome will be built])
	makefile_applet=src/applet/Makefile
else
    AC_MSG_NOTICE([LedBorg control applet will NOT be built])
fi

AC_ARG_ENABLE(rpi,
  [  --disable-rpi   Disable raspberry pi compiler optimisations],
  [case "${enableval}" in
     yes | no ) WITH_RPI="${enableval}" ;;
     *) AC_MSG_ERROR(bad value ${enableval} for --disable-rpi) ;;
   esac],
  [WITH_RPI="yes"]
)
AM_CONDITIONAL([WITH_RPI], [test "x$WITH_RPI" = "xyes"])
if test "x$WITH_RPI" = "xyes"; then
	AC_MSG_NOTICE([enabled Raspberry Pi compiler optimisations. THIS WILL ALMOST CERTAINLY FAIL ON ANY OTHER MACHINE! Use --disable-rpi to compile on other machines/architectures])
fi


#AC_DEFINE_UNQUOTED([sysconfdir], ["$sysconfdir"], [Configuration directory])

LT_INIT

AC_CONFIG_FILES([Makefile
	src/lib/Makefile
	src/Makefile
	$makefile_applet
	po/Makefile.in])

AC_OUTPUT
