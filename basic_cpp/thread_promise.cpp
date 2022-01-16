#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int factorial(future<int> &fu){
    int N, res=1;
    N = fu.get(); //set_value与get一一对应
    for(int i=N;i>1;i--){
        res *= i;
    }
    return res;
}

int main(){
    promise<int> p;
    future<int> f;
    int result;
    f = p.get_future();
    future<int> fu = async(factorial, ref(f));
    p.set_value(4); //set_value与get一一对应
    result = fu.get();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << result << endl;
    return 0;
}