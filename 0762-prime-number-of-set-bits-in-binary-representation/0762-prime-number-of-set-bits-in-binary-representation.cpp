class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            int z=__builtin_popcount(i);
            if(z==2 || z==3 || z==5 || z==7 || z==11 || z==13 || z==17 || z==19)ans++;
        }
    return ans;
    }
};