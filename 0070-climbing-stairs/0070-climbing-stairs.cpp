class Solution {
public:
    int dp[50];
    int fun(int x){
        if(x<=2)return x;
        if(dp[x]!=-1)return dp[x];
        return dp[x]=fun(x-1)+fun(x-2);
    }
    int climbStairs(int n) {
        if(n<=2)return n;
        memset(dp,-1,sizeof(dp));
        return fun(n);
    }
};