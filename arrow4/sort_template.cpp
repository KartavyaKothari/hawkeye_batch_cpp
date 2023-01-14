#include<bits/stdc++.h>
using namespace std;

void display(vector<int> & arr){
    for(auto ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void selection_sort(vector<int> &arr){
    cout<<"Calling selection_sort"<<endl;
}

void sort(vector<int> &arr){
    selection_sort(arr);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    sort(arr);
    display(arr);
    return 0;
}