cmake_minimum_required (VERSION 2.6)
project (xrit)
enable_language(CXX)

# C++11 Macro
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

use_cxx11()

# Version
set (goesdump_VERSION_MAJOR 1)
set (goesdump_VERSION_MINOR 0)
set(VERSION_INFO_MAINT_VERSION 0)

# Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -pipe -march=native")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -pipe -march=native")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(CMAKE_MACOSX_RPATH 1)

# Includes
include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("${PROJECT_SOURCE_DIR}/include/Headers")
include_directories ("${PROJECT_SOURCE_DIR}/include/Types")

# Library Source Code
file(GLOB SOURCES src/*.cpp)

# Library Targets
add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(${PROJECT_NAME}_s STATIC ${SOURCES})
SET_TARGET_PROPERTIES(${PROJECT_NAME}_s PROPERTIES OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(${PROJECT_NAME}   PROPERTIES OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT 1)

# Links
target_link_libraries (${PROJECT_NAME} sz)
target_link_libraries (${PROJECT_NAME} aec)
target_link_libraries (${PROJECT_NAME} boost_system)
target_link_libraries (${PROJECT_NAME} boost_filesystem)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}_s DESTINATION lib)

# Install library headers
file(GLOB HEADERS include/*.h)
file(GLOB HEADERS_HEADERS include/Headers/*.h)
file(GLOB HEADERS_TYPES include/Types/*.h)

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
install(FILES ${HEADERS_HEADERS} DESTINATION include/${PROJECT_NAME}/Headers)
install(FILES ${HEADERS_TYPES} DESTINATION include/${PROJECT_NAME}/Types)

# Debian Package
SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Luigi Freitas")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libaec0")
SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "")
INCLUDE(CPack)
