class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)return false;
        if(n==1)return true;
     for(int i=2; i<=31; i+=2){
        int x=1<<i;
        if(x==n)return true;
     }
     return false;

    }
};