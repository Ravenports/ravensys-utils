# ravensys-uname

set (prog ravensys-uname)

# Externally set:
#   RAVENPLAT
#   RAVENOPSYS
#   RAVENRELEASE
#   RAVENMAJOR
#   RAVENKERNEL

# Except for Darwin, all RAVENARCH equals RAVENPLAT
# Except for Darwin, all URELEASE equals RAVENRELEASE

set(RAVENARCH ${RAVENPLAT})
set(URELEASE ${RAVENRELEASE}-RAVEN)
set(APPLEREL ${RAVENMAJOR})

if (${RAVENOPSYS} STREQUAL "Darwin")
  if (${RAVENPLAT} STREQUAL "x86_64")
	set(RAVENARCH i386)
	set(URELEASE ${APPLEREL}-RAVEN) 
  endif()
endif()

if (${RAVENOPSYS} STREQUAL "SunOS")
  if (${RAVENPLAT} STREQUAL "i86pc")
	set(RAVENARCH i386)
	set(URELEASE ${RAVENRELEASE})
  endif()
endif()

if (${RAVENOPSYS} STREQUAL "NetBSD")
  if (${RAVENPLAT} STREQUAL "x86_64")
	set(RAVENARCH amd64)
	set(URELEASE ${RAVENRELEASE})
  endif()
endif()

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/uname.c
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/uname.c.in
	COMMENT "Generated uname.c"
	COMMAND sed -e 's|@OPSYS@|${RAVENOPSYS}|\; s|@ARCH@|${RAVENARCH}|\; s|@PLATFORM@|${RAVENPLAT}|\; s|@RELEASE@|${URELEASE}|\; s|@USERVER@|${RAVENKERNEL}|' ${CMAKE_CURRENT_SOURCE_DIR}/uname.c.in > ${CMAKE_CURRENT_BINARY_DIR}/uname.c
)
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/uname.c PROPERTIES GENERATED true)

set (srcs uname.c)
add_executable(${prog} ${srcs})

install(TARGETS ${prog} DESTINATION bin)
