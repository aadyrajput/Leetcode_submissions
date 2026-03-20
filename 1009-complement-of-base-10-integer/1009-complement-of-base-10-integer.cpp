class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1; 
        int digits=0;
        int nn=n;
        while(nn){
            digits++;
            nn/=2;
        }

        int z=1<<(digits); z--; //return z;
        return z^n;
    }
};