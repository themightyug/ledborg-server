NULL = 



if WITH_RPI
    COMPILER_OPTIMISATIONS = -fpic -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
else
    COMPILER_OPTIMISATIONS = -march=native -mtune=native
endif


SUBDIRS = \
	$(NULL)

AM_CPPFLAGS = \
	$(LEDBORG_SERVER_CFLAGS) \
	-include $(CONFIG_HEADER) \
	-I lib \
	$(COMPILER_OPTIMISATIONS) \
	-DSYSCONFDIR=\"${sysconfdir}\" \
	$(NULL)

AM_VALAFLAGS = \
	--vapidir=../vapi \
	--vapidir=./lib \
	--thread \
	--pkg Config \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg posix \
	--pkg LedBorg \
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
	lib/.libs/libledborg-0.2.so \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	*.c \
	*.o \
	$(NULL)


