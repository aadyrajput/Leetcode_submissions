class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> v;
        for(int i=1;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        int ans=nums[0]+v[0]+v[1];
        return ans;
    }
};