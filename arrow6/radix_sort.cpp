#include<bits/stdc++.h>
using namespace std;

int digits(int n){
    int digits = 0;
    while(n>0){
        digits++;
        n/=10;
    }
    return digits;
}

int get_pv(int a, int p){
    return (a/int(pow(10,p)))%10;
}

// bool comp_pv_0(int a, int b){
//     return get_pv(a,0) < get_pv(b,0);
// }

// bool comp_pv_1(int a, int b){
// return get_pv(a,1) < get_pv(b,1);
// }

void pv_normal_sort(vector<int> &arr, int p){
    // auto cust_comp = [&](int a, int b){return a<b;};

    sort(
        arr.begin(), 
        arr.end(), 
        [&](int a, int b){
            return get_pv(a,p)<get_pv(b,p);
        }
    );
}

void radix_sort(vector<int> &arr){
    cout<<"Applying radix sort"<<endl;
    int max_num = *max_element(arr.begin(), arr.end());
    // cout<<max_num<<endl;
    // cout<<digits(max_num)<<endl;
    for(int p = 0 ; p < digits(max_num) ; p++){
        pv_normal_sort(arr,p);
    }
}

void display(vector<int> &arr){
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(int argc, char **argv){
    vector<int> arr = {1000,99,42,7089,6,1132,489,7,77};
    display(arr);
    radix_sort(arr);
    display(arr);
    return 0;
}