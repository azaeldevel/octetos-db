

SUBDIRS = abstract

if WITH_POSTGRESQL
SUBDIRS += postgresql
endif
if WITH_MARIADB
SUBDIRS += mariadb
endif

if WITH_TESTS
SUBDIRS += tests
endif

dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS


