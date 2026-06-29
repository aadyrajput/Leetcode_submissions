class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp,int n){
        if(i>=n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ct=1e9;
        for(int j=i+1; j<=min(n-1,i+nums[i]); j++){
            ct=min(ct,1+fun(j,nums,dp,n));
        }
        return dp[i]=ct;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(0,nums,dp,n);
    }
};