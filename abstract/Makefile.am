AUTOMAKE_OPTIONS=foreign 1.4


lib_LTLIBRARIES = liboctetos-db.la



liboctetos_db_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_la_SOURCES = clientdb.cc


includeHEADERS = clientdb.hh
pkgDATA = octetos-db.pc
extraDist = octetos-db.pc.in



octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = $(includeHEADERS)
pkgconfig_DATA = $(pkgDATA)
EXTRA_DIST = $(extraDist)