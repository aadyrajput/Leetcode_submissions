class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int ct1=0;
        if(s[0]=='1')ct1++;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1')ct1++;
            if(s[i]=='0' && s[i-1]=='1') ans+=ct1;
        }
    return ans;
    }
};