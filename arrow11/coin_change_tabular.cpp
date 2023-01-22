#include<bits/stdc++.h>
using namespace std;

int coin_change_tabular(vector<int> &coins, int sum){
    vector<vector<int>> dp(sum+1,vector<int>(coins.size(), 0));

    for(int i = 0 ; i < coins.size() ; i++){
        dp[0][i] = 1;
    }

    for(int i = 1 ; i <= sum ; i++){
        for(int j = 0 ; j < coins.size() ; j++){
            int take_the_coin = i-coins[j] >= 0 ? dp[i-coins[j]][j] : 0;
            int dont_take_coin = j - 1 >= 0 ? dp[i][j-1] : 0;

            dp[i][j] = take_the_coin+dont_take_coin;
        }
    }

    return dp.back().back();
}

int main(int argc, char **argv){
    vector<int> coins = {1,2,5,10};
    int sum = 7;

    cout<<coin_change_tabular(coins, sum);
    return 0;
}