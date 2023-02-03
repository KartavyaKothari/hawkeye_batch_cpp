#include<bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<bool>> &board, int col, int row){
    int n = board.size();
    if(col >= n || row >= n) return false;

    // queen cannot be in same row
    // check if same column
    for(int i = row ; i >= 0 ; i--){
        if(board[i][col] == true) return false;
    }

    // check left and right diagonal
    for(int i = 1 ; col - i >= 0 && row - i >= 0 ; i++){
        if(board[row-i][col-i] || board[row-i][col+i]) return false;
    }

    return true;
}

int no_of_ways(vector<vector<bool>> &board, int row){
    if(row == board.size()) return 1;
    int no_ways = 0;
    for(int col = 0 ; col < board[0].size() ; col++){
        if(is_safe(board,col,row)){
            board[row][col] = true;
            no_ways += no_of_ways(board,row+1);
            board[row][col] = false;
        }
    }

    return no_ways;
}

int main(int argc, char **argv){
    int n;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    return 0;
}