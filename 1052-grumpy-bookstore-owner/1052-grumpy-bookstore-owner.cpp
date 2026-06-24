class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int> pre(n,0),suff(n,0);
        if(grumpy[0]==0)pre[0]=customers[0];
        if(grumpy[n-1]==0)suff[n-1]=customers[n-1];
    
        for(int i=1;i<n;i++){
            if(grumpy[i]==1)pre[i]=pre[i-1];
            else pre[i]=pre[i-1]+customers[i];
        }
        for(int i=n-2;i>=0;i--){
            if(grumpy[i]==1)suff[i]=suff[i+1];
            else suff[i]=suff[i+1]+customers[i];
        }
        vector<int> prec(n,0);
        prec[0]=customers[0];
        for(int i=1;i<n;i++)prec[i]=prec[i-1]+customers[i];
        if(minutes==n)return prec[n-1];

        int ans=0;
        ans=prec[minutes-1]+suff[minutes];
        for(int i=1;i<n-minutes;i++){
            int z=prec[i+minutes-1]-prec[i-1]+pre[i-1]+suff[i+minutes];
            ans=max(ans,z);
        }
        ans=max(ans,pre[n-minutes-1]+prec[n-1]-prec[n-minutes-1]);
    return ans;
    }
};