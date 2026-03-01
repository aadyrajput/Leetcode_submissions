class Solution {
public:
    bool isPal(string &x){
        int z=x.size();
        for(int i=0;i<z/2; i++){
            if(x[i]!=x[z-1-i])return false;
        }
        return true;
    }
    void fun(int i,string &s,vector<string>&v,vector<vector<string>> &ans){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        string x;
        for(int j=i; j<s.size(); j++){
            x+=s[j];
            if(isPal(x)){
                v.push_back(x);
                fun(j+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        fun(0,s,v,ans);
        return ans;
    }
};