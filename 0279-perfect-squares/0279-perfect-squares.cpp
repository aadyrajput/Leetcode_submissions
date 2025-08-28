class Solution {
public:
    int numSquares(int n) {
          int a=sqrt(n);
        if(a*a==n)return 1;
        vector<int> v;
        for(int i=1; i*i<=n; i++)v.push_back(i*i);
        int m=v.size();
        vector<vector<int>> dp(m,vector<int>(n+1,1e9));
        for(int i=0;i<m;i++)dp[i][0]=0;
        for(int i=1;i<=n; i++){
            dp[0][i]=i;
        }
        
        for(int i=1;i<m; i++){
            for(int j=1; j<=n; j++){
                int notpick=dp[i-1][j];
                int pick=INT_MAX;
                if(v[i]<=j) pick=1+dp[i][j-v[i]];
                dp[i][j]=min(pick,notpick);
            }
        }
        return dp[m-1][n];
    }
};