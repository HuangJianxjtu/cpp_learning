# C++ 学习笔记

### 0. 命名约定
* 函数、类: Pascal拼写法，例如MultiplyNumbers()
* 变量名: 驼峰命名法，例如firstNumber, secondNumber

### 1.函数重载与运算符重载(overload)
overload与override
### 2.什么是const
constant, 用于修饰只读变量；不可被修改. [参考](https://www.runoob.com/w3cnote/cpp-const-keyword.html). [代码学习](./basic_cpp/const_demo.cpp)

### 3.什么是gdb调试

### 4.C++里面关于数组的大小
C++不能直接给出数组的大小,得用sizeof()函数来计算. 因此平时尽量用string, vector之类。
此外当把数组传入函数时，默认使用指针传入，此时再用sizeof()来求数组大小会出问题。

### 5. 堆与栈
一个由C/C++编译的程序占用的内存分为以下几个部分
1、栈区（stack）— 由编译器自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
2、堆区（heap） — 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表，呵呵。
3、全局区（静态区）（static）—，全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域， 未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。 - 程序结束后有系统释放
4、文字常量区—常量字符串就是放在这里的。 程序结束后由系统释放~~~~

### 6. new delete, malloc free
[参考](https://blog.csdn.net/qq_37535749/article/details/113534079)

### 6.1　C++类实例化的两种方式:new与不new
```c++
A a; //a存在栈上
A* a = new A(); //a存在堆上
```
[参考](https://zhuanlan.zhihu.com/p/62106872)

### 7. strlen
包含在<string.h>, strlen所作的仅仅是一个计数器的工作，它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，
直到碰到第一个字符串结束符'\0'为止，然后返回计数器值。

### 9. 构造函数的初始化列表
在构造函数必须用初始化列表初始化const类型成员和引用成员

### 10. [C++11新特性](https://blog.csdn.net/zhanglu_1024/article/details/85049480)
>* (1)**关键字和新语法**
>>* [auto](./basic_cpp/class_learning.cpp)：e.g. `auto i = 1;` 
>>* nullptr: 代替了NULL (**待深入了解**) 
>>* for()循环；主要采用auto实现

>* (2)**智能指针**
>>* [std::shared_ptr](./basic_cpp/cpp11_newFeatrue_ptr.cpp): 相当于集成了new和delete方法
>>* std::make_ptr
>>* std::weak_ptr

>* (3)STL容器
>>* std::array
>>* std::forward_list
>>* unordered_map****
>>* unordered_set

>* (4)多线程  
   > 在C++11以前，C++的多线程编程均需依赖系统或第三方接口实现，一定程度上影响了代码的移植性。C++11中，引入了boost库中的多线程部分内容，形成C++
标准，形成标准后的boost多线程编程部分接口基本没有变化，这样方便了以前使用boost接口开发的使用者切换使用C++标准接口，把容易把boost接口升级为C++接口。
>>* 头文件thread. 子线程的开启可用[join()](./basic_cpp/thread_demo.cpp)和[detach()](./basic_cpp/thread_demo_plus.cpp), 
    用[mutex(互斥量)](./basic_cpp/thread_demo_plus_mutex.cpp)来保证数据的访问的安全。join与detach的区别是,join中子线程执行结束后主
    线程才继续；而detach中子线程与主线程同时执行，若主线程先结束则所有程序都会被终止。**一个线程只能被join或detach一次**
>>* **死锁**一般多因程序逻辑造成
>>* **条件变量**能在多个线程之间通信，提供资源利用率。[例程1](./basic_cpp/thread_conditional_var.cpp), [例程2](./basic_cpp/thread_print_alternately.cpp)
>>* future可以让主线程获取子线程的变量值，用于等待子线程结束后获取变量值。[例程](./basic_cpp/thread_print_alternately.cpp)
>>* promise用于让子线程获取主线程的变量值。[例程](./basic_cpp/thread_print_alternately.cpp)
>>* share_future与future类似，但可以同时传入多个线程
>>* packaged_task跟thread有啥区别？似乎不常用，用到再说。。。
>>* 线程休眠3s：`std::this_thread::sleep_for(std::chrono::seconds(3))`


### 11. [模板template](https://www.runoob.com/w3cnote/c-templates-detail.html)
* **目的**：使得类中的某些数据成员或者成员函数的参数、返回值**能取任意类型**
* 模板定义 `template <typename T> `
* 通常有两种形式：[函数模板](./basic_cpp/swap.cpp)和 类模板
>>* 函数模板针对仅参数类型不同的函数
>>* 类模板针对仅数据成员和成员函数类型不同的类

### 12. 回调函数
用函数指针实现？

### 13. class和struct有啥区别
* 区别不大，大多数情况下可互用。[参考](https://blog.csdn.net/alidada_blog/article/details/83419757)
* 主要区别是在默认的继承访问权上，class默认的是private,struct默认的是public。
* 一般情况下，struct用于数据结构，class用于定义对象。