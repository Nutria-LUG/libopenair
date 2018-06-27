lib_LTLIBRARIES = libopenair.la
nobase_include_HEADERS = \
	libopenair/configuration.hh \
	libopenair/curl_service_connector.hh

libopenair_la_LIBADD = -lcurl
libopenair_la_CXXFLAGS = -std=c++14

libopenair_la_SOURCES = \
	libopenair/configuration.hh \
	configuration.cc \
	libopenair/curl_service_connector.hh \
	curl_service_connector.cc

# Some usefull notes are reported below.
# 01. To add an existing library use -l options
#      libopenair_LDADD =  -lib
#
# 02. To add some custom flag to the project use _CXXFLAGS
#      libopenair_CXXFLAGS = -std=c++17
#
# 03. To compile an inner static library use noinst_, this avoid the
#     installation (static library must be linked directly to the the
#     compiled file).
#      noinst_LIBRARIES = libstaticlibname.a
#      libstaticlibname_a_SOURCES = ... list of sources ...
#
#      bin_PROGRAM = libopenair
#      libopenair_SOURCES = ....
#      libopenair_LDADD = libstaticlibname.a
#
#     Remember to add AC_PROG_RANLIB macro in configure.ac
#     AC_PROG_RANLIB: This is required if any libraries are built in
#                     the package. See Particular Program Checks in
#                     The Autoconf Manual. 

