add_library(kruskal "Kruskal.cpp")
add_library(prim "Prim.cpp")

target_include_directories(kruskal PUBLIC ${PROJECT_SOURCE_DIR}/include/network/spanning_tree/)
target_include_directories(prim PUBLIC ${PROJECT_SOURCE_DIR}/include/network/spanning_tree/)

target_link_libraries(kruskal PRIVATE graph)
target_link_libraries(prim PRIVATE graph)