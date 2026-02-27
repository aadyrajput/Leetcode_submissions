class Solution {
public:
    void fun(int i,int tar,vector<int>&can,vector<int>&v,set<vector<int>>&st){
        if(tar==0 || i==can.size()){
            if(tar==0)st.insert(v);
            return;
        }
        for(int j=i; j<can.size(); j++){
            if(j>i && can[j]==can[j-1])continue;
            if(can[j]>tar)break;
            v.push_back(can[j]);
            fun(j+1,tar-can[j],can,v,st);
            v.pop_back();    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> st;
        vector<int> v;
        fun(0,target,candidates,v,st);

        vector<vector<int>> ans;
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};