class Solution {
public:
    int fun(vector<int>& nums, int tar,vector<long long>&dp){
        if(tar==0)return 1;
        if(tar<0)return 0;
        if(dp[tar]!=-1)return dp[tar];
        long long z=0;
        for(auto it:nums){
            z+=fun(nums,tar-it,dp);
        }
    return dp[tar]=z;
    }
    int combinationSum4(vector<int>& nums, int target) {
       vector<long long> dp(target+1,-1);
       return fun(nums,target,dp);
    }
};