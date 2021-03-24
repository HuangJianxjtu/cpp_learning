#声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)

#声明一个cmake工程
project(cpp_learning)

#使用C++11标准
set(CMAKE_CXX_STANDARD 11)

#添加一个可执行程序
#语法：add_executable(程序名 源代码文件)
add_executable(overload basic_cpp/overload.cpp)
add_executable(overload1 basic_cpp/overload1.cpp)

add_executable(test test.cpp)
add_executable(delete_vector_element basic_cpp/delete_vector_element.cpp)

add_executable(sf_programming1 sf/programming1.cpp)
add_executable(sf_programming2 sf/programming2.cpp)
add_executable(sf_programming2_myself sf/programming2_myself.cpp)

add_executable(meituan_q1 meituan/question1.cpp)
add_executable(meituan_q2 meituan/question2.cpp)
add_executable(meituan_q3 meituan/question3.cpp)
add_executable(meituan_interview meituan/interview.cpp)
add_executable(q2_myself meituan/q2_myself.cpp)
add_executable(q3_myself meituan/q3_myself.cpp)
add_executable(q3_luo meituan/q3_luo.cpp)

add_executable(permutation backTracking/permutation.cpp)

add_executable(baidu_q1 baidu/question1.cpp)
add_executable(baidu_q2 baidu/question2.cpp)

add_executable(huawei_q1 huawei/question1.cpp)
