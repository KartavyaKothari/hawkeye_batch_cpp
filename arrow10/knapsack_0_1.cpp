#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
    int weight;
    int profit;
    bool is_selected;

    Item(int weight, int profit){
        this->weight = weight;
        this->profit = profit;
        is_selected = false;
    }
};

// return to me the max profit you can get if you have weight limit and 
// items array and the poisition till which you can see the items
int knapsack(int weight_left, vector<Item*> &items, int item, unordered_map<int, unordered_map<int, int>> &dp){
    // terminating condition(s)
    if(item == -1 || weight_left == 0) return 0;
    // knapsack: k1,k1 ...

    if(dp.find(weight_left) != dp.end() && dp[weight_left].find(item) != dp[weight_left].end()){
        return dp[weight_left][item];
    }

    // if(dp.find(weight_left) != dp.end()){
    //     auto dp_w = dp[weight_left];
    //     if(dp_w.find(item) != dp_w.end())
    //         return dp[weight_left][item];
    // }

    Item* it = items[item];

    if(it->weight > weight_left)
        return dp[weight_left][item] = knapsack(weight_left, items, item - 1, dp);

    int case_1_profit = it->profit + knapsack(
        weight_left - it->weight, 
        items, 
        item - 1,
        dp
    );

    int case_2_profit = knapsack(
        weight_left, 
        items, 
        item - 1,
        dp
    );

    // return max(k1,k2,....)

    return dp[weight_left][item] = max(case_1_profit,case_2_profit);
}

int main(int argc, char **argv){
    vector<Item*> items = {
        new Item(50,100),
        new Item(20,39),
        new Item(20,39),
        new Item(15,29)
    };

    // dp(maxweight+1,vector<int>(max_item_count+1,-1))
    // vector<vector<int>> dp; dp[weight][item] = result;
    unordered_map<int, unordered_map<int, int>> dp;

    cout<<"Max profit you can make: "<<knapsack(60,items,3,dp)<<endl;

    return 0;
}