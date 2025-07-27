class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
         int x=nums.size()/3;
        while(x<nums.size()){
            ans+=nums[x]; x+=2;
        }
        return ans;
    }
};