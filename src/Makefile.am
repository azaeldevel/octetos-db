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

octetos_db_SOURCES = \
	main.cc

octetos_db_LDFLAGS = 

octetos_db_LDADD = $(OCTETOS_DB_LIBS)


if NATIVE_WIN32
octetos_db_LDFLAGS += -mwindows
endif

lib_LTLIBRARIES =  \
	liboctetos-db-mysql-cc.la

liboctetos_db_mysql_cc_la_SOURCES =  \
	clientdb.cc \
	clientdb-mysql.cc
