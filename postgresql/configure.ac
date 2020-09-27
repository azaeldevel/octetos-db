

AC_INIT(octetos-db-postgresql,1.3.10-alpha,azael.devel@gmail.com)
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









AM_CONDITIONAL(WITH_POSTGRESQL, test x"$with_postgresql" = "xyes")
AC_ARG_WITH([postgresql], AS_HELP_STRING([--with-postgresql], [Compilando con soporte para PostgreSQL.]))
if test "x$with_postgresql" = "xyes"; then
   	PKG_CHECK_MODULES(LIBPQ,libpq)
fi



  

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([octetos-db-postgresql.pc])

AC_OUTPUT
