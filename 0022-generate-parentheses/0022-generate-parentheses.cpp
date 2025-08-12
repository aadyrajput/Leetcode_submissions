class Solution {
private:
void fun(int i,int n,string temp,int open,int close,vector<string>&ans){
    if(i==n*2){
        ans.push_back(temp);
        return;
    }
    if(open<n){
        fun(i+1,n,temp+"(",open+1,close,ans);
    }
    if(close<open){
        fun(i+1,n,temp+")",open,close+1,ans);
    }
}

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; string temp="";
        fun(0,n,temp,0,0,ans);
        return ans;       
    }
};