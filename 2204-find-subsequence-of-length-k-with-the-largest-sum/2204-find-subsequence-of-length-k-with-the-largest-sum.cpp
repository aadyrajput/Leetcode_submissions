class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         vector<pair<int,int>> v;
        for(int i=0;i<nums.size(); i++){
             v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());

        vector<pair<int,int>> v2;
        for(int i=0; i<k; i++){
            v2.push_back({v[i].second,v[i].first});
        }
        sort(v2.begin(),v2.end());
        vector<int> ans;
        for(auto it:v2)ans.push_back(it.second);
        return ans;
    }
};