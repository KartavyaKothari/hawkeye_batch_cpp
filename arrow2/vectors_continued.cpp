#include<bits/stdc++.h>
using namespace std;

void display_3d(vector<vector<vector<int>>> vecna){
    for(auto mat: vecna){
        for(auto row: mat){
            for(auto ele: row)
                cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}

int main(int argc, char **argv){
    // vector<int> cells;
    // // cells.reserve(2);

    // for(int i = 0; i < 100; i++){
    //     cells.push_back(i);
    //     cout<<i<<": "<<cells.size()<<" "<<cells.capacity()<<endl;
    // }

    vector<int> linear = {1,2,3,4,5};
    vector< vector<int> > d2 = {linear,linear,linear,linear,linear};
    vector< vector<vector<int>> > d3 = {d2,d2,d2,d2,d2};

    display_3d(d3);

    // nth dim vector is a 1d vector where each element is (n-1)th dim vector


    return 0;
}