class Solution {
public:
 int extend(int i,int j,int n,string s){
    int ans=0;
    while(i>=0 && j<n && s[i]==s[j]){
        ans++; i--; j++;
    }
    return ans;
 }
  int countSubstrings(string s) {
        int n=s.size();
        int ct=0;
        for(int i=0;i<n;i++){
           ct+=extend(i,i,n,s);
           ct+=extend(i,i+1,n,s);
        }
        return ct;

    }
};