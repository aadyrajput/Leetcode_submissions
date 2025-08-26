class Solution {
private:
int fun(int i,vector<int>&nums,vector<int>&dp){
    if(i==0)return nums[0];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int a=nums[i]+fun(i-2,nums,dp);
    int b=fun(i-1,nums,dp);
    return dp[i]=max(a,b);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> v1,v2;
        for(int i=0;i<nums.size()-1; i++)v1.push_back(nums[i]);
        for(int i=1;i<nums.size(); i++)v2.push_back(nums[i]);
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
       return max(fun(n-2,v1,dp1),fun(n-2,v2,dp2));
    }
};