class Solution {
public:
    int totalMoney(int n) {
        int ct=0;
        if(n<=7)return n*(n+1)/2;
        int z=n/7;
        int ans=28*z;
        for(int i=1; i<=z; i++) ans+=(7*(i-1));
        if(n%7==0)return ans;
        int zz=z+1;
        int zzz=n%7;
        while(zzz--){
            ans+=zz;
            zz++;
        }
return ans;

    }
};