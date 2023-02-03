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

void display(vector<int> &arr){
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void pv_counting_sort_unstable(vector<int> &arr, int p){
    cout<<"Calling pv counting sort algorithm with p = "<<p<<endl;
    map<int,unordered_map<int,int>> pv_buckets;

    for(int ele: arr){
        pv_buckets[get_pv(ele,p)][ele]++;
    }

    int idx = 0;

    for(auto kv_pair : pv_buckets){
        int pv_digit = kv_pair.first;
        auto hm = kv_pair.second;

        for(auto ele_freq_pair: hm){
            int ele = ele_freq_pair.first;
            int freq = ele_freq_pair.second;

            while(freq){
                arr[idx] = ele;
                idx++;
                freq--;
            }
        }
    }
}

void pv_counting_sort(vector<int> &arr, int p){
    cout<<"Calling pv counting sort algorithm with p = "<<p<<endl;
    vector< pair<queue<int>,unordered_map<int,int>> > pv_buckets;

    for(int ele: arr){
        pv_buckets[get_pv(ele,p)].second[ele]++;
        pv_buckets[get_pv(ele,p)].first.push(ele);
    }

    int idx = 0;

    for(auto q_hm : pv_buckets){
        auto q = q_hm.first;
        auto hm = q_hm.second;
        if(hm.empty()) continue;

        while (!q.empty()){
            int ele = q.front();
            q.pop();
            int freq = hm[ele];

            while(freq){
                arr[idx] = ele;
                idx++;
                freq--;
            }
        }
    }
}

void pv_normal_sort(vector<int> &arr, int p){
    cout<<"Calling pv normal sorting algorithm"<<endl;
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
    string tmp;
    // cout<<max_num<<endl;
    // cout<<digits(max_num)<<endl;
    for(int p = 0 ; p < digits(max_num) ; p++){
        // pv_normal_sort(arr,p);
        getline(cin,tmp);
        pv_counting_sort(arr,p);
        display(arr);
    }
}

int main(int argc, char **argv){
    vector<int> arr = {1000,99,42,7089,6,1132,489,7,77,};
    display(arr);
    radix_sort(arr);
    display(arr);
    return 0;
}