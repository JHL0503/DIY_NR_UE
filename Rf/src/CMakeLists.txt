set(RF_SOURCES rf.cpp)
add_library(Rf STATIC ${RF_SOURCES})
target_include_directories(Rf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})