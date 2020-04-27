# libdl

set(libsrcs dl_stub.c)

add_library(dlobj OBJECT ${libsrcs})
set_property(TARGET dlobj PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(dl STATIC $<TARGET_OBJECTS:dlobj>)

install(TARGETS dl
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
