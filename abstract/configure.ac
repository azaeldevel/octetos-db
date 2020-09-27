

AC_INIT(octetos-db,1.3.10-alpha,azael.devel@gmail.com)
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







PKG_CHECK_MODULES(OCTETOS_CORE, octetos-core)





AM_CONDITIONAL(WITH_ABSTRACT, test x"$with_abstract" = "xyes")
AC_ARG_WITH([abstract], AS_HELP_STRING([--with-abstract], [Compilando con soporte para Pruebas.]))




  

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([octetos-db.pc])

AC_OUTPUT
