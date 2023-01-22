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
int knapsack(int weight_left, vector<Item*> &items){
    // if(it->weight > weight_left)
    //     return dp[weight_left][item] = knapsack(weight_left, items, item - 1, dp);

    // int case_1_profit = it->profit + knapsack(
    //     weight_left - it->weight, 
    //     items, 
    //     item - 1,
    //     dp
    // );

    // int case_2_profit = knapsack(
    //     weight_left, 
    //     items, 
    //     item - 1,
    //     dp
    // );

    // return max(k1,k2,....)

    vector<vector<int>> dp(items.size()+1,vector<int>(weight_left+1,0));

    for(int i = 1 ; i <= items.size() ; i++){
        for(int j = 1 ; j <= weight_left ; j++){
            // cant take that item
            if(items[i-1]->weight > j){
                dp[i][j] = dp[i-1][j];
                continue;
            }

            // you can take the item

            // take it
            int take_it = items[i-1]->profit + dp[i-1][j-items[i-1]->weight];
            // dont take it
            int dont_take_it = dp[i-1][j];

            dp[i][j] = max(take_it, dont_take_it);
        }
    }

    return dp.back().back();
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

    cout<<"Max profit you can make: "<<knapsack(60,items)<<endl;

    return 0;
}