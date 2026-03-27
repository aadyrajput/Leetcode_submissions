class Solution {
    public:
    bool fun(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i>=0 && j<0)return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(s2[k]!='*')return false;
            }
            return true;
        }        


        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=false;
        if(s2[j]=='?' || s1[i]==s2[j])ans=fun(i-1,j-1,s1,s2,dp);
        else{
            if(s2[j]=='*')ans=fun(i-1,j,s1,s2,dp) | fun(i,j-1,s1,s2,dp);
            }
        return dp[i][j]=ans; 
    }

    bool isMatch(string s, string p) {
      int m=s.size();
      int n=p.size();
      if(s==p)return true;
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(m-1,n-1,s,p,dp);
    }
};