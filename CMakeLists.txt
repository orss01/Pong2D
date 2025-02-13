cmake_minimum_required(VERSION 3.28)
project(Pong2D LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(inc)

include(FetchContent)
file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(
    GLOB CPP_FILES "src/*.cpp"
)

add_executable(main  ${CPP_FILES})
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)