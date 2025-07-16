class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x=n/3;
        map<int,int> m;
        for(auto it:nums) m[it]++;
        vector<int> ans;
        for(auto it:m){
            if(it.second>x)ans.push_back(it.first);
        }
    return ans;
    }
};