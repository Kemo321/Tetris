cmake_minimum_required(VERSION 3.28)

# Project name and version
project(Tetris)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files for the game
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Renderer.cpp
    src/Color.cpp
)

# Add the executable
add_executable(Tetris ${SOURCES})

# Include directories for the game
target_include_directories(Tetris PUBLIC include)

# Use FetchContent to download SDL2 and GoogleTest
include(FetchContent)

# Fetch SDL2 using a more reliable source with CMake integration
FetchContent_Declare(
    SDL2
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.9/SDL2-2.30.9.zip
)
FetchContent_MakeAvailable(SDL2)

# Link SDL2 to the Tetris executable
# SDL2_DIR is set by FetchContent_MakeAvailable when SDL2 is downloaded
target_include_directories(Tetris PUBLIC ${SDL2_SOURCE_DIR}/include)
target_link_libraries(Tetris SDL2-static)

# Fetch GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Define the test executable
set(TEST_SOURCES
    tests/GameTest.cpp
    tests/BoardTest.cpp
    tests/PieceTest.cpp
)

add_executable(TetrisTests ${TEST_SOURCES})
target_include_directories(TetrisTests PUBLIC include)

# Link GoogleTest to the test executable
target_link_libraries(TetrisTests gtest gtest_main)


# Enable testing and add tests
enable_testing()
add_test(NAME TetrisTests COMMAND TetrisTests)
