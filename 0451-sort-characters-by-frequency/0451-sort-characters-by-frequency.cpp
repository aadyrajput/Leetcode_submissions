class Solution {
public:
static bool comp(pair<char,int> &a,pair<char,int>&b){
    if(a.first!=b.first) return a.second>b.second;
    return a.first<b.first;
}
    string frequencySort(string s) {
        map<char,int> m;
        for(auto it:s)m[it]++;
        vector<pair<char,int>> v;
        for(auto it:m) v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),comp);
        string ans;
        for(int i=0; i<v.size(); i++){
            char x=v[i].first; int y=v[i].second;
            while(y--){
                ans.push_back(x);
            }
        }

        return ans;
    }
};