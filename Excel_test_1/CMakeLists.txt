cmake_minimum_required(VERSION 3.12)

project(Excel_test_1)

set(CMAKE_CXX_STANDARD 17)

set(QXLSX_DIR "C:/Users/ktmth/source/repos/codinghajo3/Excel_in_Taemin/Excel_test_1/QXlsx")

find_package(QXlsx REQUIRED PATHS ${QXLSX_DIR})

add_executable(Excel_test_1 main.cpp)

target_link_libraries(Excel_test_1 QXlsx)
