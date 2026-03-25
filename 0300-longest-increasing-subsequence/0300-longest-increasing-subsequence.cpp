class Solution {
public:
    int fun(int i,int last,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        int nottake=fun(i+1,last,nums,dp);
        int take=0;
        if(last==-1 || nums[i]>nums[last]) take=1+fun(i+1,i,nums,dp);
        return dp[i][last+1]=max(nottake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(0,-1,nums,dp);
    }
};