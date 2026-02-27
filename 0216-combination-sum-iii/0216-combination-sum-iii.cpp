class Solution {
public:
    void fun(int i,int tar,vector<int>&v,vector<int>&temp,vector<vector<int>>&ans, int k){
        if(tar<0)return;
        if(tar==0){
            if(temp.size()==k)ans.push_back(temp);
            return;
        }
        if(i==v.size())return;
        if(v[i]<=tar){
            temp.push_back(v[i]);
            fun(i+1,tar-v[i],v,temp,ans,k);
            temp.pop_back();
        }
        fun(i+1,tar,v,temp,ans,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
        }

        vector<int> temp;
        vector<vector<int>> ans;
        fun(0,n,v,temp,ans,k);
        return ans;
    }
};