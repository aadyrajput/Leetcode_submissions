class Solution {
public:
     bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool check(string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        else{i++;j--;}
    }
    return true;
  }
    int almostPalindromic(string s) {
        int n=s.size();
        int stind=0; int mxlen=1;
        for(int i=0;i<n;i++){
            for(int j=i+mxlen;j<n;j++){
                if(check(s,i,j)){
                        mxlen=max(mxlen,j-i+1);
                    }
                }
            }
        return mxlen;

    }
};