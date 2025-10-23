class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size()>2){
            string z;
            for(int i=0;i<s.size()-1; i++){
                int x=(s[i]+s[i+1])%10;
                char xx='0'+x;
                z.push_back(xx);
            }
            s=z;
        }
        if(s[0]==s[1])return true;
        return false;

    }
};