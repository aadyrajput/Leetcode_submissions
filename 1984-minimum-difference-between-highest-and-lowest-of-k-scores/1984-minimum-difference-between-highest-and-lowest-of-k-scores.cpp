class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        if(n==1)return 0;
        for(int i=0;i<n; i++){
            int z=i+k-1;
            if(z>=n)break;
            ans=min(ans,nums[z]-nums[i]);
        }
    return ans;
    }
};