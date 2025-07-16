class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0; int ct=0;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++) if(nums[i]%2==0) ct++;
        ans=max(ans,ct);
        ans=max(ans,n-ct);
        int ctx=1; int prev=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]%2!=prev%2){
                ctx++; prev=nums[i];
            }
        }
        ans=max(ans,ctx);
    return ans;
    }
};