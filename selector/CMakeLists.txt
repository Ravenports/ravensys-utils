# ravensys-selector

set (prog ld)
set (srcs selector.c)
add_executable(${prog} ${srcs})

macro(install_symlink filepath sympath)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${filepath} ${sympath})")
    install(CODE "message(\"-- Created symlink: ${sympath} -> ${filepath}\")")
endmacro(install_symlink)

install(TARGETS ${prog} DESTINATION libexec)
