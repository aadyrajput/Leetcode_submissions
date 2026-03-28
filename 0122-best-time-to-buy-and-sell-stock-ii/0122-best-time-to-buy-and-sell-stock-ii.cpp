class Solution{
public:
    int fun(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans=0;
        if(buy==1){
            ans=max(fun(i+1,1,prices,dp),-prices[i]+fun(i+1,0,prices,dp));
        }
        else{
            ans=max(fun(i+1,0,prices,dp),prices[i]+fun(i+1,1,prices,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};