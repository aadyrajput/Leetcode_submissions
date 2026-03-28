class Solution {
public:
  int fun(int ind,int tar,vector<int> &arr, vector<vector<int>> &dp){
      if(ind==0){
          if(tar==0 && arr[0]==0) return 2;
          if(tar==0 || arr[0]==tar) return 1;
          return 0;
      }
      if(dp[ind][tar]!=-1) return dp[ind][tar];
      int notpick=fun(ind-1,tar,arr,dp);
      int pick=0;
      if(arr[ind]<=tar)pick=fun(ind-1,tar-arr[ind],arr,dp);
      return dp[ind][tar]=pick+notpick;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)sum+=nums[i];
        int x=sum+target;
        int tar=x/2;
        if(x%2!=0 || abs(sum)<abs(target) ) return 0;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        
        return fun(n-1,tar,nums,dp);
    }
};