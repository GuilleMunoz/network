add_library(tarjan "Tarjan.cpp")

target_include_directories(tarjan PUBLIC ${PROJECT_SOURCE_DIR}/include/network/component/)

target_link_libraries(tarjan PRIVATE graph)