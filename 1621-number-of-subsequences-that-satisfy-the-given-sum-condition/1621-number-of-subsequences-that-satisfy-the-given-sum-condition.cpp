class Solution {
     const int mod=1e9+7;
    long long binpow(long long a, long long b) {
        a %= mod;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res%mod;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
            sort(nums.begin(),nums.end());
            int ans=0;
            for(int i=0; i<nums.size(); i++){
                int x=upper_bound(nums.begin(), nums.end(), target-nums[i])-nums.begin();
                if(x>i) {
                    ans+=binpow(2,x-i-1)%mod; ans%=mod;}
            }
return ans%mod;
    }
};