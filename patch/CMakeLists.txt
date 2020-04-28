# patch

set (prog patch)

set (srcs
	patch.c
	pch.c
	inp.c
	util.c
	backupfile.c
	mkpath.c
)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (srcs ${srcs} linux_support.c)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "(Solaris|SunOS)")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set (srcs ${srcs} mac_support.c)
endif()

add_executable(${prog} ${srcs})
target_link_libraries(${prog} ${libs})
target_include_directories(${prog} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${incbsd})

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
