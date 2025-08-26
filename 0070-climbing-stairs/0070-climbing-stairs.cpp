class Solution{
private:
int fun(int i,vector<int>&dp){
    if(i<0)return 0;
    if(i==0 || i==1)return 1;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=fun(i-1,dp)+fun(i-2,dp);
}
public:
    int climbStairs(int n) {
      if(n<=2)return n;
      vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};