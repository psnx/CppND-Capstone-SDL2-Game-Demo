cmake_minimum_required(VERSION 3.17.3)
project(Capstone)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(SDL2 CONFIG REQUIRED)


file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)




