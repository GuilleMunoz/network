add_library(graph "Graph.cpp")

target_include_directories(graph PUBLIC ${PROJECT_SOURCE_DIR}/include/network/)

add_subdirectory("component")
add_subdirectory("path")
add_subdirectory("spanning_tree")