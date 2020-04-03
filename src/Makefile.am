AUTOMAKE_OPTIONS=foreign 1.4

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CPPUNIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liboctetos-db.la
if WITH_MYSQL
lib_LTLIBRARIES += liboctetos-db-mysql.la
endif
if WITH_DBI
lib_LTLIBRARIES += liboctetos-db-dbi.la 
endif
if WITH_POSTGRESQL
lib_LTLIBRARIES += liboctetos-db-postgresql.la 
endif
if WITH_MARIADB
lib_LTLIBRARIES += liboctetos-db-maria.la
endif


liboctetos_db_la_LDFLAGS = -z now
if PLATFORM_WIN32
liboctetos_db_la_LDFLAGS += -no-undefined
endif
if NATIVE_WIN32
liboctetos_db_la_LDFLAGS += -export-dynamic
endif
liboctetos_db_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_la_SOURCES = clientdb.cc

if WITH_MYSQL
liboctetos_db_mysql_la_LDFLAGS= 
liboctetos_db_mysql_la_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_LIBDADD = $(MYSQLCLIENT_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_mysql_la_SOURCES = clientdb-mysql.cc 
endif

if WITH_MARIADB
liboctetos_db_maria_la_LDFLAGS= 
liboctetos_db_maria_la_CFLAGS = $(MARIADB_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_maria_la_CPPFLAGS = $(MARIADB_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_maria_la_LIBDADD = $(MARIADB_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_maria_la_SOURCES = clientdb-maria.cc 
endif

if WITH_DBI
liboctetos_db_dbi_la_LDFLAGS= 
liboctetos_db_dbi_la_CFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
liboctetos_db_dbi_la_CPPFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
liboctetos_db_dbi_la_LIBDADD = $(DBI_LIBS) $(OCTETOS_CORE_CC_LIBS) liboctetos-db.la 
liboctetos_db_dbi_la_SOURCES = clientdb-dbi.cc
endif

if WITH_POSTGRESQL
liboctetos_db_postgresql_la_LDFLAGS= 
liboctetos_db_postgresql_la_CFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_postgresql_la_CPPFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_postgresql_la_LIBDADD = $(LIBPQ_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_postgresql_la_SOURCES = clientdb-postgresql.cc 
endif

octetos_db_includedir = $(includedir)/octetos/db
octetos_db_include_HEADERS = clientdb.hh
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-db.pc
EXTRA_DIST = octetos-db.pc.in
if WITH_MYSQL
pkgconfig_DATA += octetos-db-mysql.pc
EXTRA_DIST += octetos-db-mysql.pc.in
octetos_db_include_HEADERS += clientdb-mysql.hh
endif
if WITH_MARIADB
pkgconfig_DATA = $pkgconfig_DATA octetos-db-maria.pc
EXTRA_DIST = $(EXTRA_DIST) octetos-db-maria.pc.in
octetos_db_include_HEADERS = $(octetos_db_include_HEADERS) clientdb-maria.hh
endif
if WITH_POSTGRESQL
pkgconfig_DATA += octetos-db-postgresql.pc
EXTRA_DIST += octetos-db-postgresql.pc.in
octetos_db_include_HEADERS += clientdb-postgresql.hh
endif