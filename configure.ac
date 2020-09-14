dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.


AC_INIT(octetos-db,1.3.10-alpha,zael.devel@gmail.com)
AC_CANONICAL_SYSTEM
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([gnu subdir-objects])
AM_SILENT_RULES([yes])

AM_PROG_AS
AC_LANG_CPLUSPLUS
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL







PKG_CHECK_MODULES(OCTETOS_CORE, octetos-core)



SLECTED_COMP=None

AM_CONDITIONAL(WITH_ABSTRACT, test x"$with_abstract" = "xyes")
AC_ARG_WITH([abstract], AS_HELP_STRING([--with-abstract], [Compilando con soporte para Pruebas.]))
if test "x$with_abstract" = "xyes"; then
	SLECTED_COMP=Abstract
fi

AM_CONDITIONAL(WITH_MYSQL, test x"$with_mysql" = "xyes")
AC_ARG_WITH([mysql], AS_HELP_STRING([--with-mysql], [Compilando con soporte para MySQL.]))
if test "x$with_mysql" = "xyes"; then
   	PKG_CHECK_MODULES(MYSQLCLIENT,libmysqlclient)
	SLECTED_COMP=MySQL
fi

AM_CONDITIONAL(WITH_MARIADB, test x"$with_mariadb" = "xyes")
AC_ARG_WITH([mariadb], AS_HELP_STRING([--with-mariadb], [Compilando con soporte para MariaDB.]))
if test "x$with_mariadb" = "xyes"; then
   	PKG_CHECK_MODULES(MARIADB,libmariadb)
	SLECTED_COMP=MariaDB
fi

AM_CONDITIONAL(WITH_POSTGRESQL, test x"$with_postgresql" = "xyes")
AC_ARG_WITH([postgresql], AS_HELP_STRING([--with-postgresql], [Compilando con soporte para PostgreSQL.]))
if test "x$with_postgresql" = "xyes"; then
   	PKG_CHECK_MODULES(LIBPQ,libpq)
	SLECTED_COMP=PostgreSQL
fi

AM_CONDITIONAL(WITH_DBI, test x"$with_dbi" = "xyes")
AC_ARG_WITH([dbi], AS_HELP_STRING([--with-dbi], [Compilando con soporte para DBI.]))
if test "x$with_dbi" = "xyes"; then
	PKG_CHECK_MODULES(DBI,dbi)
	SLECTED_COMP=DBI
fi

if [$SLECTED_COMP == None]; then
	echo "Use : "
  	echo "	--with-abstract			Para el componete de API Abstracta."
  	echo "	--with-mysql			Para el componete de MySQL."
  	echo "	--with-mariadb			Para el componete de MariaDB"
  	echo "	--with-postrgresql		Para el componete de PostgreSQL"
  	#echo "Use --with-dbi				Para el componete de DBI."
  	AC_MSG_ERROR([Se deve incar un componete para inicar la compilacion])
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
])
