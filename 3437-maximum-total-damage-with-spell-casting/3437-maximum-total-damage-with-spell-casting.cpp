class Solution {
private:
long long fun(int i,vector<pair<long long,long long>>&v, vector<long long> &dp){
    if(i>=v.size())return 0;
    if(dp[i]!=-1)return dp[i];
    long long nottake=fun(i+1,v,dp);
    
    int j=i+1;
    while(j<v.size() && v[j].first<=v[i].first+2){
        j++;
    }
    long long take=v[i].second+fun(j,v,dp);
    return dp[i]=max(take,nottake);
}
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long,long long>m;
        for(auto it:power)m[it]++;
        vector<pair<long long,long long>> v;
        for(auto it:m){
            v.push_back({it.first,it.first*1ll*it.second});
        }
        int n=v.size();
        vector<long long> dp(n,-1);
        return fun(0,v,dp);
    }
};