class Solution {
public:
    int mina=0;
    int fun(int i,int budget,vector<int> &cost,vector<int>&val,vector<vector<int>>&dp){
        if(i<0){
            return budget/mina;
        }
        if(dp[i][budget]!=-1)return dp[i][budget];
        int nottake=fun(i-1,budget,cost,val,dp);
        int take=0;
        if(cost[i]<=budget) take=val[i]+fun(i-1,budget-cost[i],cost,val,dp);
        return dp[i][budget]=max(take,nottake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> cost(n), val(n);
         mina=INT_MAX;

        for(int i=0;i<n;i++){
            cost[i]=items[i][1];
            mina=min(mina,cost[i]);
            int ct=0;
            for(int j=0; j<n; j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0) ct++;
            }
            val[i]=1+ct;
        }

    vector<vector<int>> dp(cost.size(),vector<int>(budget+1,-1));
    return fun(n-1,budget,cost,val,dp);
    }
};