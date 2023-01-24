#include<bits/stdc++.h>
using namespace std;

int lcs(string &first, string &second){
    vector<vector<int>> dp(first.size()+1,vector<int>(second.size()+1,0));

    for(int i = 1 ; i <= first.size() ; i++){
        for(int j = 1 ; j <= second.size() ; j++){
            if(first[i-1] == second[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(
                    dp[i-1][j-1],
                    max(
                        dp[i-1][j],
                        dp[i][j-1]
                    )
                );
            }
        }
    }

    return dp.back().back();
}

int main(int argc, char **argv){
    string first, second;
    cin>>first>>second;
    cout<<"LCS: "<<lcs(first,second)<<endl;
    return 0;
}