class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n,0),suff(n,0);

        if(customers[0]=='N')pre[0]=1;
        for(int i=1;i<n; i++){
           if(customers[i]=='Y') pre[i]=pre[i-1];
           else pre[i]=pre[i-1]+1;
        }
        
        if(customers[n-1]=='Y')suff[n-1]=1;         
         for(int i=n-2;i>=0; i--){
           if(customers[i]=='N') suff[i]=suff[i+1];
           else suff[i]=suff[i+1]+1;
        }
        //return suff[0];
        int ans=0; int val=suff[0];

        for(int i=1; i<=n-1; i++){
            int z=pre[i-1]+suff[i];
            if(z<val){
                val=z;
                ans=i;
            }
        }

         if(pre[n-1]<val){
            ans=n;
        }
        return ans;

    }
};