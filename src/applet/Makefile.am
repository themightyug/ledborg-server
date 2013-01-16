NULL = 

AM_CPPFLAGS = \
	$(LEDBORG_SERVER_CFLAGS) \
	-include $(CONFIG_HEADER) \
	-march=native -mtune=native \
	$(NULL)

AM_VALAFLAGS = \
	--vapidir=../../vapi \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg posix \
	--pkg gtk+-2.0 \
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

