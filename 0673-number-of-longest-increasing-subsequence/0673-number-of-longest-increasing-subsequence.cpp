class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
          // Code here
        vector<int> arr=nums; int n=arr.size();
       vector<int> dp(n,1);
       vector<int> ways(n,1);
       
       for(int i=0;i<n;i++){
           for(int j=0;j<i; j++){
               if(arr[i]>arr[j] && dp[j]+1>dp[i]){
                   dp[i]=1+dp[j];
                   ways[i]=ways[j];
               }
              else if(arr[i]>arr[j] && dp[j]+1==dp[i]){
                   ways[i]+=ways[j];
               }
           }
       }
       
       int maxlen=0; int ind=-1;
       for(int i=0;i<n;i++)maxlen=max(maxlen,dp[i]);

        int ct=0;
       for(int i=0;i<n;i++){
        if(dp[i]==maxlen)ct+=ways[i];
       }
       return ct;
    }
};