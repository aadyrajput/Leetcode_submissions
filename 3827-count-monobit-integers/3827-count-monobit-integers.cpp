class Solution {
public:
    int countMonobit(int n) {
        int ind=0;
        if(n==0) return 1;
        for(int i=0;i<12; i++){
            int x=1<<i;
            if(x<=n){ind=i;}
            else break;
        }
        int z=n+1;
        if(!(n&z)){
            return ind+2;
        }
        return ind+1;
    }
};