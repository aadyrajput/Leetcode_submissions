class Solution {
public:
    long long mult(int mid,int k,int r){
        long long ans=1;
        for(int i=0;i<k; i++){
            if(ans>r)return r+1;
            ans=ans*1ll*mid;
        }
        return ans;
    }
    int bin(int r,int k){
        double lo=0, hi=r;
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(mult(mid,k,r)<=r){
                ans=mid; lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        int z1=bin(r,k);
        if(l==0){
            return z1+1;
        }
        int z2=bin(l-1,k);
        return z1-z2;
    }
};