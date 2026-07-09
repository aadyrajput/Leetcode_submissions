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
        
    string shortestPalindrome(string s) {
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        string neww=s+'-'+rev;
        int zz=neww.size();
        vector<int> lps(zz,0);
        fun(neww,lps,zz);

        int len=lps[zz-1];

        string culprit=rev.substr(0,s.size()-len);
        return culprit + s;
    }
};