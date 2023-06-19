cmake_minimum_required(VERSION 3.25)
project(sese-core-example)

set(CMAKE_CXX_STANDARD 20)

find_package(SString CONFIG REQUIRED)
find_package(SimpleUuid CONFIG REQUIRED)
find_package(sese CONFIG REQUIRED)
find_package(sese-event CONFIG REQUIRED)
find_package(sese-plugin CONFIG REQUIRED)

add_subdirectory(record)
add_subdirectory(thread)
add_subdirectory(json)
add_subdirectory(xml)
add_subdirectory(convert)