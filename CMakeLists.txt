cmake_minimum_required(VERSION 3.18)

project(network LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(network)

# Add test executable test
add_executable(test test.cpp)

# Link libraries used (in this case all)
target_link_libraries(test PRIVATE graph)
target_link_libraries(test PRIVATE kruskal)
target_link_libraries(test PRIVATE dijkstra)
target_link_libraries(test PRIVATE FW)
target_link_libraries(test PRIVATE tarjan)
target_link_libraries(test PRIVATE prim)
target_link_libraries(test PRIVATE boruvka)