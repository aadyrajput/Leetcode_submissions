class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int i1= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int i2= upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i1==i2){
             ans.push_back(-1); ans.push_back(-1);
             return ans;
        }
        ans.push_back(i1); ans.push_back(i2-1);
        return ans;
    }
};