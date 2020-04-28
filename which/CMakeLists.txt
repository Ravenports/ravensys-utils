# which

set (prog which)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
   target_compile_definitions(${prog} PUBLIC LIBBSD_OVERLAY)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "(Solaris|SunOS)")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
endif()

set (srcs which.c)

add_executable(${prog} ${srcs})
target_link_libraries(${prog} ${libs})
target_include_directories(${prog} PUBLIC ${incbsd})

install(TARGETS ${prog} DESTINATION bin)
install(FILES which.1 DESTINATION share/man/man1)
