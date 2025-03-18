set(RF_SOURCES rf.cpp rf_dev.cpp)
add_library(rf STATIC ${RF_SOURCES})
target_include_directories(rf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})