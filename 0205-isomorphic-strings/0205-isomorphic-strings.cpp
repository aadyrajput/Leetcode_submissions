class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m, mrev;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                if(mrev.find(t[i])!=mrev.end())return false;
                mrev[t[i]]=s[i]; 
                m[s[i]]=t[i];
            }
            else{
                if(m[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
};