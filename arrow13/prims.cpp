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

int prims_mst(int src, unordered_map<int,list<pair<int,int>>> &adj){
    int min_weight = 0;
    
    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    unordered_map<int,bool> mst_set;

    pq.push({0,src});

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        // cout<<node.second<<" "<<node.first<<endl;

        if(mst_set[node.second]) continue;
        mst_set[node.second] = true;
        min_weight += node.first;
        
        for(auto neigh: adj[node.second]){
            pq.push({neigh.second, neigh.first});
        }
    }

    return min_weight;
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
    
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto edge: graph){ 
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }

    cout<<"MST: "<<prims_mst(7,adj);
    return 0;
}