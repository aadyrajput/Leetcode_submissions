class Solution {
private:
int fun(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
if(i<0 || j<0)return -1e9;
if(dp[i][j]!=-1e9)return dp[i][j];
int take=nums1[i]*nums2[j]+max(0,fun(i-1,j-1,nums1,nums2,dp));
int nottake=max(fun(i-1,j,nums1,nums2,dp),fun(i,j-1,nums1,nums2,dp));
return dp[i][j]=max(take,nottake);
}
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1e9));
        return fun(m-1,n-1,nums1,nums2,dp);
    }
};