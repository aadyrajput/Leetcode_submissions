class Solution {
public:
    int fun(int i1,int i2,string &text1, string &text2,vector<vector<int>> &dp){
    if(i1<0 || i2<0)return 0;
    if(dp[i1][i2]!=-1)return dp[i1][i2];
    int take=0;
  if(text1[i1]==text2[i2]) take=1+fun(i1-1,i2-1,text1,text2,dp);
  else take=max(fun(i1,i2-1,text1,text2,dp), fun(i1-1,i2,text1,text2,dp));
  return dp[i1][i2]=take;
}
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string ss=s;
        reverse(ss.begin(),ss.end());
        int n=m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,s,ss,dp);
    }
};