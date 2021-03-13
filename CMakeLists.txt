#声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)

#声明一个cmake工程
project(cpp_learning)

#使用C++11标准
set(CMAKE_CXX_STANDARD 11)

#添加一个可执行程序
#语法：add_executable(程序名 源代码文件)
add_executable(overload overload.cpp)

add_executable(overload1 overload1.cpp)

add_executable(test test.cpp)

add_executable(sf_programming1 sf/programming1.cpp)
add_executable(sf_programming2 sf/programming2.cpp)
add_executable(sf_programming2_myself sf/programming2_myself.cpp)

add_executable(meituan_q1 meituan/question1.cpp)
add_executable(meituan_q2 meituan/question2.cpp)
add_executable(meituan_q3 meituan/question3.cpp)