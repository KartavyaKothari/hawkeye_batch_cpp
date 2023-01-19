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

void merge(vector<int> &arr, int a, int b, int mid){
    vector<int> arr1(
        arr.begin()+a,
        arr.begin()+mid+1
    );
    vector<int> arr2(
        arr.begin()+mid+1,
        arr.begin()+b+1
    );

    int i = 0;
    int j = 0;
    int k = a;

    while(i < arr1.size() && j < arr2.size()){
        if(cmp_desc(arr1[i],arr2[j])){
            arr[k] = arr1[i];
            i++;
            k++;

            // arr[k++] = arr1[i++];
        }else{
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < arr1.size()){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < arr2.size()){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int a, int b){
    if(a>=b) return;
    int mid = (a+b)/2;
    // int mid = a+(b-a)/2;

    merge_sort(arr, a, mid);
    merge_sort(arr, mid+1, b);

    merge(arr, a, b, mid);
}

void sort(vector<int> &arr){
    cout<<"Calling merge_sort"<<endl;
    merge_sort(arr,0,arr.size()-1);
}

int main(int argc, char **argv){
    vector<int> arr = {6,5,3,8,55,79,23,56,78,990,23,4};
    display(arr);
    sort(arr);
    // sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);
    return 0;
}