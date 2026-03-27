class Solution {
public:
    int fun(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=fun(i-1,j-1,s1,s2,dp)+fun(i-1,j,s1,s2,dp);
        }
        else{
         ans=fun(i-1,j,s1,s2,dp);
        }
        return dp[i][j]=ans; 
    }
    int numDistinct(string s, string t) {
      int m=s.size();
      int n=t.size();
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
      return fun(m-1,n-1,s,t,dp);
    }
};