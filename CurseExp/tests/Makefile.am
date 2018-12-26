## Process this file with automake to produce Makefile.in

TESTS = check_roots
check_PROGRAMS = check_roots
check_roots_SOURCES = check_roots.c $(top_builddir)/src/roots.h
check_roots_CFLAGS = @CHECK_CFLAGS@
check_roots_LDADD = $(top_builddir)/src/libroots.la @CHECK_LIBS@
