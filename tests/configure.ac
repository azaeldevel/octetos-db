

AC_INIT(tests,1.3.10-alpha,azael.devel@gmail.com)
AC_CONFIG_AUX_DIR([.])

AM_INIT_AUTOMAKE


AM_PROG_AS
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET

  
AM_CONDITIONAL(WITH_MARIADB, test x"$with_mariadb" = "xyes")
AC_ARG_WITH([mariadb], AS_HELP_STRING([--with-mariadb], [Compilando con soporte para MariaDB.]))


AM_CONDITIONAL(WITH_POSTGRESQL, test x"$with_postgresql" = "xyes")
AC_ARG_WITH([postgresql], AS_HELP_STRING([--with-postgresql], [Compilando con soporte para PostgreSQL.]))



AC_CONFIG_FILES([Makefile])

AC_OUTPUT
