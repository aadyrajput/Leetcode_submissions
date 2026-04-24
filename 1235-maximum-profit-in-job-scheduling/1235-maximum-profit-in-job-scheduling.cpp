class Solution {
public:
    int fun2(vector<vector<int>>&v,int st,int tar){
        int n=v.size();
        int lo=st;
        int hi=n-1;

        int ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(v[mid][0]>=tar){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
    int fun(int i,vector<vector<int>>&v,vector<int>&dp,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int nottake=fun(i+1,v,dp,n);
        int nextind=fun2(v,i+1,v[i][1]);
        int take=v[i][2]+fun(nextind,v,dp,n);
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            v[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end());
        vector<int>dp(n+1,-1);
        return fun(0,v,dp,n);
    }
};