class Solution {
public:
    string trimTrailingVowels(string s) {
        string ans="";
        int n=s.size();
        int p=n-1;
        for(int i=n-1;i>=0; i--){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o'|| s[i]=='u') p--;
            else break;
        }
        if(p==-1)return "";
        for(int i=0;i<=p;i++)ans+=s[i];
        return ans;
    }
};