class Solution {
public:
const int M=1e9+7;
int delrow[4]={-1,0,1,0};
int delcol[4]={0,-1,0,1};
    long long fun(int i, int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n){
        if(dp[i][j]!=-1)return dp[i][j];
        long long ct=1;
        for(int k=0;k<4; k++){
            int nrow=delrow[k]+i; int ncol=delcol[k]+j;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]>grid[i][j]){
                 ct=(ct+fun(nrow,ncol,grid,dp,m,n))%M;
            }
        }
        return dp[i][j]=ct;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                ans= (ans+fun(i,j,grid,dp,m,n))%M;
            }
        }
        return ans;   
    }
};