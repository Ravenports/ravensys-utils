# realpath (coming to NetBSD on version 10)
# We have to rename it bsd_realpath to avoid conflict with coreutils

set (prog bsd_realpath)
set (srcs bsd_realpath.c)
add_executable(${prog} ${srcs})

install(TARGETS ${prog} DESTINATION bin)
install(FILES ${prog}.1 DESTINATION share/man/man1)
