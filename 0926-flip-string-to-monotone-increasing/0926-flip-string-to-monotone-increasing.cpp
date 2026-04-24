class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> pre1(n,0);
        vector<int> suff0(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1')pre1[i]=1;
            else suff0[i]=1;
        }
        for(int i=1;i<n;i++)pre1[i]+=pre1[i-1];
        for(int i=n-2;i>=0;i--)suff0[i]+=suff0[i+1];

        int ans=suff0[0];
        ans=min(ans,pre1[n-1]);
        for(int i=0;i<n-1;i++){
            int ct1=pre1[i];
            int ct2=suff0[i+1];
            ans=min(ans,ct1+ct2);
        }

    return ans;
    }
};