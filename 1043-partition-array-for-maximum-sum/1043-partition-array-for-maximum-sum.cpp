class Solution {
public:
    int fun(int i,vector<int>&arr,vector<int>&dp,int k,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int maxa=0;
        for(int j=i; j<min(i+k,n); j++){
            maxa=max(maxa,arr[j]);
            ans=max(ans,maxa*(j-i+1)+fun(j+1,arr,dp,k,n));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return fun(0,arr,dp,k,n);
    }
};