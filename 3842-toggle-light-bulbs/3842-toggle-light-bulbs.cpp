class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        map<int,int> m;
        for(auto it:bulbs)m[it]++;
        for(auto it:m)if(it.second%2!=0)ans.push_back(it.first);

        return ans;
    }
};