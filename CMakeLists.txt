cmake_minimum_required(VERSION 3.0)
project(cpu1)

set(VERILATOR_INC "UNKNOWN" CACHE PATH "Path to verilator includes")
set(VERILATOR_EXE "UNKNOWN" CACHE FILE "Path to verilator excutable")

add_subdirectory("verilator-3.841/include")

include_directories(${VERILATOR_INC})
include_directories("obj_dir")

file(GLOB RTL "obj_dir/*.cpp" "obj_dir/*.h")
add_library(librtl ${RTL})

file(GLOB SOURCE "source/*.cpp" "source/*.h" "source/*.v")
add_executable(cpu1 ${SOURCE})
target_link_libraries(cpu1 libverilator librtl)

file(GLOB VFILES "source/*v")

add_custom_command(TARGET cpu1 PRE_BUILD COMMAND
    ${VERILATOR_EXE} "--top-module" "cpu1" "--compiler" "msvc" "-Isource" "--cc" ${VFILES} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
