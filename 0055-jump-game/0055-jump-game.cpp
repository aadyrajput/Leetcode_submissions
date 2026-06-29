class Solution {
public:
    bool fun(int i,vector<int>&nums,vector<int>&dp,int n){
        if(i>=n-1)return true;
        if(dp[i]!=-1)return dp[i];
        bool ans=false;
        for(int j=i+1; j<=min(n-1,i+nums[i]); j++){
            ans=ans|fun(j,nums,dp,n);
        }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(0,nums,dp,n);
    }
};