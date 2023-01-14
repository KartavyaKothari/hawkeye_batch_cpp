#include<bits/stdc++.h>
using namespace std;

void display(vector<int> & arr){
    for(auto ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

bool cmp_asc(int a, int b){
    return a < b;
}

bool cmp_desc(int a, int b){
    return a > b;
}

void selection_sort(vector<int> &arr){
    cout<<"Calling selection_sort"<<endl;

    for(int i=0; i<arr.size(); i++){
        int min_ele_idx = i;

        for(int j=i+1; j<arr.size(); j++){
            if(cmp_desc(arr[j],arr[min_ele_idx])){
                min_ele_idx = j;
            }
        }

        swap(arr[i], arr[min_ele_idx]);
    }
}

void sort(vector<int> &arr){
    selection_sort(arr);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    // sort(arr);
    sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);
    return 0;
}