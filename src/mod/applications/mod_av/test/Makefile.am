bin_PROGRAMS = test_mod_av test_avformat
AM_CFLAGS = $(SWITCH_AM_CFLAGS) -I../ $(AVFORMAT_CFLAGS) $(AVCODEC_CFLAGS) $(SWSCALE_CFLAGS) $(AVUTIL_CFLAGS) $(AVRESAMPLE_CFALGS)
AM_LDFLAGS = $(switch_builddir)/libfreeswitch.la $(AVFORMAT_LIBS) $(AVCODEC_LIBS) $(SWSCALE_LIBS)  $(AVUTIL_LIBS) $(AVRESAMPLE_LIBS) -avoid-version -no-undefined $(SWITCH_AM_LDFLAGS) ../mod_av.la
TESTS = $(bin_PROGRAMS)
