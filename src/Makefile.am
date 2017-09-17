INCLUDES =						\
	-DG_LOG_DOMAIN=\"Nautilus-Open-Terminal\"	\
	-DDATADIR=\"$(datadir)\"			\
	-DGNOMELOCALEDIR=\""$(datadir)/locale"\" 	\
	-I$(top_srcdir)					\
	-I$(top_builddir)				\
	$(WARN_CFLAGS)                                  \
	-Werror                                         \
	$(DISABLE_DEPRECATED)				\
	$(NAUTILUS_CFLAGS)				\
	$(GCONF_CFLAGS)

nautilus_extensiondir=$(NAUTILUS_EXTENSION_DIR)

nautilus_extension_LTLIBRARIES=libnautilus-terminal.la

libnautilus_terminal_la_SOURCES = \
	nautilus-terminal.h       \
	nautilus-terminal.c       \
	nautilus-terminal.h       \
	terminal.c

libnautilus_terminal_la_LDFLAGS = -module -avoid-version
libnautilus_terminal_la_LIBADD  = $(NAUTILUS_LIBS) $(GCONF_LIBS)
