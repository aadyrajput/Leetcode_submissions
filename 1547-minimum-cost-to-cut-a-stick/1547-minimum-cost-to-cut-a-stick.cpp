class Solution {
public:
    int fun(int l,int r,vector<int>&cuts,vector<vector<int>>&dp){
        if(l+1==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=1e9;
        for(int p=l+1;p<=r-1; p++){
            int curr=cuts[r]-cuts[l];
            ans=min(ans,curr+fun(l,p,cuts,dp)+fun(p,r,cuts,dp));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(),cuts.end());
      int c=cuts.size();
      vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    return fun(0,c-1,cuts,dp);
    }
};