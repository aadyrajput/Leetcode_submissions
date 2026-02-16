class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
    for(int i=0;i<32; i++){
        int z=1<<i;
        int zz=31-i;
        int zzz=1<<zz;
        if(n&z)ans=ans|zzz;
    }
    return ans;
    }
};