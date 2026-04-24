class Solution {
public:
    int fun(int i,int n,vector<int>&v,vector<vector<int>>&dp){
        if(i==0){
            return n;
        }
        if(dp[i][n]!=-1)return dp[i][n];
        int ans=fun(i-1,n,v,dp);
        if(n>=v[i]) ans=min(ans, 1+fun(i,n-v[i],v,dp));
        return dp[i][n]=ans;
    }
    int numSquares(int n) {
        vector<int> v; int z=0;
        for(int i=1; i*i<=n; i++){
            z++;
            v.push_back(i*i);
        }
        vector<vector<int>> dp(z+1,vector<int>(n+1,-1));
        return fun(z-1,n,v,dp);
    }
};