class Solution {
public:
    void fun(int op,int cl,string s,vector<string>&ans,int n){
        if(cl>op)return;
        if(op==n && cl==n){
            ans.push_back(s);
            return;
        }
        if(op+1<=n){
            fun(op+1,cl,s+"(",ans,n);
        }
        if(cl+1<=n){
            fun(op,cl+1,s+")",ans,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        fun(0,0,s,ans,n);
        return ans;
    }
};