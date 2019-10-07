# Setting CMake version properly to ensure correct policies behavior
cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Setting up OpenROAD project
project(OpenROAD VERSION 2019.10.05
                 DESCRIPTION "OpenROAD RTL-to-GDS Flow"
                 LANGUAGES CXX)

# Configure build version
configure_file (
    "${PROJECT_SOURCE_DIR}/include/openroad/version.h.in"
    "${PROJECT_BINARY_DIR}/include/openroad/version.h"
)

# Add Required libraries
add_subdirectory(module/FakeDB)
add_subdirectory(module/FakeTimer)
add_subdirectory(module/FakePlacer)

# Find libraries
find_package(SWIG REQUIRED)

find_package(FakeDB 1.0 REQUIRED)
find_package(FakeTimer 1.0 REQUIRED)
find_package(FakePlacer 1.0 REQUIRED)


# Define target
add_executable(openroad
    src/main.cpp
    src/openroad_wrap.cpp
)

target_compile_features(openroad PRIVATE cxx_auto_type)
target_compile_options(openroad PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

target_include_directories(openroad
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROJECT_BINARY_DIR}/include
)

target_link_libraries(openroad
    PRIVATE
        fakedb
        faketimer
        fakeplacer
        tcl
)

# enable swig compile
set (OPENROAD_SWIG_FILES
    src/openroad.i
)

add_custom_command(OUTPUT ${PROJECT_SOURCE_DIR}/src/openroad_wrap.cpp
  COMMAND ${SWIG_EXECUTABLE} -tcl8 -c++ -o ${PROJECT_SOURCE_DIR}/src/openroad_wrap.cpp ${PROJECT_SOURCE_DIR}/src/openroad.i   
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  DEPENDS ${OPENROAD_SWIG_FILES}
)