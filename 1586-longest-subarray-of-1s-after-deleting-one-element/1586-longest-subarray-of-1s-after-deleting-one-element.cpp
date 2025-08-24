class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n),suff(n);
        pre[0]=nums[0]; suff[n-1]=nums[n-1];
        for(int i=1; i<n; i++){
            if(nums[i]==0)pre[i]=0;
            else pre[i]=1+pre[i-1];
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i]==0)suff[i]=0;
            else suff[i]=1+suff[i+1];
        }
        int maxa=0; int ct=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){ct++;continue;}
        int left=0,right=0;
          if(i-1>=0) left=pre[i-1];
          if(i+1<=n-1)right=suff[i+1];
          maxa=max(maxa,left+right);
        }
        if(ct==n)return n-1;
        return maxa;
    }
};