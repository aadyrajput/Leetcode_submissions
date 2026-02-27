class Solution {
public:
    void fun(int i,int sum,vector<int>&can,int tar,vector<int>&v,set<vector<int>>&st){
        if(i==can.size()){
            if(sum==tar){
                st.insert(v);
            }
            return;
        }
        if(sum+can[i]<=tar){
            v.push_back(can[i]);
            fun(i,sum+can[i],can,tar,v,st);
            v.pop_back();
        }
        fun(i+1,sum,can,tar,v,st);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> v;
        fun(0,0,candidates,target,v,st);

        vector<vector<int>> ans;
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};