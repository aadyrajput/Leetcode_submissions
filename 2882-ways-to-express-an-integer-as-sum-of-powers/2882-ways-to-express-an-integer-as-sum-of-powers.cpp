class Solution {
const int M=1e9+7;
int fun(int i,int tar,vector<int>&v,vector<vector<int>> &dp){
if(tar==0)return 1;
if(tar<0 || i>=v.size())return 0;
if(dp[i][tar]!=-1)return dp[i][tar];
int pick=0;
if(v[i]<=tar) pick=fun(i+1,tar-v[i],v,dp)%M;
int notpick=fun(i+1,tar,v,dp)%M;
return dp[i][tar]=(pick+notpick)%M;
}
public:
    int numberOfWays(int n, int x) {
        vector<int> v;
        for(int i=1; i<=n; i++){
            long long z=1;
            for(int j=0;j<x; j++)z*=i;
            if(z>n)break;
            v.push_back(z);
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(0,n,v,dp);
    }
};