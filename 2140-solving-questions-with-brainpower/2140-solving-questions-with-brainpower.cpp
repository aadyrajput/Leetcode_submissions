class Solution {
public:
    long long fun(int i,vector<vector<int>>&v,vector<long long>&dp,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long nottake=fun(i+1,v,dp,n);
        long long take=v[i][0]+fun(i+v[i][1]+1,v,dp,n);
        return dp[i]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,-1);
        return fun(0,questions,dp,n);
    }
};