class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> v=nums;
        reverse(v.begin(),v.end());
        for(auto it:v)nums.push_back(it);
        return nums;
    }
};