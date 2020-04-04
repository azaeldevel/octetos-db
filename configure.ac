dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(octetos-db,1.2.2-alpha.5,zael.devel@gmail.com)
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

PKG_CHECK_MODULES(OCTETOS_CORE, octetos-core)

AM_CONDITIONAL(WITH_MYSQL, test x"$with_mysql" = "xyes")
AC_ARG_WITH([mysql], AS_HELP_STRING([--with-mysql], [Compilando con soporte para MySQL.]))
if test "x$with_mysql" = "xyes"; then
   	PKG_CHECK_MODULES(MYSQLCLIENT,libmysqlclient)
fi

AM_CONDITIONAL(WITH_MARIADB, test x"$with_mariadb" = "xyes")
AC_ARG_WITH([mariadb], AS_HELP_STRING([--with-mariadb], [Compilando con soporte para MariaDB.]))
if test "x$with_mariadb" = "xyes"; then
   	PKG_CHECK_MODULES(MARIADB,libmariadb)
fi

AM_CONDITIONAL(WITH_POSTGRESQL, test x"$with_postgresql" = "xyes")
AC_ARG_WITH([postgresql], AS_HELP_STRING([--with-postgresql], [Compilando con soporte para PostgreSQL.]))
if test "x$with_postgresql" = "xyes"; then
   	PKG_CHECK_MODULES(LIBPQ,libpq)
fi

AM_CONDITIONAL(WITH_DBI, test x"$with_dbi" = "xyes")
AC_ARG_WITH([dbi], AS_HELP_STRING([--with-dbi], [Compilando con soporte para DBI.]))
if test "x$with_dbi" = "xyes"; then
	PKG_CHECK_MODULES(DBI,dbi)
fi

AM_CONDITIONAL(WITH_TESTS, test x"$with_tests" = "xyes")
AC_ARG_WITH([tests], AS_HELP_STRING([--with-tests], [Compilando con soporte para Pruebas.]))
if test "x$with_tests" = "xyes"; then
	PKG_CHECK_MODULES(CUNIT,cunit)
fi

AC_OUTPUT([
Makefile
src/octetos-db.pc
src/octetos-db-mysql.pc
src/octetos-db-postgresql.pc
src/octetos-db-maria.pc
src/Makefile
tests/Makefile
po/Makefile.in])
