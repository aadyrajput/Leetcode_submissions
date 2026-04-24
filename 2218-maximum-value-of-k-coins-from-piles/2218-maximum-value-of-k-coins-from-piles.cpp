class Solution {
public:
    int fun(int i,int k,vector<vector<int>>&v,vector<vector<int>>&dp,int n){
        if(i==n || k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int nottake=fun(i+1,k,v,dp,n);
        int take=0;
        int sum=0; int ct=0; 
        int zz=v[i].size(); zz=min(zz,k);
        for(int j=0;j<zz; j++){
            sum+=v[i][j]; ct++;
            take=max(take,sum+fun(i+1,k-ct,v,dp,n));
        }    
        return dp[i][k]=max(take,nottake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return fun(0,k,piles,dp,n);
    }
};