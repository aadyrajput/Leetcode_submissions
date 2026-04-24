class Solution {
public:
    int fun(int i,vector<int>&days,vector<int>&costs,vector<int>&dp,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int l1=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
        int val1=costs[0]+fun(l1,days,costs,dp,n);
        
        int l2=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
        int val2=costs[1]+fun(l2,days,costs,dp,n);

        int l3=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
        int val3=costs[2]+fun(l3,days,costs,dp,n);

        return dp[i]=min({val1,val2,val3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return fun(0,days,costs,dp,n);
    }
};