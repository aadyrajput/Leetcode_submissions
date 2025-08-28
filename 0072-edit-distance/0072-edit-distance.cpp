class Solution {
private:
int fun(int i,int j,string &a,string &b,vector<vector<int>>&dp){
if(i<0) return j+1;
if(j<0) return i+1;
if(dp[i][j]!=-1)return dp[i][j];
int op=0;
if(a[i]==b[j])op=fun(i-1,j-1,a,b,dp);
else op=1+min(fun(i-1,j-1,a,b,dp),min(fun(i-1,j,a,b,dp),fun(i,j-1,a,b,dp)));
return dp[i][j]=op;
}
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,word1,word2,dp);
    }
};