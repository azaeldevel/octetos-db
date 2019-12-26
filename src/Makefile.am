AUTOMAKE_OPTIONS=foreign 1.4

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CPPUNIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liboctetos-db.la \
	liboctetos-db-mysql.la 

bin_PROGRAMS = test-v0

liboctetos_db_la_LDFLAGS =$(OCTETOS_CORE_CFLAGS)
if PLATFORM_WIN32
liboctetos_db_la_LDFLAGS += -no-undefined
endif
if NATIVE_WIN32
liboctetos_db_la_LDFLAGS += -export-dynamic
endif
liboctetos_db_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_la_SOURCES = clientdb.cc

liboctetos_db_mysql_la_LDFLAGS= 
liboctetos_db_mysql_la_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
liboctetos_db_mysql_la_LIBDADD = $(MYSQLCLIENT_LIBS) $(OCTETOS_CORE_LIBS) 
liboctetos_db_mysql_la_SOURCES = clientdb-mysql.cc 

#liboctetos_db_dbi_la_LDFLAGS= 
#liboctetos_db_dbi_la_CFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
#liboctetos_db_dbi_la_CPPFLAGS = $(DBI_CFLAGS) $(OCTETOS_CORE_CC_CFLAGS)
#liboctetos_db_dbi_la_LIBDADD = $(DBI_LIBS) $(OCTETOS_CORE_CC_LIBS) liboctetos-db.la 
#liboctetos_db_dbi_la_SOURCES = clientdb-dbi.cc

test_v0_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
test_v0_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS)
test_v0_LDADD = $(MYSQLCLIENT_LIBS) $(OCTETOS_CORE_LIBS) liboctetos-db.la liboctetos-db-mysql.la $(MYSQLCLIENT_LIBS) 
test_v0_SOURCES = test-v0.cc

octetos_db_includedir = $(includedir)/octetos/db
octetos_db_include_HEADERS = clientdb.hh clientdb-mysql.hh clientdb-dbi.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-db.pc

EXTRA_DIST = octetos-db.pc.in
