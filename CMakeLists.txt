cmake_minimum_required(VERSION 3.28)
project(BallsWithYourFriends LANGUAGES CXX)

#option(BUILD_SHARED_LIBS "Build shared libraries" ON)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

add_executable(main src/main.cpp src/classes/ball.cpp src/classes/mapLoader.cpp src/classes/wall.cpp src/classes/utils_2d.cpp src/classes/game.cpp)

set_target_properties(main PROPERTIES CXX_STANDARD 20)
set_target_properties(main PROPERTIES OUTPUT_NAME baluminc)

target_include_directories(main PRIVATE src/clasees src/utils)
target_link_libraries(main PRIVATE sfml-graphics)