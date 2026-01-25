class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;
        int ct=0;
        for(int i=n-1; i>=1; i--){
            if(nums[i]>nums[i-1])ct++;
            else break;
        }
        if(ct!=0)ans=min(ans,n-1-ct);
    return ans;
    }
};