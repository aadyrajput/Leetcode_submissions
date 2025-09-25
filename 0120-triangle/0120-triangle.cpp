class Solution {
private:
int fun(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
  if(i==n-1) return triangle[n-1][j];
  if(dp[i][j]!=-1) return dp[i][j];
  int d= triangle[i][j]+fun(i+1,j+1,n,triangle,dp);
  int dr=triangle[i][j]+fun(i+1,j,n,triangle,dp);
  return dp[i][j]=min(d,dr);
}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return fun(0,0,n,triangle,dp);
    }
};