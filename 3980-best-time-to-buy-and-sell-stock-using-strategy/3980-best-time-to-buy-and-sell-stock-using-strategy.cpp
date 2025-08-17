class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
     int n=prices.size();
     vector<long long> v(n),has(n),pre(n),suff(n);
     long long ans=0;
     for(int i=0;i<n;i++){
         v[i]=prices[i]*strategy[i];
         ans+=v[i];
     }
    pre[0]=v[0];
    for(int i=1;i<n;i++)pre[i]=pre[i-1]+v[i];
    suff[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--)suff[i]=suff[i+1]+v[i];
     has[0]=prices[0];
    for(int i=1;i<n; i++)has[i]=has[i-1]+prices[i];

    int l=0; int r=k-1;
    while(r!=n){
        long long ans1=0,ans2=0,ans3=0;
        if(r+1<=n-1) ans1=suff[r+1];
        if(l-1>=0) ans2=pre[l-1];
        ans3=has[r]-has[r-k/2];
        ans=max(ans,ans1+ans2+ans3);
        l++;r++;
    }
    return ans;
    }
};