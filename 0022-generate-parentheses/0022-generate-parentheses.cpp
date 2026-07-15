class Solution {
public:
    void fun(vector<string>&ans,int op,int cl,int n,string temp){
        if(op==n && cl==n){
            ans.push_back(temp);
            return;
        }

        if(op<n){        
        temp.push_back('(');
        fun(ans,op+1,cl,n,temp);
        temp.pop_back();
        }

        if(cl<n && cl<op){
        temp.push_back(')');
        fun(ans,op,cl+1,n,temp);
        temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int op=0, cl=0;
        string temp="";
        fun(ans,op,cl,n,temp);
        return ans;
    }
};