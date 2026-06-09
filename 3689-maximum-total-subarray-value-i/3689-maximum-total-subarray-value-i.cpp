class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mina=INT_MAX;
        int maxa=INT_MIN;
        for(auto it:nums){
            maxa=max(maxa,it);
            mina=min(mina,it);
        }
        int z=abs(mina-maxa);
        long long ans=z*1ll*k;
        return ans;
    }
};