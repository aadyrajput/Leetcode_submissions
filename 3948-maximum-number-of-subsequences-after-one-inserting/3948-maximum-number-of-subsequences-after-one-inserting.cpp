class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<long long> pre(n,0),suff(n,0);
        if(s[0]=='L') pre[0]=1;
        if(s[n-1]=='T')suff[n-1]=1;
        for(int i=1; i<n; i++){
            int ct=0;
            if(s[i]=='L') ct=1;
           pre[i]+=(pre[i-1]+ct);
        }
        for(int i=n-2; i>=0; i--){
            int ct=0;
            if(s[i]=='T') ct=1;
           suff[i]+=(suff[i+1]+ct);
        }
        long long ans1=0, ans2=0,ans3=0,ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='C'){
                ans1+=(pre[i]+1)*suff[i];
                ans2+=(pre[i])*(suff[i]+1);
                ans+=pre[i]*suff[i];
            }
            else{
                ans3=max(ans3,pre[i]*suff[i]);
            }
        }
        return max(ans1,max(ans2,ans3+ans));


    }
};