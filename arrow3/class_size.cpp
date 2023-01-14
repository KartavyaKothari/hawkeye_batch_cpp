#include<bits/stdc++.h>
using namespace std;

class Example{
    int a,b,c,d,e;
    vector<char> arr = {1,2,3};
};

int main(int argc, char **argv){
    Example ex;

    vector<Example> arr(10,ex);

    cout<<"Size of class: "<<sizeof(Example)<<endl;
    cout<<"Size of obejct of class: "<<sizeof(ex)<<endl;
    cout<<"Size of vector<Example>: "<<sizeof(arr)<<endl;
    cout<<"Size of int in my system: "<<sizeof(int)<<endl;
    cout<<"Size of a pointer in my system: "<<sizeof(int*)<<endl;

    return 0;
}