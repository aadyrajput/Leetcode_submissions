class Solution {
public:
    const int M=1e9+7;
    int fun(int i,int z,vector<vector<int>>&v,string &tar,vector<vector<int>>&dp,int n){
        if(z==tar.size())return 1;
        if(i==n) return 0;
        if(dp[i][z]!=-1)return dp[i][z];
        int nottake=fun(i+1,z,v,tar,dp,n);
        int take=0;
        if(v[i][tar[z]-'a']!=0) take=(v[i][tar[z]-'a']*1ll*fun(i+1,z+1,v,tar,dp,n))%M;
        return dp[i][z]=(take+nottake)%M;
    }
    int numWays(vector<string>& words, string target){
        int n=words[0].size();
        int z=target.size();
        if(z>n)return 0;

        vector<vector<int>> v(n,vector<int>(26,0));
        for(auto it:words){
            for(int i=0;i<it.size();i++){
                v[i][it[i]-'a']++;
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(z+1,-1));
        return fun(0,0,v,target,dp,n);
    }
};