add_library(dijkstra "Dijkstra.cpp")
add_library(FW "FW.cpp")

target_include_directories(dijkstra PUBLIC ${PROJECT_SOURCE_DIR}/include/network/path/)
target_include_directories(FW PUBLIC ${PROJECT_SOURCE_DIR}/include/network/path/)

target_link_libraries(dijkstra PRIVATE graph)
target_link_libraries(FW PRIVATE graph)