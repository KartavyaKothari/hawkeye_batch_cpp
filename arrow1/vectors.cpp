#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &vec){
    // for(int i = 0; i < vec.size() ; i++){
    //     cout << vec[i] << " ";
    // }

    for(auto ele: vec){
        cout << ele << " ";
    }
}

void display(vector<string> &vec){
    // for(int i = 0; i < vec.size() ; i++){
    //     cout << vec[i] << " ";
    // }

    for(auto ele: vec){
        cout << ele << " ";
    }
}

int main(int argc, char **argv){
    // int a[10];
    // vector<int> a = {1,2,3,4};
    vector<int> a(10,42);

    a.push_back(34);

    display(a);

    vector<string> names = {"Adarsh","Mayank","Shreya"};

    display(names);

    vector< vector<int> > mat (10, vector<int>(10,1));

    for(auto col: mat){
        for(auto ele: col){
            cout << ele << " ";
        }
    }


    return 0;
}