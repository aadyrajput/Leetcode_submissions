class Solution {
private:
int fun(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
if(i<0 || j<0) return 0;
if(dp[i][j]!=-1)return dp[i][j];
int mina;
if(s1[i]==s2[j]){
    mina=s1[i]+fun(i-1,j-1,s1,s2,dp);
}
else mina=max(fun(i-1,j,s1,s2,dp),fun(i,j-1,s1,s2,dp));
return dp[i][j]=mina;
}
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=fun(m-1,n-1,s1,s2,dp);
        int tot=0;
        for(auto it:s1)tot+=it;
        for(auto it:s2)tot+=it;
        return tot-2*ans;

    }
};