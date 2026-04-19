class Solution {
public:
    int fun(int i,int left,vector<int>&v,vector<vector<int>>&dp,int n){
        if(i==n && left==0)return 0;
        if(i==n || left<0)return 1e9;
        if(dp[i][left]!=-1)return dp[i][left];
        int ans=1e9;
        int maxa=-1;
        for(int j=i; j<n; j++){
            maxa=max(maxa,v[j]);
            ans=min(ans,maxa+fun(j+1,left-1,v,dp,n));
        }
        return dp[i][left]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
     int n=jobDifficulty.size();
     if(n<d)return -1;
     vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
     return fun(0,d,jobDifficulty,dp,n);
    }
};