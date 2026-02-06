class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)return 0;
        int ans=n-1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int z=(nums[i]+k-1)/k;
            int zz=lower_bound(nums.begin(),nums.end(),z)-nums.begin();
            if(zz>i)continue;
            ans=min(ans,zz+n-1-i);
        }
        return ans;
    }
};