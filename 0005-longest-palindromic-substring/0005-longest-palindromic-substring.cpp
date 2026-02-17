class Solution {
public:
  bool check(string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
  }
    string longestPalindrome(string s) {
        int n=s.size();
        int stind=0; int mxlen=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check(s,i,j)){
                    if(mxlen<j-i+1){
                        mxlen=j-i+1;
                        stind=i;
                    }
                }
            }
        }

        return s.substr(stind,mxlen);
    }
};