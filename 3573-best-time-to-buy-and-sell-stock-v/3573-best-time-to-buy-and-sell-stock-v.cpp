class Solution {
public:   
long long fun(int i,int tran,int state,vector<int>&prices,vector<vector<vector<long long>>>&dp,int k){
        if(i==prices.size()){
            if(state==0)return 0;
            else return -1e9;
        }
        if(dp[i][tran][state]!=-1)return dp[i][tran][state];

        long long ans=fun(i+1,tran,state,prices,dp,k);
        if(state==0){
            ans=max(ans,fun(i+1,tran,1,prices,dp,k)-prices[i]);
            ans=max(ans,fun(i+1,tran,2,prices,dp,k)+prices[i]);
        }
        else if(state==1 && tran<k){
            ans=max(ans,fun(i+1,tran+1,0,prices,dp,k)+prices[i]);
        }
        else if(state==2 && tran<k){
        ans=max(ans,fun(i+1,tran+1,0,prices,dp,k)-prices[i]);
        }

        return dp[i][tran][state]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(k*2,vector<long long>(3,-1)));
        return fun(0,0,0,prices,dp,k);
    }
};