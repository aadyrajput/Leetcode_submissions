class Solution {
private:
int fun(int i,int open,string &s, vector<vector<int>>&dp){
        if(i==s.size()){
            if(open==0) return true;
            return false;
        }
        if(dp[i][open]!=-1)return dp[i][open];
        bool flag=false;
        if(s[i]=='*'){
            flag= flag | fun(i+1,open+1,s,dp);
            if(open!=0) flag= flag | fun(i+1,open-1,s,dp);
            flag= flag | fun(i+1,open,s,dp);
        }
        else{
            if(s[i]=='(') flag= fun(i+1,open+1,s,dp);
            else if(open!=0){
                flag= fun(i+1,open-1,s,dp);
            }
        }
        return dp[i][open]=flag;
}
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,0,s,dp);
    }
};