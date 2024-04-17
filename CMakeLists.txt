cmake_minimum_required(VERSION 3.28)
project(text_editor)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(text_editor main.cpp
        PieceTree.cpp
        PieceTree.h
        RedBlackTreeTest.cpp
        RedBlackTreeTest.h
)

target_link_libraries(
        text_editor
        gtest gtest_main
)
target_link_libraries(
        text_editor
        gmock gmock_main
)
include(GoogleTest)
gtest_discover_tests(text_editor)


