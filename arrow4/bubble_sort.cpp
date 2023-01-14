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

void bubble_sort(vector<int> &arr){
    cout<<"Calling bubble_sort"<<endl;

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr.size()-1; j++){
            if(!cmp_asc(arr[j],arr[j+1])){
                swap(arr[j],arr[j+1]);

                // int temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
            }
        }
    }
}

void sort(vector<int> &arr){
    bubble_sort(arr);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    display(arr);
    sort(arr);
    // sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);
    return 0;
}