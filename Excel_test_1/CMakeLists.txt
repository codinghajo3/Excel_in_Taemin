cmake_minimum_required(VERSION 3.0.0)
project(Excel_test_1 VERSION 0.1.0 LANGUAGES C CXX)

# QXlsx 라이브러리 찾기 및 설정
find_package(QXlsx REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/qxlsx")  # qxlsx 폴더 경로 설정

include(CTest)
enable_testing()

add_executable(Excel_test_1 main.cpp)

# QXlsx 헤더 파일 위치 설정
target_include_directories(Excel_test_1 PUBLIC ${QXlsx_INCLUDE_DIRS})

# QXlsx 라이브러리 연결
target_link_libraries(Excel_test_1 QXlsx)

include(CPack)
