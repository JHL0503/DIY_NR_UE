
add_executable(rf_test rf_test.cpp)
target_link_libraries(rf_test Rf gtest gtest_main pthread)