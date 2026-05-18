class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1)return s;

        for(int i=2;i<=n; i++){
            int ct=0; char prev;
            string ss="";
            for(int j=0;j<s.size(); j++){
                if(j==0){prev=s[j]; ct=1; continue;}
                if(s[j]==prev)ct++;
                else{ss+=char('0'+ct); ss+=prev; prev=s[j]; ct=1;}
            }
            ss+=char('0'+ct); ss+=prev;
            s=ss;
        }
        return s;

    }
};