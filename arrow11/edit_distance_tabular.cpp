#include<bits/stdc++.h>
using namespace std;

int edit_distance_tab(string &first, int f_idx, string &second, int s_idx) {
    vector<vector<int>> dp(second.size()+1,vector<int>(first.size()+1,0));

    for(int i = 0 ; i < first.size()+1 ; i++){
        for(int j = 0 ; j < second.size()+1 ; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else{
                if(first[i] == second[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(
                        dp[i-1][j],
                        min(
                            dp[i][j-1],
                            dp[i-1][j-1]
                        )
                    );
                }
            }
        }
    }

    return dp.back().back();
    // return dp[first.size()][second.size()];
}

int main(int argc, char **argv){
    string me = "KARTAVYA";
    string crush = "KRITIKA";

    cout<<edit_distance_tab(me,0,crush,0)<<endl;
    return 0;
}