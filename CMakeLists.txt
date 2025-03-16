cmake_minimum_required(VERSION 3.10)  # 최소 CMake 버전
project(my_project)  # 프로젝트 이름

set(CMAKE_CXX_STANDARD 17)  # C++ 표준 지정

# Google Test 추가
add_subdirectory(third_party/googletest)
include_directories(third_party/googletest/googletest/include)

# 하위 디렉토리 추가
add_subdirectory(Rf)


# 실행 파일 생성
set(SOURCES main.cpp)
add_executable(my_project ${SOURCES})

# 하위 모듈들 링크
target_link_libraries(my_project Rf)