class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)return 0;
        long long ans=n-999;
        if(n<1e6)return ans;
        ans+=(n-999999);
        if(n<1e9)return ans;
        ans+=(n-999999999);
        if(n<1e12)return ans;
        ans+=(n-999999999999);
        if(n<1e15)return ans;
        ans+=(n-999999999999999);
        return ans;
    }
};