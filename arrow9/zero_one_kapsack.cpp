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

int knapsack(int weight_left, int profit, vector<Item*> &items){
    // terminating condition(s)
    // knapsack: k1,k1 ...
    // return max(k1,k2,....)
}

int main(int argc, char **argv){

    return 0;
}