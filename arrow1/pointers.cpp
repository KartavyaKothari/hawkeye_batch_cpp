#include<bits/stdc++.h>
using namespace std;

// class Example{
//     public:
//     int n;
//     vector<int> a;
//     Example(){
//         a = vector<int>(100,0);
//         // vector<char> a(100,'a');
//         for(int i: a){
//             cout<<i<<" ";
//         }
//     }  
// };

int main(int argc, char **argv){
    int a = 10;
    double b = 23.5;
    int* a_pt = &a;
    double* b_pt = &b;

    char g = 0;

    // Example ob;

    cout << "a = " << *a_pt << endl;
    cout << "b = " << *b_pt << endl;
    cout<<endl;
    cout << "add of a " << &a <<endl; 
    cout << "add of a " << a_pt <<endl;
    cout<<endl;
    cout<<b_pt<<endl;
    cout<<sizeof(double)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(int*)<<endl;
    cout<<sizeof(double*)<<endl;
    cout<<sizeof(char*)<<endl;
    // cout<<sizeof(Example)<<endl;
    // cout<<sizeof(ob)<<endl;
    // cout<<sizeof(Example*)<<endl;
    cout<<b_pt+1<<endl;

    return 0;
}