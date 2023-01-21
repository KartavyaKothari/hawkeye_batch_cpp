#include<bits/stdc++.h>
using namespace std;


// 1 1 2 3 5 8 13 21
int fibo(int n, unordered_map<int, int> &dp){
    if(n < 2) return 1;
    if(dp.find(n) == dp.end())
        dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}

int main(int argc, char **argv){
    // int n;
    // cin>>n;
    unordered_map<int,int> dp;
    for(int i = 0 ; i < 1000000 ; i++)
        cout<<i<<" : "<<fibo(i,dp)<<endl;
    return 0;
}


// ON A BREAK TILL 11