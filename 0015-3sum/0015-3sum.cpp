class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        map<int,int> m;
        for(auto it:nums)m[it]++;
        for(auto it:m){
            for(auto itt:m){
                int a=it.first;
                int b=itt.first;
                int c=0-a-b;
                if(m.count(c)==0) continue;
                if(a==b && a==c){
                    if(m[a]<3) continue;
                    vector<int> t; 
                         t.push_back(a); t.push_back(a); t.push_back(a);
                         s.insert(t);
                }
                else if(a==b && a!=c){
                    if(m[a]<2) continue;
                    vector<int> t;
                    t.push_back(a); t.push_back(a); t.push_back(c);
                    s.insert(t);
                }
                else if(a<b && b<c){
                    vector<int> t;
                   t.push_back(a); t.push_back(b); t.push_back(c);
                    s.insert(t);
                }

            }
        }

        vector<vector<int>> ans;
        for(auto it:s)ans.push_back(it);
        return ans;
    }
};