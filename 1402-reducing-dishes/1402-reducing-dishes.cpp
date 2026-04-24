class Solution {
public:
    int fun(int i,int ct,vector<int>&v,vector<vector<int>>&dp,int n){
        if(i==n)return 0;
        if(dp[i][ct]!=-1)return dp[i][ct];
        int nottake=fun(i+1,ct,v,dp,n);
        int take=(v[i]*ct)+fun(i+1,ct+1,v,dp,n);
        return dp[i][ct]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(0,1,satisfaction,dp,n);
    }
};