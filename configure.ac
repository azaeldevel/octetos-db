

AC_INIT(octetos-db,1.4.0-alpha,azael.devel@gmail.com)
AC_CONFIG_AUX_DIR([.])
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



  

AC_CONFIG_FILES([Makefile])

AC_CONFIG_SUBDIRS([abstract])

if test "x$with_postgresql" = "xyes"; then
   	AC_CONFIG_SUBDIRS([postgresql])
fi
if test "x$with_mariadb" = "xyes"; then
   	AC_CONFIG_SUBDIRS([mariadb])
fi
if test "x$with_tests" = "xyes"; then
	AC_CONFIG_SUBDIRS([tests])
fi

AC_OUTPUT
