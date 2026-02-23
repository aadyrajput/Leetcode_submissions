class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> m;
        for(auto it:roads){
            m[it[0]]++;
            m[it[1]]++;
        }
        vector<int> v;
        for(auto it:m)v.push_back(it.second);
        sort(v.begin(),v.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<v.size();i++){
            long long z=v[i]*1ll*(n-i);
            ans+=z;
        }
        return ans;
        

    }
};