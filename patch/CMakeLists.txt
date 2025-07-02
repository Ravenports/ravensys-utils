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

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set (srcs ${srcs} mac_support.c)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "(Solaris|SunOS)")
   set (srcs ${srcs} fgetln.c)
endif()

add_executable(${prog} ${srcs})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (srcs ${srcs} linux_support.c)
   target_link_libraries(${prog} ${libs})
endif()

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
