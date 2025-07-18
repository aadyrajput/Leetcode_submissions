class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1; m['X']=10; m['V']=5; m['L']=50;
        m['C']=100; m['D']=500; m['M']=1000;
        int ans=0; int prev=0;
        for(int i=s.size()-1; i>=0; i--){
            int x=m[s[i]];
            if(prev>x) ans-=x;
            else ans+=x;
            prev=x;
        }
        return ans;
    }
};