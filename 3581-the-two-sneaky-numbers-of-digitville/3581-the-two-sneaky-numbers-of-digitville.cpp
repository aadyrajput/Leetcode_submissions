class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums)m[it]++;
        vector<int>ans;
        for(auto it:m)if(it.second>1)ans.push_back(it.first);
        return ans;
    }
};