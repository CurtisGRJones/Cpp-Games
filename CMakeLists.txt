cmake_minimum_required(VERSION 3.16)
project(TikTakToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")

find_package(SDL2 REQUIRED)

add_executable(TikTakToe src/main.cpp)

target_include_directories(TikTakToe PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(TikTakToe ${SDL2_LIBRARIES})