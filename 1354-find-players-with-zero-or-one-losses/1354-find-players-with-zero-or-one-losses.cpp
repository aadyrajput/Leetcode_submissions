class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        map<int,int> m;
        for(int i=0; i<matches.size(); i++){
            int win=matches[i][0]; int loss=matches[i][1];
            s.insert(win); s.insert(loss);
            m[loss]++;
        }
        vector<int> ans1,ans2;
        for(auto it:m){
            if(it.second==1) ans2.push_back(it.first);
            s.erase(it.first);
        }
        for(auto it:s){
            ans1.push_back(it);
        }
        vector<vector<int>> ans;
        ans.push_back(ans1); ans.push_back(ans2);
return ans;

    }
};