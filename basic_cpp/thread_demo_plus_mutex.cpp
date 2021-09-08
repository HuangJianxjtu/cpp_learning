#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>  // sleep

using namespace std;

int global_i = 0;
mutex my_lock;

void print_one(){
    for(int i=0;i<10;i++){
        // lock()后，打印消息时就再也不会出现中断的情况了，变量访问也更安全
        my_lock.lock();
        cout<<"thread 1, value = "<<global_i<<endl;
        global_i++;
        my_lock.unlock();
        sleep(1);
    }
}

void print_two(){
    for(int j=0;j<10;j++){
        my_lock.lock();
        cout<<"thread 2, value = "<<global_i<<endl;
        global_i++;
        my_lock.unlock();
        sleep(1);
    }
}

int main(int argc, char **argv){
    thread t1(print_one);
    thread t2(print_two);
    // 没有线程锁时
    t2.join(); // t1,t2线程可以同时进行
    t1.join(); // join()后，必须等待子线程结束后，主进程才可以继续


    for(int k=0;k<10;k++){
        cout<<"main thread, value = "<<k<<endl;
        sleep(1);
    }
    return 0;
}
