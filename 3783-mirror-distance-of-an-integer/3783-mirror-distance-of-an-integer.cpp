class Solution {
public:
    int mirrorDistance(int n) {
        int nn=n;
        int rev=0;
        while(nn){
            rev=rev*10;
            rev+=(nn%10);
            nn/=10;
        }
        return abs(rev-n);
    }
};