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
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        
        vector<int> lps(m,0);
        fun(needle,lps,m);
        
        int i=0, j=0;
        while(i<n && j<m){
            if(haystack[i]==needle[j]){
                i++; j++;
            }
            if(j==m){
                return i-j;
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return -1;   
    }
};