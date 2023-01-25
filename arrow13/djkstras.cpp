#include<bits/stdc++.h>
using namespace std;

#define UM unordered_map
#define INF 9999

void dijktras(int src, UM<int,list<pair<int,int>>> &adj, UM<int,int> &dist){
    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        for(auto edge: adj[node.second]){
            if(dist[edge.first] > dist[node.second] + edge.second){
                dist[edge.first] = dist[node.second] + edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }
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
    
    unordered_map<int,list<pair<int,int>>> adj;
    unordered_map<int,int> dist;
    for(auto edge: graph){ 
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
        dist[edge[0]] = INF;
        dist[edge[1]] = INF;
    }

    dijktras(0,adj,dist);

    for(auto kv: dist){
        cout<<kv.first<<": "<<kv.second<<endl;
    }    
    return 0;
}