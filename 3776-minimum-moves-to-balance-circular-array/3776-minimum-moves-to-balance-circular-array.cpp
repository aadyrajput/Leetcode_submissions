class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum=0;
        int n=balance.size();
        int mina=INT_MAX, min_ind=n;
        for(int i=0;i<n;i++){
            sum+=balance[i];
            if(balance[i]<0){
                min_ind=i; mina=balance[i];
        }
        }
        if(mina>=0)return 0;
        if(sum<0)return -1;

        mina=abs(mina);
        int ans=0;
        for(int i=1; i<n;i++){
            int z1=balance[(min_ind-i+n)%n];
            int z2=balance[(min_ind+i)%n];
            int z=z1+z2;
            if(mina>z){
                mina-=z; ans+=(z*i);
            }
            else{
                ans+=(mina*i); mina=0;break; 
            }
        }

    return ans;
    }
};