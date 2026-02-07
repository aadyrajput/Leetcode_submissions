class Solution {
public:
    int minimumDeletions(string s) {
       int n=s.size();
       vector<int> pre(n,0),suff(n,0);
       if(s[0]=='b')pre[0]=1; 
       if(s[n-1]=='a')suff[n-1]=1;
       for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+(s[i]=='b');
       }
       for(int i=n-2;i>=0; i--){
        suff[i]=suff[i+1]+(s[i]=='a');
       }
       int ans=INT_MAX;
       for(int i=1;i<n-1;i++){
        ans=min(ans,pre[i-1]+suff[i+1]);
       }
       ans=min(ans,pre[n-1]);
       ans=min(ans,suff[0]);
       return ans;


    }
};