class Solution {
const int M=1e9+7;

private:
long long fun(long long num,long long pow){
long long res=1;
num%=M;
while(pow>0){
    if(pow%2==1)res=(res*num)%M;
    num=(num*num)%M;
    pow/=2;
}
return res;
}

public:
    int countGoodNumbers(long long n) {
        long long a=n/2;
        long long b=(n+1)/2;
        long long ans1=fun(4,a);
        long long ans2=fun(5,b);
        return (ans1*ans2)%M;
    }
};