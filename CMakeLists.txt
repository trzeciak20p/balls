cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(main src/main.cpp src/classes/ball.cpp src/classes/mapLoader.cpp src/classes/wall.cpp src/utils/utils_2d.cpp)

target_include_directories(main PRIVATE src/clasees src/utils)
target_link_libraries(main PRIVATE sfml-graphics)