class Solution {
    private:
    int fun(int i,int buy,int n,int fee,vector<int>&arr,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy==1) profit= max(-arr[i]+fun(i+1,0,n,fee,arr,dp),fun(i+1,1,n,fee,arr,dp));
        else profit=max(arr[i]-fee+fun(i+1,1,n,fee,arr,dp),fun(i+1,0,n,fee,arr,dp));    
        return dp[i][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,1,n,fee,prices,dp);

    }
};