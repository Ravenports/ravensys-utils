# realpath (coming to NetBSD on version 10)

set (prog realpath)
set (srcs realpath.c)
add_executable(${prog} ${srcs})

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
