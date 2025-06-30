class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxa=0;
        map<int,int> m; vector<pair<int,int>> v;
        for(auto it:nums)m[it]++;
        for(auto it:m)v.push_back({it.first,it.second});
        for(int i=0;i<v.size()-1; i++){
            if(v[i+1].first-v[i].first==1) maxa=max(maxa,v[i+1].second+v[i].second);
        }
        return maxa;

    }
};