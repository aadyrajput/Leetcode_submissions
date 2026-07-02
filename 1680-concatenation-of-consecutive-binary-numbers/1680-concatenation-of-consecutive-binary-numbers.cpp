class Solution {
public:
    int M=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int z=log2(i)+1;
            ans=(ans<<z)|i;
            ans=ans%M;
        }
    return ans;

    }
};