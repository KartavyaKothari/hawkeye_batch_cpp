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


void bucket_sort(vector<int> &arr){
    // unordered_map<int,int> buckets;
    map<int,int> buckets;

    for(int ele: arr){
        // if(buckets.find(ele) == buckets.end()){
        //     buckets[ele] = 0;
        // }
        buckets[ele]++;
    }

    // for(auto row: buckets){
    //     cout<<row.first<<" "<<row.second<<endl;
    // }

    int i = 0;

    for(auto row: buckets){
        int key = row.first;
        int cnt = row.second;

        while(cnt>0){
            arr[i] = key;
            i++;
            cnt--;
        }
    }
}

void sort(vector<int> &arr){
    cout<<"Calling bucket_sort"<<endl;
    bucket_sort(arr);
}

// template <typename X, typename Y>
// class Pair{
//     public:
//     X first;
//     Y second;
// };

int main(int argc, char **argv){
    vector<int> arr = {3,4,5,3,2,3,5,6,7,8,7,6,5,4,3,2,3,4,5,6,7,8,9,8,7,6,1,8,6,7,2,2,3,4,5,6};
    display(arr);
    sort(arr);
    // sort(arr.begin(),arr.end(),cmp_desc);
    display(arr);


    // pair<string,int> nameage;
    // nameage.first = "John";
    // nameage.second = 32;

    return 0;
}