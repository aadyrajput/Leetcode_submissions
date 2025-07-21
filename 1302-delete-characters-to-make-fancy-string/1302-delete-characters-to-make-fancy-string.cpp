class Solution {
public:
    string makeFancyString(string s) {
        int ct=1;
        char prev=s[0];
        string ans;
        ans.push_back(s[0]);
        for(int i=1;i<s.size(); i++){
            if(s[i]==prev){
                ct++; prev=s[i];
                if(ct==1 || ct==2) ans.push_back(s[i]);
                else continue;
            }
            else{ ct=1; prev=s[i];
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};