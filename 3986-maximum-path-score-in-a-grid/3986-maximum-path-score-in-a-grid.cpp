class Solution {
private:
int fun(int i,int j,int cost,int k,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
if(i<0 || j<0 || cost>k)return -1e9;
if(i==0 && j==0){
    if(grid[i][j]==0) return 0;
    if(cost==k)return -1e9;
    return grid[0][0];   
}
if(dp[i][j][cost]!=-1)return dp[i][j][cost];

int s=0; int c=0; 
if(grid[i][j]==1){s++; c++;}
if(grid[i][j]==2){s+=2; c++;}
int up=fun(i,j-1,cost+c,k,grid,dp);
int left=fun(i-1,j,cost+c,k,grid,dp);
return dp[i][j][cost]=s+max(left,up);
}
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int ans=fun(m-1,n-1,0,k,grid,dp);
        if(ans<0)return -1;
        return ans;
    }
};