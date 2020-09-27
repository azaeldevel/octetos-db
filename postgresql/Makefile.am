AUTOMAKE_OPTIONS=foreign 1.4


lib_LTLIBRARIES = liboctetos-db-postgresql.la


liboctetos_db_postgresql_la_CXXFLAGS = $(LIBPQ_CFLAGS) -I$(top_srcdir)/../abstract 
liboctetos_db_postgresql_la_LIBADD = $(OCTETOS_CORE_LIBS) 
liboctetos_db_postgresql_la_SOURCES = clientdb-postgresql.cc


includeHEADERS = clientdb-postgresql.hh
pkgDATA = octetos-db-postgresql.pc
extraDist = octetos-db-postgresql.pc.in



octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = $(includeHEADERS)
pkgconfig_DATA = $(pkgDATA)
EXTRA_DIST = $(extraDist)