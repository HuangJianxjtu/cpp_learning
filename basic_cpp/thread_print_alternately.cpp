#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>  // sleep
#include <condition_variable>
#include <future>

using namespace std;

// condition_variable cv;
// mutex mtx;
// int k=0;

class Foo{
private:
    condition_variable cv;
    mutex mtx;
    int k;
public:
    Foo(){
        k=0;
    }
    void first(){ //无参数
        for(int i=0;i<10;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return k==0;});
            cout << "first" <<endl;
            k=1;
            lock.unlock();
            cv.notify_all();
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void second(int num_in){    //值传参
        for(int i=0;i<10;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return k==1;});
            cout << "second: " << num_in <<endl;
            k=2;
            lock.unlock();
            cv.notify_all();
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void third(int &num_in){ //引用传参
        for(int i=0;i<10;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return k==2;});
            cout << "third: " << num_in << endl<<endl;
            k=0;
            lock.unlock();
            cv.notify_all();
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    int my_factorial(int n){
        int res = 1;
        for(int i=n;i>1;i--){
            res *= i;
        }
        return res;
    }
};

int main(){
    int ii = 88, kk=99;
    int res_f;
    Foo f;
    thread t1(&Foo::first, &f);  //无参数
    thread t2(&Foo::second, &f, ii); //值传参
    thread t3(&Foo::third, &f, std::ref(kk)); //引用传参
    t1.join();
    t2.join();
    t3.join();

    std::future<int> fu = std::async(&Foo::my_factorial, &f, 4);
    res_f = fu.get();
    cout << "result: "<<res_f<<endl;

    // sleep(100);
}
