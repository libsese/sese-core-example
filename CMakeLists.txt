set(VCPKG_OVERLAY_PORTS ${CMAKE_CURRENT_LIST_DIR}/ports)

cmake_minimum_required(VERSION 3.10)
project(sese-core-example)

set(CMAKE_CXX_STANDARD 20)

find_package(sese CONFIG REQUIRED)

if (${MSVC})
    add_compile_options(/utf-8)
endif ()

add_subdirectory(record)
add_subdirectory(thread)
add_subdirectory(json)
add_subdirectory(xml)
add_subdirectory(convert)
add_subdirectory(yaml)
add_subdirectory(http)