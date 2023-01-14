#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &mat){
    for(auto col: mat){
        for(int ele: col)
            cout<<ele<<" ";
        cout<<endl;
    }
}

bool cmp_vec_idx2(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int main(int argc, char **argv){
    vector<vector<int>> mat = {
        {10,5,2,6,8,9,2,3},
        {2,4,2,6,8,9,2,3},
        {3,3,2,6,8,9,2,3},
        {4,2,2,6,8,9,2,3},
        {5,1,2,6,8,9,2,3}
    };

    display(mat);
    sort(mat.begin(), mat.end(),cmp_vec_idx2);
    cout<<endl;
    display(mat);

    return 0;
}