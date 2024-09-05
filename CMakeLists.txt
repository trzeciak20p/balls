cmake_minimum_required(VERSION 3.28)
project(BallsWithYourFriends LANGUAGES CXX)

if (WIN32)
  #set(SFML_STATIC_LIBRARIES TRUE)
  option(BUILD_SHARED_LIBS "Build shared libraries" ON)

  include(FetchContent)
  FetchContent_Declare(SFML
      GIT_REPOSITORY https://github.com/SFML/SFML.git
      GIT_TAG 2.6.x
      GIT_SHALLOW ON
      EXCLUDE_FROM_ALL
      SYSTEM)
  FetchContent_MakeAvailable(SFML)
else()
  find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
endif()

add_executable(main src/main.cpp src/classes/ball.cpp src/classes/mapLoader.cpp src/classes/wall.cpp src/classes/utils_2d.cpp src/classes/game.cpp)

set_target_properties(main PROPERTIES CXX_STANDARD 20)
set_target_properties(main PROPERTIES OUTPUT_NAME baluminc)

target_include_directories(main PRIVATE src/clasees)
target_link_libraries(main PRIVATE sfml-graphics)