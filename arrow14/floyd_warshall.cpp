#include<bits/stdc++.h>
using namespace std;

#define UM unordered_map
#define INF 9999

void floyd(vector<vector<int>> &adj){
    int n = 4;

    for(int k = 0; k < n; k++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){

                cout<<u<<" "<<k<<" "<<v<<endl;
                // if(adj[u][k] + adj[k][v] < adj[u][v]){
                //     adj[u][v] = adj[u][k] + adj[k][v];
                // }
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
    
    // assign1: complete this code
    // assign2: poorman dp this code
    floyd(graph);

    return 0;
}