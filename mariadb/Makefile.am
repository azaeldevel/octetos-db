AUTOMAKE_OPTIONS=foreign 1.4


lib_LTLIBRARIES = liboctetos-db-maria.la


liboctetos_db_maria_la_CXXFLAGS = $(MARIADB_CFLAGS) -I$(top_srcdir)/../abstract  
liboctetos_db_maria_la_LIBADD = $(OCTETOS_CORE_LIBS) 
liboctetos_db_maria_la_SOURCES = clientdb-maria.cc


includeHEADERS = clientdb-maria.hh
pkgDATA = octetos-db-maria.pc
extraDist = octetos-db-maria.pc.in



octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = $(includeHEADERS)
pkgconfig_DATA = $(pkgDATA)
EXTRA_DIST = $(extraDist)