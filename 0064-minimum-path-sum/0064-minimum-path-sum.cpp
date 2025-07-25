class Solution {
private:
int fun(int i,int j, vector<vector<int>> &dp,vector<vector<int>> &grid){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+fun(i-1,j,dp,grid);
    int left=grid[i][j]+fun(i,j-1,dp,grid);
    return dp[i][j]=min(up,left);
}

public:
    int minPathSum(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,grid);
    }
};