class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=0;
        if (dividend == INT_MIN && divisor == -1)return INT_MAX;
        if((dividend<0 &&divisor>0) || (dividend>0 && divisor<0))sign=1;
        long long n=llabs((long long)dividend);
        long long d=llabs((long long)divisor);

        long long ans=0;
        while(n>=d){
            int ct=0;
            while(n>=(d<<(ct+1))){
                ct++;
            }
            ans+=(1<<ct);
            n-=(d<<ct);
        }
        if(sign)ans=-ans;
        return ans;
    }
};