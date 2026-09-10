cmake_minimum_required(VERSION 3.20)
project(cpp_tutorial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Every ordinary lesson is a self-contained program with its own main().
file(GLOB_RECURSE lesson_sources CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER lesson_sources INCLUDE REGEX ".*/0[1-6]_.*\\.cpp$")
list(FILTER lesson_sources EXCLUDE REGEX ".*/05_standard_library/07_multifile_example/.*")

foreach(source IN LISTS lesson_sources)
    file(RELATIVE_PATH relative_source "${CMAKE_CURRENT_SOURCE_DIR}" "${source}")
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" target "${relative_source}")
    add_executable("${target}" "${source}")
endforeach()

add_executable(multi_file_example
    05_standard_library/07_multifile_example/main.cpp
    05_standard_library/07_multifile_example/ledger.cpp)
