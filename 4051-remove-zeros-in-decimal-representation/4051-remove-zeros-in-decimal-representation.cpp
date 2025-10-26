class Solution {
public:
    long long removeZeros(long long n) {

        long long ans=0;
        int ct=0;
        while(n){
            int z=n%10;
            if(z!=0){
                long long zz=pow(10,ct);
                zz=zz*1ll*(n%10);
                ans+=(zz); ct++;
            }
            n=n/10;
        }
        return ans;
    }
};