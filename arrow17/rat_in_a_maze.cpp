#include<bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>> &maze, int a, int b){
    if(a >= maze.size() || b >= maze[0].size() || maze[a][b] == 0)
        return false;
    return true;
}

bool is_sol(vector<vector<int>> &maze, int a, int b){
    return (a == maze.size() - 1 && b == maze[0].size() - 1);
}

int no_of_ways(vector<vector<int>> &maze, int a, int b){
    if(!is_safe(maze, a, b)) return 0;
    if(is_sol(maze, a, b)) return 1;

    // mark this is sol
    // move forward and backtrack
    // umark this as sol

    int move_down = no_of_ways(maze,a+1,b);
    int move_right = no_of_ways(maze,a,b+1);

    return move_down+move_right;
}

int main(int argc, char **argv){
    vector<vector<int>> maze = { 
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 1 } 
    };
    return 0;
}




// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         if(grid[0][0]==1) return 0;
//         int row = grid.size();
//         int col = grid[0].size();

//         grid[0][0] = 1;
        
//         for(int i = 1 ; i < row ; i++){
//             if(grid[i][0] == 1){
//                 while(i<row) grid[i++][0] = 0;
//             }else grid[i][0] = 1;
//         }
        
//         for(int i = 1 ; i < col ; i++){
//             if(grid[0][i] == 1){
//                 while(i<col) grid[0][i++] = 0;
//             }else grid[0][i] = 1;
//         }
        
//         for(int i = 1 ; i < row ; i++){
//             for(int j = 1 ; j < col ; j++){
//                 grid[i][j] = grid[i][j]==0?grid[i-1][j]+grid[i][j-1]:0;
//             }
//         }
        
//         return grid.back().back();
//     }
// };