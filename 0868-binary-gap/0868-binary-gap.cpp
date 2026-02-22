class Solution {
public:
    int binaryGap(int n) {
        int z=__builtin_popcount(n);
        if(z<=1)return 0;
        int ind=-1; int ct=1;
        int ans=0;
        for(int i=0;i<=log2(n)+1; i++){
            int p=1<<i;
            if(ind==-1){
                if(p&n){
                    ind=i;  continue;
                }
                else continue;
            }
            if(p&n){
                ans=max(ans,ct); ct=1;
            }
            else ct++;
        }
    return ans;
    }
};