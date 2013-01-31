NULL = 


if WITH_APPLET
  MAYBE_APPLET = applet
endif

if WITH_RPI
	COMPILER_OPTIMISATIONS = -fpic -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
else
	COMPILER_OPTIMISATIONS = -march=native -mtune=native
endif


SUBDIRS = \
	$(MAYBE_APPLET) \
	$(NULL)

AM_CPPFLAGS = \
	$(LEDBORG_SERVER_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(COMPILER_OPTIMISATIONS) \
	-DSYSCONFDIR=\"${sysconfdir}\" \
	$(NULL)

AM_VALAFLAGS = \
	--vapidir=../vapi \
	--thread \
	--pkg Config \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg posix \
	--pkg ledborg \
	$(NULL)

bin_PROGRAMS = \
	ledborg_server \
	$(NULL)

ledborg_server_SOURCES = \
	main.vala \
	LedBorgServer.vala \
	Device.vala \
	Responder.vala \
	$(NULL)

ledborg_server_LDADD = \
	$(LEDBORG_SERVER_LIBS) \
	lib/.libs/libledborg.so \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

