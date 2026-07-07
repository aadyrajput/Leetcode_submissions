class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;

        int z=n; int sum=0; string s;
        while(z){
            if(z%10!=0)s.push_back(char('0'+z%10));
            sum+=(z%10);
            z/=10;
        }
        reverse(s.begin(),s.end());
        long long num=0;
        for(int i=0;i<s.size();i++){
            int a=s[i]-'0';
            num=num*1ll*10; num+=a;
        }
        num=num*1ll*sum;
    return num;

    }
};