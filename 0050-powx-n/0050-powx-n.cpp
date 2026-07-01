class Solution {
public:
    double bin_exp(double a,int b){
        long long bb=b;
        if(b<0){
            a=1.0/a;
            bb=-bb;
        }
    
        double ans=1.0;
        while(bb){
            if(bb&1)ans=(ans*a);
            a*=a;
            bb/=2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        return bin_exp(x,n);
    }
};