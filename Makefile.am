NULL = 

ACLOCAL_AMFLAGS = -I m4

#Build in these directories:

SUBDIRS = \
	src \
	po \
	$(NULL)

ledborg_serverdocdir = ${prefix}/doc/ledborg_server
ledborg_serverdoc_DATA = \
	ChangeLog \
	README \
	COPYING \
	AUTHORS \
	INSTALL \
	NEWS \
	$(NULL)

ledborg_confdir = ${sysconfdir}/ledborg-server
ledborg_conf_DATA = \
	src/conf/ledborg-server.html \
	$(NULL)

EXTRA_DIST = \
	$(ledborg_serverdoc_DATA) \
	$(ledborg_conf_DATA) \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in \
	$(NULL)

DISTCLEANFILES = \
	intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache \
	$(NULL)

