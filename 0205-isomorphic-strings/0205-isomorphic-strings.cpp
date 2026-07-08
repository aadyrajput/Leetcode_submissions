class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                for(auto it:m){
                    if(it.second==t[i])return false;
                }   
                m[s[i]]=t[i];
            }
            else{
                if(m[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
};