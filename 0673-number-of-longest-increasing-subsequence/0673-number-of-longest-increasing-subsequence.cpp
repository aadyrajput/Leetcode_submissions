class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> arr=nums;
          int n=arr.size();
        vector<int> dp(n,1),ct(n,1);
        int maxa=1; 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    ct[i]=ct[j];
                }        
                else if(arr[j]<arr[i] && 1+dp[j]==dp[i]){
                    dp[i]=1+dp[j];
                    ct[i]+=ct[j];
                }        
                
            }
            
        }
        
        for(int i=0; i<n; i++){
            if(dp[i]>maxa){
                maxa=dp[i];  
            }
        }
    int ctt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxa){
                ctt+=ct[i];
            }
        }
    return ctt;
    }
};