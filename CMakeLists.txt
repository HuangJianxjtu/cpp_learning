#声明要求的cmake最低版本
cmake_minimum_required(VERSION 3.10)

#声明一个cmake工程
project(cpp_learning)

#使用C++11标准
set(CMAKE_CXX_STANDARD 11)

#添加一个可执行程序
#语法：add_executable(程序名 源代码文件)
add_executable(overload basic_cpp/overload.cpp)
add_executable(overload1 basic_cpp/overload1.cpp)

add_executable(test_hj basic_cpp/argc_and_argv.cpp)
add_executable(delete_vector_element basic_cpp/delete_vector_element.cpp)
add_executable(for_switch basic_cpp/for_switch.cpp)

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

add_executable(permutation backTracking/permutation_checked.cpp)
add_executable(minSum_index backTracking/minSum_orderSequence_index.cpp)

add_executable(baidu_q1 baidu/question1.cpp)
add_executable(baidu_q2 baidu/question2.cpp)

add_executable(huawei_q1 huawei/question1.cpp)

add_executable(jizhijia_q1 jizhijia/q1.cpp)
add_executable(jizhijia_q1_1 jizhijia/q1_1.cpp)
add_executable(jizhijia_q2 jizhijia/q2.cpp)
add_executable(jizhijia_q2_1 jizhijia/q2_1.cpp)

add_executable(swap_1 basic_cpp/swap.cpp)

add_executable(maxSubArray leetcode/53_maxSubArray.cpp)
add_executable(uniquePaths leetcode/62_uniquePaths.cpp)
add_executable(uniquePaths_ii leetcode/63_uniquePaths_ii.cpp)
add_executable(offer_24_reverseList leetcode/offer_24_reverseList.cpp)
add_executable(class_learning basic_cpp/class_learning.cpp)
add_executable(cpp11_newPtr basic_cpp/cpp11_newFeatrue_ptr.cpp)
add_executable(offer25_mergeTwoLists leetcode/offer25_mergeTwoLists.cpp)
add_executable(8_myAtoi leetcode/8_myAtoi.cpp)
add_executable(leetcode_82 leetcode/82_Remove_Duplicates_from_Sorted_List2.cpp)
add_executable(leetcode_83 leetcode/83_Remove_Duplicates_from_Sorted_List.cpp)
add_executable(leetcode_86 leetcode/86_Partition_List.cpp)
add_executable(leetcode_92 leetcode/92_Reverse_Linked_List_II.cpp)
add_executable(leetcode_138 leetcode/138._Copy_List_with_Random_Pointer.cpp)
add_executable(leetcode_141 leetcode/141_Linked_List_Cycle.cpp)
add_executable(leetcode_142 leetcode/142_Linked_List_Cycle_plus.cpp)
add_executable(leetcode_143 leetcode/143_Reorder_List.cpp)
add_executable(leetcode_148 leetcode/148_Sort_List.cpp)
add_executable(leetcode_206 leetcode/206_Reverse_Linked_List.cpp)

add_executable(queue_demo basic_cpp/queue_demo.cpp)

add_executable(thread_demo basic_cpp/thread_demo.cpp)
target_link_libraries(thread_demo pthread)

add_executable(thread_demo_plus_mutex basic_cpp/thread_demo_plus_mutex.cpp)
target_link_libraries(thread_demo_plus_mutex pthread)

add_executable(thread_demo_plus basic_cpp/thread_demo_plus.cpp)
target_link_libraries(thread_demo_plus pthread)

add_executable(const_demo basic_cpp/const_demo.cpp)
add_executable(template_class_demo basic_cpp/template_class_demo.cpp)