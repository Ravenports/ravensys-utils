# mtree

set (prog mtree)
set (libssl ${CMAKE_INSTALL_PREFIX}/libressl/lib/libcrypto_pic.a)
set (incssl ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_INSTALL_PREFIX}/libressl/include)

set (libs ${libssl})

set (srcs
	compare.c
	create.c
	excludes.c
	misc.c
	mtree.c
	spec.c
	verify.c
	crc.c
	sha1hl.c
)

add_executable(${prog} ${srcs})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (libs ${libs} -lpthread)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
   target_compile_definitions(${prog} PUBLIC LIBBSD_OVERLAY)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "(Solaris|SunOS)")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libfts.a)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
endif()

target_link_libraries(${prog} ${libs})
target_include_directories(${prog} PUBLIC ${incssl} ${incbsd})

install(TARGETS ${prog} DESTINATION bin)
