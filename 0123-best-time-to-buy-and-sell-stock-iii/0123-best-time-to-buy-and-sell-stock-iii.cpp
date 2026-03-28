class Solution {
public:
 int fun(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int k){
        if(i==prices.size() || buy==k*2)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans=0;
        if(buy%2==0){
            ans=max(fun(i+1,buy,prices,dp,k),-prices[i]+fun(i+1,buy+1,prices,dp,k));
        }
        else{
            ans=max(fun(i+1,buy,prices,dp,k),prices[i]+fun(i+1,buy+1,prices,dp,k));
        }
        return dp[i][buy]=ans;
    }

    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         int k=2;
        vector<vector<int>> dp(n+1,vector<int>(k*2,-1));
        return fun(0,0,prices,dp,k);
    }
};