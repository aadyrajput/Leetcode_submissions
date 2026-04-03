class Solution {
public:
    vector<int> fact;
    int bin_expo(int a,int b,int M){
        int ans=1;
        while(b){
            if(b&1) ans=(ans*1ll*a)%M;
            a=(a*1ll*a)%M;
            b=b/2;
        }
        return ans;
    }

    int nCr(int a,int b,int M){
        if(a<b)return 0;
        int z1=fact[a];
        int z2=(fact[b]*1ll*fact[a-b])%M;
        int z22=bin_expo(z2,M-2,M);
        int ans=(z1*1ll*z22)%M;
        return ans;
    }

    int countVisiblePeople(int n, int pos, int k) {
        int M=1e9+7;
        if(k==0)return 2;
        fact.resize(n+1,0);
        fact[0]=fact[1]=1;
        for(int i=2; i<=n; i++){
            fact[i]=(fact[i-1]*1ll*i)%M;
        }

        long long ans=0;
         int l=pos; int r=n-1-pos;
        for(int i=0;i<=k; i++){
            int left=i; int right=k-i;
            if(left>l || right>r) continue;
            ans=(ans+ nCr(l,left,M)*1ll*nCr(r,right,M))%M;
        }

    return (ans*2)%M;
    }
};