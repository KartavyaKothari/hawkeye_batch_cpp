#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> &adj_mat){
    for(int i = 0; i < adj_mat.size() ; i++){
        for(int j = 0; j < adj_mat[0].size(); j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
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
    int n = 5;
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {1,3},
        {3,4}
    };
    // This is a vector of edges
    // This is undirected graph

    // vector<vector<int>> adj_mat(5,vector<int>(5,0));
    vector<vector<bool>> adj_mat(5,vector<bool>(5,false));
    unordered_map<int, list<int>> adj_lst;

    for(auto edge: edges){
        adj_mat[edge[0]][edge[1]] = true;
        adj_mat[edge[1]][edge[0]] = true;
    }

    for(auto edge: edges){
        adj_lst[edge[0]].push_back(edge[1]);
        adj_lst[edge[1]].push_back(edge[0]);
    }

    display(adj_mat);
    cout<<endl;
    display(adj_lst);    
}