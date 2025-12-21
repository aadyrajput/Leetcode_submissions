class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long ans=1e18;
        long long sum=0;
        for(auto it:cost)sum+=it;
        vector<long long> has(26,0);
        for(int i=0;i<s.size();i++){
            has[s[i]-'a']+=cost[i];
        }
        for(int i=0;i<26; i++){
            has[i]=sum-has[i];
            ans=min(ans,has[i]);
        }
        return ans;
    }
};