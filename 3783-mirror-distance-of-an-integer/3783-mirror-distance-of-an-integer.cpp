class Solution {
public:
    int mirrorDistance(int n) {
        int ct=0; int nn=n;
        while(nn){
            ct++;
            nn/=10;
        }
        int m=0;
        ct--; int z=n;
        while(n){
            int z=n%10;
            z=z*pow(10,ct);
            m+=z;
            n/=10; ct--;
        }
        int ans=abs(z-m);
        return ans;

    }
};