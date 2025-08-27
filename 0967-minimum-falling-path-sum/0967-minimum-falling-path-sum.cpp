class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
    for(int j=0; j<n; j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0;j<n; j++){
    int b=INT_MAX, bl=INT_MAX, br=INT_MAX;    
     b=matrix[i][j]+dp[i-1][j];
    if(j-1>=0) bl=matrix[i][j]+dp[i-1][j-1];
    if(j+1<=n-1) br=matrix[i][j]+dp[i-1][j+1];
     dp[i][j]=min(b,min(bl,br));
        }
    }
    int ans=INT_MAX;
        for(int j=0;j<n; j++){
            ans=min(ans,dp[n-1][j]);
        }
    return ans;
    }
};