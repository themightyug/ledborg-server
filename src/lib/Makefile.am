NULL = 


if WITH_RPI
	COMPILER_OPTIMISATIONS = -fpic -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
else
	COMPILER_OPTIMISATIONS = -fpic -march=native -mtune=native
endif

lib_LTLIBRARIES = libledborg.la

AM_CPPFLAGS = \
	$(LEDBORG_SERVER_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(NULL)
	$(COMPILER_OPTIMISATIONS) \
	$(NULL)

libledborg_la_LDFLAGS = \
	-version-info 0:1:0 \
	$(NULL)

libledborg_la_VALAFLAGS = \
	--library=libledborg.so \
	--header=libledborg.h \
	--thread \
	--vapidir=../../vapi \
	--vapi=LedBorg.vapi \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg posix \
	$(NULL)

libledborg_la_SOURCES = \
	LedBorgClient.vala \
	IOError.vala \
	RequestError.vala \
	Colour.vala \
	$(NULL)

libledborg_la_LIBADD = \
	$(LEDBORG_SERVER_LIBS) \
	$(NULL)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libledborg.pc

libledborg.pc: $(NULL)


EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	*.lo \
	*.c \
	.libs \
	libledborg.pc \
	$(NULL)

