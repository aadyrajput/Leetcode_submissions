class Solution {
public:
    const int M=1e9+7;
    long long pow(int a,int b){
        long long res=1;
        while(b){
            if(b&1)res=(res*1ll*a)%M;
            a=(a*1ll*a)%M;
            b=b/2;
        }
        return res;
    }
    int sumOfNumbers(int l, int r, int k) {
        int ans=0;
        long long z=pow(r-l+1,k-1)%M;
        int sum=0;
        for(int i=l;i<=r; i++)sum+=i;
        long long zz=(z*1ll*sum)%M;
        

        long long zzz=pow(10,k);
        zzz=zzz-1;
        zzz=(zzz*1ll*pow(9,M-2))%M;
        zz=(zz*1ll*zzz)%M;
    return zz;

    }
};