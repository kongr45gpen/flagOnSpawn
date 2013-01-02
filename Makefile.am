lib_LTLIBRARIES = flagOnSpawn.la

flagOnSpawn_la_SOURCES = flagOnSpawn.cpp
flagOnSpawn_la_CXXFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
flagOnSpawn_la_LDFLAGS = -module -avoid-version -shared
flagOnSpawn_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

AM_CPPFLAGS = $(CONF_CPPFLAGS)
AM_CFLAGS = $(CONF_CFLAGS)
AM_CXXFLAGS = $(CONF_CXXFLAGS)

EXTRA_DIST = \
	README.txt \
	flagOnSpawn.def \
	flagOnSpawn.sln \
	flagOnSpawn.vcxproj

MAINTAINERCLEANFILES =	\
	Makefile.in
