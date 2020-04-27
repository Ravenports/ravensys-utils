cmake_minimum_required(VERSION 3.16)
project(ravensys)

SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

add_subdirectory(libdl)
add_subdirectory(sha256)
# add_subdirectory(fonts)
# add_subdirectory(src)
# add_subdirectory(sys)
# add_subdirectory(examples)

# install(FILES rgb.txt DESTINATION share/doc/pgplot)
