## 侯捷C++课程笔记

### 1. Introduction

* C与C++的不同：对待数据与函数的方式不同。在c中变量一般是全局的
![c_vs_cpp](./imgs/c_vs_cpp.png "c vs c++")

* 两种主要的c++ class: object based类型(complex)与类型object oriented(string). string类型是一个指针


### 2. 头文件与类
* 头文件：防卫式声明(guard), #ifndef ... #define #endif
* inline function: 函数若在class body内定义完成，便**自动**成为inline候选人。若要在class body外定义inline
function, 需要在函数名称前加关键字**inline**
* access level(访问等级)：public, private. 一般数据是private, 函数是public
* **constructor(构造函数)：** 函数名称跟类的名称一样，无返回值；与其他函数相比，其有初始化列表；
constructor可以有很多个，overloading(重载); 
* **const** member functions(常量成员函数)：e.g. `double real () const {return re;}`。
作用--只会读取数据，不会修改数据。const修饰函数放在()后，修饰变量或实例放在前面
* 参数传递：值传参、引用传参和指针传参。引用传参的速度与指针传参差不多快（底层都是传指针），但形式更好看。
**尽量都使用引用传参**； pass by reference to const,使用常量引用传参，const的作用是不能修改所传参数
* friend(友元)： 友元可以获取class中的private内容，但这样会打破class的封装;相同class
的各个objects互为friends(友元)
#### 好的的class该咋写：
>* 数据放在private中
>* 尽可能使用引用传参
>* 返回值尽量使用引用返回
>* 应该加const的就要加
>* 构造函数constructor尽量使用初始化列表