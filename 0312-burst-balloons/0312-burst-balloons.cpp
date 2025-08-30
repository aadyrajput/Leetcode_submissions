class Solution {
private:
int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
if(i>j)return 0;
if(dp[i][j]!=-1)return dp[i][j];
int maxa=INT_MIN;
for(int k=i; k<=j; k++){
    int x=nums[i-1]*nums[j+1]*nums[k]+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp);
    maxa=max(maxa,x);
}
return dp[i][j]=maxa;
}
public:
    int maxCoins(vector<int>& nums) {
     nums.insert(nums.begin(),1);
     nums.push_back(1);
     int c=nums.size();
     vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
     return fun(1,c-2,nums,dp);
    }
};