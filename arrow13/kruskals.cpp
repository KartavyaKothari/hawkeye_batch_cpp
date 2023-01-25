#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &arr){
    for(auto row : arr){
        for(auto ele: row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int find_root(int ele,unordered_map<int,int> &parent){
    if(ele == parent[ele]) return ele;
    return parent[ele] = find_root(parent[ele],parent);
}

bool merge_set(int ele1, int ele2, unordered_map<int,int> &parent){
    int root1 = find_root(ele1,parent);
    int root2 = find_root(ele2,parent);

    if(root1 == root2) return false;
    parent[root1] = root2;
    return true;
}

vector<vector<int>> kruskals_mst(vector<vector<int>> &graph, int n){
    sort(graph.begin(), graph.end(), [&](auto a, auto b){return a[2]<b[2];});
    vector<vector<int>> mst;
    unordered_map<int,int> parent;

    for(int i = 0 ; i < n ; i++) parent[i] = i;

    for(auto edge: graph)
        if(merge_set(edge[0],edge[1],parent))
            mst.push_back(edge);

    return mst;
}

int main(int argc, char **argv){
    vector<vector<int>> graph = {
        {0,1,4},
        {0,7,8},
        {1,2,8},
        {1,7,11},
        {2,3,7},
        {2,5,4},
        {2,8,2},
        {3,4,9},
        {3,5,14},
        {4,5,10},
        {5,6,2},
        {6,7,1},
        {6,8,6},
        {7,8,7}
    };

    display(graph);
    auto mst = kruskals_mst(graph, 9);
    display(mst);

    return 0;
}