#include <iostream>

using namespace std;

class Fish{
private:
    float weight;
    float size;
public:
    Fish(float w, float s):weight(w),size(s) {}
    void Swim(){
        cout<<"fish swim"<<endl;
    }
    float GetWeight(){
        return weight;
    }
};

class Tuna: public Fish{
public:
    Tuna(float d, float d1, float b):Fish(d, d1){
        billLength = b;
    }
    float billLength;
    float GetPrice(){
        return GetWeight()*15;
    }
};

class Sharp:private Fish{

};

int main(){
    Fish f(20.0, 2.0);
    Tuna t(15.0, 1.0, 0.1);
    t.Swim();
    cout<<"price: "<<t.GetPrice()<<endl;
    // t.weight = 1.5;
    return 0;
}