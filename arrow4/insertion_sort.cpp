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

void insertion_sort(vector<int> &arr){
    cout<<"Calling insertion_sort"<<endl;

    for(int i = 1 ; i < arr.size(); i++){
        int key = arr[i];
        int curr;
        for(curr = i-1 ; curr >= 0 ; curr--){
            if(cmp_asc(key, arr[curr])){
                arr[curr+1] = arr[curr];
            }else{
                break;
            }
        }
        arr[curr+1] = key;
    }
}

void sort(vector<int> &arr){
    insertion_sort(arr);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    display(arr);
    sort(arr);
    // sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);
    return 0;
}