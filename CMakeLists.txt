cmake_minimum_required(VERSION 3.28)
project(BallsWithYourFriends LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

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

add_executable(main src/main.cpp src/classes/ball.cpp src/classes/board.cpp src/classes/wall.cpp src/classes/utils_2d.cpp src/classes/game.cpp)

# basycznie powinno sie używać analizatora ale jeszcze go nie ma wiec jest ściana (wall)
# target_compile_options(main PRIVATE "-Wall;-Wextra;-Wpedantic;-pedantic-errors;-fanalyzer;-Wshadow;-Wnull-dereference;-Wduplicated-cond;-Wredundant-decls;-Wduplicated-branches;-Wlogical-op;-Wcast-qual;-Wfloat-equal")
# target_compile_options(main PRIVATE "-Weverything;-Wno-c++98-compat")
set_target_properties(main PROPERTIES CXX_STANDARD 20)
set_target_properties(main PROPERTIES OUTPUT_NAME baluminc)

target_include_directories(main PRIVATE src/clasees)
target_link_libraries(main PRIVATE sfml-graphics)