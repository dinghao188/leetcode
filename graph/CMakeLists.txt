aux_source_directory(. graph_SRC)

add_executable(graph ${graph_SRC})
target_link_libraries(graph gtest_main)
gtest_discover_tests(graph)