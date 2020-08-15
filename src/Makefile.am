AUTOMAKE_OPTIONS=foreign 1.4


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CPPUNIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g




if WITH_ABSTRACT
lib_LTLIBRARIES = liboctetos-db.la
endif
if WITH_MYSQL
lib_LTLIBRARIES = liboctetos-db-mysql.la
endif
if WITH_POSTGRESQL
lib_LTLIBRARIES = liboctetos-db-postgresql.la 
endif
if WITH_DBI
lib_LTLIBRARIES = liboctetos-db-dbi.la 
endif
if WITH_MARIADB
lib_LTLIBRARIES = liboctetos-db-maria.la
endif



if WITH_MYSQL
liboctetos_db_mysql_la_LDFLAGS= 
liboctetos_db_mysql_la_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_LIBDADD = $(MYSQLCLIENT_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_mysql_la_SOURCES = clientdb-mysql.cc clientdb.cc
endif 
if WITH_MARIADB
liboctetos_db_maria_la_LDFLAGS= 
liboctetos_db_maria_la_CFLAGS = $(MARIADB_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_maria_la_CPPFLAGS = $(MARIADB_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_maria_la_LIBDADD = $(MARIADB_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_maria_la_SOURCES = clientdb-maria.cc clientdb.cc
endif
if WITH_DBI
liboctetos_db_dbi_la_LDFLAGS= 
liboctetos_db_dbi_la_CFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
liboctetos_db_dbi_la_CPPFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
liboctetos_db_dbi_la_LIBDADD = $(DBI_LIBS) $(OCTETOS_CORE_CC_LIBS)
liboctetos_db_dbi_la_SOURCES = clientdb-dbi.cc clientdb.cc
endif 
if WITH_POSTGRESQL
liboctetos_db_postgresql_la_LDFLAGS= 
liboctetos_db_postgresql_la_CFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_postgresql_la_CPPFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_postgresql_la_LIBDADD = $(LIBPQ_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_postgresql_la_SOURCES = clientdb-postgresql.cc clientdb.cc
endif
if WITH_ABSTRACT
liboctetos_db_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_la_SOURCES = clientdb.cc
endif




if WITH_ABSTRACT
includeHEADERS = clientdb.hh
pkgDATA = octetos-db.pc
extraDist = octetos-db.pc.in
endif
if WITH_MYSQL
pkgDATA = octetos-db-mysql.pc
extraDist = octetos-db-mysql.pc.in
includeHEADERS = clientdb-mysql.hh
endif
if WITH_MARIADB
pkgDATA = octetos-db-maria.pc
extraDist = octetos-db-maria.pc.in
includeHEADERS = clientdb-maria.hh
endif
if WITH_POSTGRESQL
pkgDATA = octetos-db-postgresql.pc
extraDist = octetos-db-postgresql.pc.in
includeHEADERS = clientdb-postgresql.hh
endif

octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = $(includeHEADERS)
pkgconfig_DATA = $(pkgDATA)
EXTRA_DIST = $(extraDist)