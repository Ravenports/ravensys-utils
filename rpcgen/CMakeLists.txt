# rpcgen

set (prog rpcgen)

set (srcs
	rpc_main.c
	rpc_clntout.c
	rpc_cout.c
	rpc_hout.c
	rpc_parse.c
	rpc_sample.c
	rpc_scan.c
	rpc_svcout.c
	rpc_tblout.c
	rpc_util.c
)

add_executable(${prog} ${srcs})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd.a)
   target_link_libraries(${prog} ${libs})
   target_include_directories(${prog} PUBLIC /usr/include/tirpc)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "(Solaris|SunOS)")
   set (incbsd ${CMAKE_INSTALL_PREFIX}/include/bsd)
   target_include_directories(${prog} PUBLIC ${incbsd})
endif()

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
