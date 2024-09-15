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