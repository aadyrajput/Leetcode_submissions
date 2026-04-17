class Solution {
public:
bool isPalindrom(string &ss){
   bool ans=true;
    for(int i=0; i<=ss.size()/2; i++){
        if(ss[i]!=ss[ss.size()-1-i]) ans=false;
    }
    return ans;
}
    int countSubstrings(string s) {
        int n=s.size();
        int ct=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n; j++){
                temp+=s[j];
                if(isPalindrom(temp))ct++;
            }
        }
        return ct;

    }
};