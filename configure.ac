dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(octetos-db, 0.3.0-alpha)
AC_CANONICAL_SYSTEM
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

AM_PROG_AS
AC_LANG_CPLUSPLUS
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL


dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=octetos-db
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT



dnl ***************************************************************************
dnl Check for Windows
dnl ***************************************************************************
AC_CANONICAL_HOST

case $host_os in
  *mingw*)
    platform_win32=yes
    native_win32=yes
    ;;
  pw32* | *cygwin*)
    platform_win32=yes
    native_win32=no
    ;;
  *)
    platform_win32=no
    native_win32=no
    ;;
esac
AM_CONDITIONAL(PLATFORM_WIN32, test x"$platform_win32" = "xyes")
AM_CONDITIONAL(NATIVE_WIN32, test x"$native_win32" = "xyes")


LT_INIT([win32-dll])


PKG_CHECK_MODULES(MYSQLCLIENT,mysqlclient)
PKG_CHECK_MODULES(DBI,dbi)
PKG_CHECK_MODULES(CPPUNIT,cppunit)
PKG_CHECK_MODULES(OCTETOS_CORE, octetos-core, OCTETOS_CORE_found=1, OCTETOS_CORE_found=0)
if test $OCTETOS_CORE_found = 0; then
	AC_MSG_ERROR(Error could not find library (Octetos Core) pkg-config file is it installed?)
fi


AC_OUTPUT([
Makefile
src/octetos-db.pc
src/Makefile
po/Makefile.in])