class Solution {
public:
    int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        for(int mid=i; mid<=j; mid++){
            int z=nums[i-1]*nums[mid]*nums[j+1] +fun(i,mid-1,nums,dp)+fun(mid+1,j,nums,dp);
            ans=max(ans,z);
        }

        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(1,n-2,nums,dp);
    }
};