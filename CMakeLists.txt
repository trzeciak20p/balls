cmake_minimum_required(VERSION 3.28)

project(FriendsWithYourBall
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/addSFML.cmake)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo" "Speed")
set(CMAKE_CXX_FLAGS_SPEED "-Ofast" CACHE STRING "Flags used when fast")

add_executable(main
    src/main.cpp
    src/classes/board/ball.cpp
    src/classes/board/board.cpp
    src/classes/board/wall.cpp
    src/classes/board/chargeMeter.cpp
    src/classes/board/simulation.cpp
    src/classes/gui/slider.cpp
    src/classes/gui/button.cpp
    src/classes/gui/gui.cpp
    src/classes/gui/guiScenarios.cpp
    src/classes/utils_2d.cpp
    src/classes/game.cpp
    src/classes/fontLoader.cpp
    src/classes/ui.cpp
)
set_target_properties(main PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_compile_features(main PRIVATE cxx_std_20)
target_include_directories(main PRIVATE src/clasees)
target_link_libraries(main PRIVATE sfml-window sfml-graphics)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "some resources have been coppied"
)

add_dependencies(main copy_assets)