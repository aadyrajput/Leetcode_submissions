class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int prev=0;
        int sum=0;
        int n=s.size();
        for(int i=n-1; i>=0; i--){
            if(m[s[i]]<prev)sum-=m[s[i]];
            else {sum+=m[s[i]]; prev=m[s[i]];}
        }
    return sum;
    }
};