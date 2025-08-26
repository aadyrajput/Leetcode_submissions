class Solution {

private:
int fun(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
    if(i<0 || j<0 || v[i][j]==1)return 0;
     if(i==0 && j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=0; int left=0;
     up=fun(i-1,j,v,dp);
     left=fun(i,j-1,v,dp);
    return dp[i][j]=up+left;
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,obstacleGrid,dp);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //     if(obstacleGrid[i][j]==1) dp[i][j]=0;
        //     else if(i==0 && j==0) dp[i][j]=1;
        //     else{
        //         int up=0; int left=0;
        //      if(i>0)  up=dp[i-1][j];
        //       if(j>0)  left=dp[i][j-1];
        //       dp[i][j]=(left+up);
        //     }
        //     }
        // }
        // return dp[m-1][n-1];
    }
};