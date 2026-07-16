class Solution {
public:
    vector<vector<int>> ans;
    void fun(int i,int tar,vector<int>&v,int k){
        if(i==k){
            if(tar==0){
                ans.push_back(v);
            }
            return;
        }
        int last=0;
        if(i!=0)last=v.back();
        
        for(int j=last+1; j<=9; j++){
            if(j>tar)break;
            v.push_back(j);
            fun(i+1,tar-j,v,k);
            v.pop_back();
           }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        fun(0,n,v,k);
        return ans;
    }
};