# ravensys-selector

set (prog ld)

# Externally set:
#   LOCALBASE

macro(install_symlink filepath sympath)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${filepath} ${sympath})")
    install(CODE "message(\"-- Created symlink: ${sympath} -> ${filepath}\")")
endmacro(install_symlink)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/selector.c
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/selector.c.in
	COMMENT "Generated selector.c"
	COMMAND sed -e 's|@BASE@|${LOCALBASE}|\;' ${CMAKE_CURRENT_SOURCE_DIR}/selector.c.in > ${CMAKE_CURRENT_BINARY_DIR}/selector.c
)

set (srcs selector.c)
add_executable(${prog} ${srcs})

install(TARGETS ${prog} DESTINATION libexec)
