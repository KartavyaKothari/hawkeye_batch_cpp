#include<bits/stdc++.h>
using namespace std;
#define UM unordered_map<int,list<int>>

void dfs_first(){
    // do dfs
    // add to stack curr node, right before returning
}

void dfs_last(){
    // pop from stack and do dfs on all unvisited
    // add to solution the dfs path
    // return after dfs is done
}

vector<vector<int>> kosarjaru(UM &adj, UM &adj_rev){
    vector<vector<int>> sol;
    stack<int> order;

    dfs_first(adj, order);

    dfs_last(adj_rev,order,sol);
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

    unordered_map<int,list<int>> adj_lst;
    unordered_map<int,list<int>> adj_lst_rev;

    for(auto edge: graph){
        adj_lst[edge[0]].push_back(edge[1]);
    }

    for(auto edge: graph){
        adj_lst[edge[1]].push_back(edge[0]);
    }

    return 0;
}