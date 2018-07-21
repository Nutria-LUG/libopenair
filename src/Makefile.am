lib_LTLIBRARIES = libopenair.la
nobase_include_HEADERS =  \
	libopenair/configuration.hh \
	libopenair/curl_service_connector.hh

libopenair_la_LIBADD = -lcurl
libopenair_la_CXXFLAGS = -std=c++14

libopenair_la_SOURCES = \
	libopenair/configuration.hh \
	configuration.cc \
	libopenair/curl_service_connector.hh \
	curl_service_connector.cc
