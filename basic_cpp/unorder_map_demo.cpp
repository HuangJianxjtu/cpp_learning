#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>  // shared_ptr

using namespace std;

class Feature{
public:
    int value;
    Feature();
};

Feature::Feature(){
    cout <<"constructor" << endl;
}


int main(){
    Feature f;
    f.value = 99;
    vector<shared_ptr<Feature>> f_set;

    shared_ptr<Feature> f1 = make_shared<Feature>();
    f1->value = 1;
    shared_ptr<Feature> f2 = make_shared<Feature>();
    f2->value = 2;

    f_set.push_back(f1);
    f_set.push_back(f2);

    cout<< f_set[0]->value <<endl;

    auto it0 = f_set.begin();
    while (it0 != f_set.end()) {
        cout<< (*it0)->value <<endl;
        it0++;
    }

    // int a;
    // int *aa;
    // aa = &a;
    // *aa =1;
    // cout<< aa <<endl;
    // cout<< *aa <<endl;

    return 0;
}