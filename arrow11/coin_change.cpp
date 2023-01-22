#include<bits/stdc++.h>
using namespace std;

#define DP unordered_map<int, unordered_map<int,int>>

bool find_keys(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}

int coin_change(vector<int> &coins, int idx, int sum, DP &dp){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(idx < 0) return 0;

    if(find_keys(dp,idx,sum)){
        return dp[idx][sum];
    }

    int take_the_coin = coin_change(coins, idx, sum - coins[idx], dp);
    int coin_not_taken = coin_change(coins, idx - 1, sum, dp);

    return dp[idx][sum] = take_the_coin + coin_not_taken;
}

int main(int argc, char **argv){
    vector<int> coins = {1,2,5,10};
    DP dp;
    // int sum = 8;
    // cout<<"sum = "<<sum<<" : "<<coin_change(coins, coins.size() - 1, sum, dp)<<endl;
    for(int i=0; i<10000; i++)
        cout<<"sum = "<<i<<" : "<<coin_change(coins, coins.size() - 1, i, dp)<<endl;
    return 0;
}