class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n; i++){
            string z=s;
            z+="1";
            reverse(s.begin(),s.end());
            for(int j=0;j<s.size(); j++){
                if(s[j]=='1')s[j]='0';
                else s[j]='1';
            }
            z+=s;
            s=z;
        }
        return s[k-1];
    }
};