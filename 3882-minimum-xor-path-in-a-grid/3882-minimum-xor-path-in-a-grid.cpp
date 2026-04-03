class Solution {
public:
    int fun(int i,int j,int xorr,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i<0 || j<0)return 1e9;
        xorr=xorr^grid[i][j];
        if(i==0 && j==0)return xorr;
        if(dp[i][j][xorr]!=-1)return dp[i][j][xorr];
        int left=fun(i,j-1,xorr,grid,dp);
        int up=fun(i-1,j,xorr,grid,dp);
        return dp[i][j][xorr]=min(left,up);
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return fun(m-1,n-1,0,grid,dp);
    }
};