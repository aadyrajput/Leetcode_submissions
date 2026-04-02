class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,0)));
        for(int k=0;k<3;k++){
            if(coins[0][0]>=0 || k==0)dp[0][0][k]=coins[0][0];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                for(int k=0;k<3;k++){
                  int best=-1e9;
                if(i-1>=0) best=max(best,coins[i][j]+dp[i-1][j][k]);
                if(j-1>=0) best=max(best,coins[i][j]+dp[i][j-1][k]);
                if(i-1>=0 && k>0) best=max(best,dp[i-1][j][k-1]);
                if(j-1>=0 && k>0) best=max(best,dp[i][j-1][k-1]);
             dp[i][j][k]=best;
            }
        }
        }

        return max({dp[m-1][n-1][0],dp[m-1][n-1][1],dp[m-1][n-1][2]});
    }
};