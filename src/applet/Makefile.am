NULL = 


if WITH_RPI
	COMPILER_OPTIMISATIONS = -fpic -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
else
	COMPILER_OPTIMISATIONS = -march=native -mtune=native
endif



AM_CPPFLAGS = \
	$(LEDBORG_SERVER_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(COMPILER_OPTIMISATIONS) \
	-DSYSCONFDIR=\"${sysconfdir}\" \
	$(NULL)

AM_VALAFLAGS = \
	--vapidir=../../vapi \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg posix \
	--pkg gtk+-3.0 \
	$(NULL)

bin_PROGRAMS = \
	ledborg_control_applet \
	$(NULL)

ledborg_control_applet_SOURCES = \
	main.vala \
	LedBorgControlApplet.vala \
	LedBorgClient.vala \
	../IOError.vala \
	../RequestError.vala \
	../Colour.vala \
	$(NULL)

ledborg_control_applet_LDADD = \
	$(LEDBORG_SERVER_LIBS) \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

