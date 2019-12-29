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
bin_PROGRAMS += mysql-v0
mysql_v0_CPPFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS) $(MYSQLCLIENT_CFLAGS) $(CUNIT_CFLAGS) -I$(top_srcdir)/src -L$(top_builddir)/src
mysql_v0_CFLAGS = $(MYSQLCLIENT_CFLAGS) $(OCTETOS_CORE_CFLAGS) -I$(top_srcdir)/src
mysql_v0_LDADD = $(MYSQLCLIENT_LIBS) $(OCTETOS_CORE_LIBS) $(CUNIT_LIBS) $(top_builddir)/src/liboctetos-db.la $(top_builddir)/src/liboctetos-db-mysql.la $(MYSQLCLIENT_LIBS)  $(MYSQLCLIENT_LIBS)
mysql_v0_SOURCES = mysql-v0.cc
endif

