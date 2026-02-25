class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        long long ans=0;
        int i=0;

        while(i<n && s[i]==' ')i++;

        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')sign=-1;
            i++;
        }

        while(i<n && (s[i]>='0' && s[i]<='9')){
            int z=s[i]-'0';

            if(ans>(INT_MAX-z)/10){
                if(sign==1)return INT_MAX;
                return INT_MIN;
            }
            ans=ans*10+z;
            i++;
        }
        return ans*sign;

    
    }
};