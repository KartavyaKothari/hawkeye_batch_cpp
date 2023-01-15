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

int partition(vector<int> &arr, int a, int b){
    int pivot = b;
    int left = a-1;

    for(int right = a; right < b ; right++){
        if(cmp_desc(arr[right], arr[pivot])){
            left++;
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[pivot], arr[left+1]);
    return left+1;
}

void quick_sort(vector<int> &arr, int a, int b){
    if(a>=b) return;

    int p = partition(arr,a,b);

    quick_sort(arr,a,p-1);
    quick_sort(arr,p+1,b);
}

void sort(vector<int> &arr){
    cout<<"Calling quick_sort"<<endl;
    quick_sort(arr, 0, arr.size()-1);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    display(arr);
    sort(arr);
    // sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);
    return 0;
}