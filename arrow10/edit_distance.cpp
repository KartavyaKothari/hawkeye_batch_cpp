#include<bits/stdc++.h>
using namespace std;

#define DP unordered_map<int, unordered_map<int,int>>

bool find_keys(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}

int edit_distance(string &first, int f_idx, string &second, int s_idx, DP &dp) {
    if(f_idx == first.size()){
        return second.size() - s_idx;
    }

    if(s_idx == second.size()){
        return first.size() - f_idx;
    }

    if(find_keys(dp,f_idx,s_idx)){
        return dp[f_idx][s_idx];
    }

    if(first[f_idx] == second[s_idx]){
        return dp[f_idx][s_idx] = edit_distance(first, f_idx+1, second, s_idx+1, dp);
    }

    int remove_operation_cost  = edit_distance(first, f_idx+1, second, s_idx, dp);
    int insert_operation_cost  = edit_distance(first, f_idx,   second, s_idx+1, dp);
    int replace_operation_cost = edit_distance(first, f_idx+1, second, s_idx+1, dp);

    return dp[f_idx][s_idx] = 1+min(remove_operation_cost, min(replace_operation_cost, insert_operation_cost));
}

int main(int argc, char **argv){
    string me = "KARTAVYA";
    string crush = "KRITIKA";

    DP dp;

    cout<<edit_distance(me,0,crush,0,dp)<<endl;
    return 0;
}