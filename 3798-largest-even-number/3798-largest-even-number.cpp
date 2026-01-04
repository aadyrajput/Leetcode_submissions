class Solution {
public:
    string largestEven(string s) {
        string ans="";
        int n=s.size();
        if(s[n-1]=='2')return s;
        bool flag=false;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='2')flag=true;
            if(flag){
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};