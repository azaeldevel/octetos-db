

AC_INIT(octetos-db-maria,1.3.10-alpha,azael.devel@gmail.com)
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE


AM_PROG_AS
AC_LANG_CPLUSPLUS
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL









AM_CONDITIONAL(WITH_MARIADB, test x"$with_mariadb" = "xyes")
AC_ARG_WITH([mariadb], AS_HELP_STRING([--with-mariadb], [Compilando con soporte para MariaDB.]))
if test "x$with_mariadb" = "xyes"; then
   	PKG_CHECK_MODULES(MARIADB,libmariadb)
fi



  

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([octetos-db-maria.pc])

AC_OUTPUT
