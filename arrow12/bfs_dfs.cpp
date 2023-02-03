#include<bits/stdc++.h>
using namespace std;

#define UM unordered_map

void bfs(int curr, UM<int, list<int>> &adj){
    UM<int, bool> is_in_queue;
    queue<int> nodes;

    nodes.push(curr);
    is_in_queue[curr] = true;

    while(!nodes.empty()){
        int node = nodes.front();
        nodes.pop();
        cout<<node<<" ";

        for(int neigh: adj[node]){
            if(!is_in_queue[neigh]){
                nodes.push(neigh);
                is_in_queue[neigh] = true;
            }
        }
    }
}

void dfs_iterative(){

}

void dfs_recursive(int curr, UM<int, list<int>> &adj, UM<int, bool> &visited){
    cout << curr << " ";
    visited[curr] = true;

    for(int neigh: adj[curr]){
        if(!visited[neigh]){
            dfs_recursive(neigh,adj,visited);
        }
    }
}

void display(unordered_map<int, list<int>> &adj_lst){
    for(auto kv_pair: adj_lst){
        cout<<kv_pair.first<<": {";
        for(auto v: kv_pair.second){
            cout<<v<<",";
        }
        cout<<"}"<<endl;
    }
}

int main(int argc, char **argv){
    vector<pair<int,int>> edges = {
        {1,3},
        {1,4},
        {2,4},
        {2,8},
        {3,5},
        {3,8},
        {4,8},
        {5,7},
        {6,7},
        {6,8},
        {4,9}
    };

    unordered_map<int, list<int>> adj;
    for(auto edge: edges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    unordered_map<int, bool> visited;
    // vector<bool> visited;
    display(adj);
    cout<<endl;
    dfs_recursive(7,adj,visited);
    cout<<endl;
    bfs(7,adj);

    return 0;
}