class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
     vector<int> dp(n+1);
     dp[1]=1; int M=1e9+7;
     for(int i=1; i<=n; i++){
        for(int j=i+delay; j<=min(n,i+forget-1); j++){
            dp[j]=(dp[j]+dp[i])%M;
     }
     if(i+forget<=n)dp[i]=0;
     dp[i]+=dp[i-1];
     dp[i]=dp[i]%M;
     }
     return dp[n];
    }
};