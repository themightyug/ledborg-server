NULL = 

ACLOCAL_AMFLAGS = -I m4

#Build in these directories:

if WITH_SERVER
    MAYBE_SERVER = src
else
    MAYBE_SERVER = $(NULL)
endif


SUBDIRS = \
	src/lib \
	$(MAYBE_SERVER) \
	po \
	$(NULL)


if WITH_SERVER
ledborg_serverdocdir = ${datarootdir}/doc/ledborg_server
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

else
ledborg_serverdocdir = $(NULL)
ledborg_serverdoc_DATA = $(NULL)
ledborg_confdir = $(NULL)
ledborg_conf_DATA = $(NULL)
endif


libledborg_vapidir = $(VAPIDIR)
libledborg_vapi_DATA = \
	src/lib/libledborg.vapi \
	$(NULL)

libledborg_hdir = $(INCLUDEDIR)
libledborg_h_DATA = \
	src/lib/libledborg.h \
	$(NULL)

EXTRA_DIST = \
	$(libledborg_vapi_DATA) \
	$(libledborg_h_DATA) \
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

