class Solution {
private:
long long fun(int i,int j,vector<vector<long long>>&dp,vector<vector<int>>&waitCost){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 1e18;
    if(dp[i][j]!=-1)return dp[i][j];
     long long up=waitCost[i][j]+(i+1)*1ll*(j+1)+ fun(i-1,j,dp,waitCost);
    long long left=waitCost[i][j]+(i+1)*1ll*(j+1)+fun(i,j-1,dp,waitCost);
    return dp[i][j]=min(left,up);
}

public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
    return fun(m-1,n-1,dp,waitCost)-waitCost[m-1][n-1];
    }
};