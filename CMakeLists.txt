cmake_minimum_required(VERSION 3.18)

project(network LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(network)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE graph)
target_link_libraries(test PRIVATE kruskal)
target_link_libraries(test PRIVATE dijkstra)
target_link_libraries(test PRIVATE FW)
target_link_libraries(test PRIVATE tarjan)
target_link_libraries(test PRIVATE prim)