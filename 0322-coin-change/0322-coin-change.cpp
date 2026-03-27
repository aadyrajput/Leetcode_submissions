class Solution {
public:
    int fun(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(amt%coins[0]!=0)return 1e9;
            return amt/coins[0];
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int ct1=fun(i-1,amt,coins,dp);
        int ct2=1e9;
        if(coins[i]<=amt) ct2=1+fun(i,amt-coins[i],coins,dp);
        return dp[i][amt]=min(ct1,ct2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int z=fun(n-1,amount,coins,dp);
        if(z==1e9)return -1;
        return z;
    }
};