class Solution {
public:
      int fun(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])ans=fun(i-1,j-1,s1,s2,dp);
        else ans=1+min({fun(i-1,j-1,s1,s2,dp),fun(i-1,j,s1,s2,dp),fun(i,j-1,s1,s2,dp)});
        return dp[i][j]=ans; 
    }
    int minDistance(string word1, string word2) {
    if(word1==word2)return 0;
     int m=word1.size();
     int n=word2.size();
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(m-1,n-1,word1,word2,dp);
    }
};
