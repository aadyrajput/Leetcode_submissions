class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)return true;
        if(n<3)return false;
        for(int i=0; i<22; i++){
            long long x=pow(3,i);
            if(x==n)return true;
        }
        return false;
    }
};