class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.empty()) return true;

        unordered_map<int, vector<int>> adj;

        for(auto d: dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n+1, 0);
        unordered_map<int,bool> visited;
        queue<int> nodes;

        for(int a = 1 ; a <= n ; a++){
            if(color[a] != 0) continue;

            color[a] = 1;
            nodes.push(a);
            visited[a] = true;

            while(!nodes.empty()){
                int curr = nodes.front();
                nodes.pop();

                for(int neigh: adj[curr]){
                    if(color[neigh] == color[curr]) return false;
                    color[neigh] = color[curr] == 1? 2: 1;
                    if(!visited[neigh]){
                        nodes.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }
        }

        return true;
    }
};