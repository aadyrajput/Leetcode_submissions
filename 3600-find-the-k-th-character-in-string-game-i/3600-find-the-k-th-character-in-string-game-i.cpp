class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        if(k==1)return 'a';
        while(s.size()<k){
            int sz=s.size();
            for(int i=0; i<sz; i++){
                if(s[i]!='z') s.push_back(char(s[i]+1));
                else s.push_back('a');
            }
        }
        return s[k-1];
    }
};