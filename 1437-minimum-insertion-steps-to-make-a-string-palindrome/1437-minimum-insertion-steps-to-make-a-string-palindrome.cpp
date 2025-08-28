class Solution {
private:
int fun(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
   if(i<0 || j<0)return 0;
   if(dp[i][j]!=-1)return dp[i][j];
    int take=0;
  if(text1[i]==text2[j]) take=1+fun(i-1,j-1,text1,text2,dp);
  else take=max(fun(i,j-1,text1,text2,dp), fun(i-1,j,text1,text2,dp));
  return dp[i][j]=take;
}

public:
    int minInsertions(string s){
     int n=s.size();
     string s2;
     for(int i=n-1;i>=0;i--)s2.push_back(s[i]);
     vector<vector<int>> dp(n,vector<int>(n,-1));
     return n-fun(n-1,n-1,s,s2,dp);   
    }
};