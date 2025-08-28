class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     sort(nums.begin(),nums.end());
    int n=nums.size();
     vector<int> dp(n,1),has(n);
     for(int i=0;i<n; i++)has[i]=i;
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                dp[i]=1+dp[j];
                has[i]=j;
            }
        }
     }
        int maxa=1; int last=0;
        for(int i=0;i<n; i++){
            if(dp[i]>maxa){
                maxa=dp[i]; last=i;
            }
        }
        vector<int> v;
        v.push_back(nums[last]);
        while(has[last]!=last){
            last=has[last];
            v.push_back(nums[last]);
        }
        reverse(v.begin(),v.end());
        return v;

    }
};