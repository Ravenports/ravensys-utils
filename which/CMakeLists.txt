# which

set (prog which)

set (srcs which.c)

add_executable(${prog} ${srcs})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
   target_compile_definitions(${prog} PUBLIC LIBBSD_OVERLAY)
   target_link_libraries(${prog} ${libs})
   target_include_directories(${prog} PUBLIC ${incbsd})
endif()

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
