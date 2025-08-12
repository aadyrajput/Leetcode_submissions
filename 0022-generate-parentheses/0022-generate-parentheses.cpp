class Solution {
private:
bool isValid(string s){
    int ctl=0; int ctr=0;
    for(int i=0;i<s.size(); i++){
        if(s[i]=='(')ctl++;
        else ctr++;
        if(ctr>ctl)return false;
    }
    return ctl==ctr;
}
private:
void fun(int i,int n,string temp,vector<string>&ans){
    if(i==n*2){
        if(isValid(temp))ans.push_back(temp);
        return;
    }
    temp.push_back('(');
    fun(i+1,n,temp,ans);
    temp.pop_back();
    temp.push_back(')');
    fun(i+1,n,temp,ans);
}

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; string temp;
        fun(0,n,temp,ans);
        return ans;       
    }
};