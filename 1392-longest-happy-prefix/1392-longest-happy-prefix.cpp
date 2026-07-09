class Solution {
public:
     void fun(string &pat, vector<int>&lps, int m){
        int len=0;  // length of prev pref=suf;
        lps[0]=0;
        int i=1;
        
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)len=lps[len-1];
                else{
                    lps[i]=0; i++;
                }
            }
        }
        
        
    }
    string longestPrefix(string s) {
        
        int m=s.size();
        vector<int> lps(m,0);
        fun(s,lps,m);
        
        int len = lps[m-1];
    if(len == 0) return "";
    return s.substr(0, len);
    }
};