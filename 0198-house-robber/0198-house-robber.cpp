class Solution {
private:
int fun(int i,vector<int>&nums,vector<int>&dp){
    if(i==0)return nums[0];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int a=0;
    if(i>=1)a=nums[i]+fun(i-2,nums,dp);
    int b=fun(i-1,nums,dp);
    return dp[i]=max(a,b);
}

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(n-1,nums,dp);
    }
};