class Solution {
public:
    bool validDigit(int n, int x) {
        int ct=0;
        int lastdigit=0;
        while(n){
            if(n%10==x)ct++;
            lastdigit=n%10;
            n=n/10;
        }
        if(ct>=1 && lastdigit!=x)return true;
        return false;

    }
};