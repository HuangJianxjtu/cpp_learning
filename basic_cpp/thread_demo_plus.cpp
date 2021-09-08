#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>  // sleep

using namespace std;

mutex my_lock;

void print_one(){
    for(int i=0;i<10;i++){
        my_lock.lock();  //避免打印消息时被中断
        cout<<"thread 1, value = "<<i<<endl;
        my_lock.unlock();
        sleep(1);
    }
}

int main(int argc, char **argv){
    thread t1(print_one);
    t1.detach(); // detach()后，子线程与主线程同时运行；主线程结束后， 所有程序都要终止，无论子线程是否结束

    for(int k=0;k<5;k++){
        my_lock.lock();
        cout<<"main thread, value = "<<k<<endl;
        my_lock.unlock();
        sleep(1);
    }
    return 0;
}
