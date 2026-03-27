class Solution {
public:
     int fun(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(amt==0)return 1;
            if(amt%coins[0]==0)return 1;
            return 0;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int ct1=fun(i-1,amt,coins,dp);
        int ct2=0;
        if(coins[i]<=amt) ct2=fun(i,amt-coins[i],coins,dp);
        return dp[i][amt]=ct1+ct2;
    }
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};