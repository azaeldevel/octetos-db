## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_DB_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

octetos_db_includedir = $(includedir)/octetos/db
octetos_db_include_HEADERS = clientdb.hh clientdb-mysql.hh

bin_PROGRAMS = octetos_db


lib_LTLIBRARIES =  \
	liboctetos-db.la\
	liboctetos-db-mysql-cc.la\
	liboctetos-db-dbi-cc.la

liboctetos_db_la_LDFLAGS = /usr/local/lib/liboctetos-core-cc.a 
liboctetos_db_la_LIBDADD = /usr/local/lib/liboctetos-core-cc.a
liboctetos_db_la_SOURCES = clientdb.cc 

liboctetos_db_mysql_cc_la_LIBDADD = $(OCTETOS_DB_LIBS) /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la 
liboctetos_db_mysql_cc_la_SOURCES = clientdb-mysql.cc 

liboctetos_db_dbi_cc_la_LDFLAGS = $(OCTETOS_DB_LIBS) /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la
liboctetos_db_dbi_cc_la_LIBDADD = $(OCTETOS_DB_LIBS) /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la 
liboctetos_db_dbi_cc_la_SOURCES = clientdb-dbi.cc


octetos_db_LDFLAGS = $(OCTETOS_DB_LIBS)  /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la liboctetos-db-dbi-cc.la
octetos_db_LDADD = $(OCTETOS_DB_LIBS)  /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la liboctetos-db-dbi-cc.la
octetos_db_LIBDADD = $(OCTETOS_DB_LIBS)  /usr/local/lib/liboctetos-core-cc.a liboctetos-db.la liboctetos-db-dbi-cc.la
octetos_db_SOURCES = main.cc 



if NATIVE_WIN32
octetos_db_LDFLAGS += -mwindows
endif