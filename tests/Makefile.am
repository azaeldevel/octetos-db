AUTOMAKE_OPTIONS=foreign 1.4

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(CUNIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g


bin_PROGRAMS = 

if WITH_MYSQL
bin_PROGRAMS += mysql
mysql_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS) $(MYSQLCLIENT_CFLAGS) $(CUNIT_CFLAGS) -I$(top_srcdir)/src
mysql_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS) $(MYSQLCLIENT_CFLAGS) $(CUNIT_CFLAGS) -I$(top_srcdir)/src
mysql_LDFLAGS = 
mysql_LDADD = $(OCTETOS_CORE_LIBS) $(CUNIT_LIBS) $(MYSQLCLIENT_LIBS) 
mysql_SOURCES = mysql.cc $(top_srcdir)/src/clientdb-mysql.cc $(top_srcdir)/src/clientdb.cc
endif

if WITH_POSTGRESQL
bin_PROGRAMS += postgresql
postgresql_CPPFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS) $(MYSQLCLIENT_CFLAGS) $(CUNIT_CFLAGS) -I$(top_srcdir)/src 
postgresql_CFLAGS = $(LIBPQ_CFLAGS) $(OCTETOS_CORE_CFLAGS) $(MYSQLCLIENT_CFLAGS) $(CUNIT_CFLAGS) -I$(top_srcdir)/src
postgresql_LDFLAGS = 
postgresql_LDADD = $(OCTETOS_CORE_LIBS) $(CUNIT_LIBS) $(LIBPQ_LIBS)
postgresql_SOURCES = postgresql.cc $(top_srcdir)/src/clientdb-postgresql.cc $(top_srcdir)/src/clientdb.cc
endif