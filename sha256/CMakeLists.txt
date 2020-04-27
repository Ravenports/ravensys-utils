# md5 (sha256 is a symlink to md5)

set (prog md5)
set (srcs md5c.c md5hl.c sha256hl.c main.c)

set (libssl ${CMAKE_INSTALL_PREFIX}/libressl/lib/libcrypto_pic.a)
set (incssl ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_INSTALL_PREFIX}/libressl/include)

set (libs ${libssl})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
   set (libs ${libs} ${CMAKE_INSTALL_PREFIX}/lib/libbsd_pic.a)
endif()

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/md5hl.c
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mdXhl.c
	COMMENT "Generated md5hl.c"
	COMMAND echo '\#define LENGTH 16' > ${CMAKE_CURRENT_BINARY_DIR}/md5hl.c && sed -e 's/mdX/md5/g\; s/MDX/MD5/g' ${CMAKE_CURRENT_SOURCE_DIR}/mdXhl.c >> ${CMAKE_CURRENT_BINARY_DIR}/md5hl.c
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/sha256hl.c
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mdXhl.c
	COMMENT "Generated sha256hl.c"
	COMMAND echo '\#define LENGTH 32' > ${CMAKE_CURRENT_BINARY_DIR}/sha256hl.c && sed -e 's/mdX/sha256/g\; s/MDX/SHA256_/g\; s/SHA256__/SHA256_/g' ${CMAKE_CURRENT_SOURCE_DIR}/mdXhl.c >> ${CMAKE_CURRENT_BINARY_DIR}/sha256hl.c
)

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/md5hl.c PROPERTIES GENERATED true)
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/sha256hl.c PROPERTIES GENERATED true)

add_executable(${prog} ${srcs})
target_link_libraries(${prog} ${libs})
target_include_directories(${prog} PUBLIC ${incssl})

install(TARGETS ${prog} DESTINATION bin)
install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink \
	md5 ${CMAKE_INSTALL_PREFIX}/bin/sha256)"
)
install(CODE "message(\"-- Installing: symlink bin/sha256 -> bin/md5\")")
