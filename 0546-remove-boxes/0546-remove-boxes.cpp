class Solution {
public:
    int fun(int l,int r,int streak,vector<int>&v,vector<vector<vector<int>>>&dp){
        if(l>r)return 0;
        if(l==r)return (streak+1)*(streak+1);
        if(dp[l][r][streak]!=-1)return dp[l][r][streak];
        
        int ans=fun(l+1,r,0,v,dp)+((streak+1)*(streak+1));  //when we end strak right there
        for(int i=l+1; i<=r; i++){
            if(v[l]==v[i]){
                ans=max(ans, fun(l+1,i-1,0,v,dp)+fun(i,r,streak+1,v,dp));
            }
        }
        return dp[l][r][streak]=ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return fun(0,n-1,0,boxes,dp);
    }
};