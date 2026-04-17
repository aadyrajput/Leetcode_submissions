class Solution {
private:
bool isPalindrom(string &ss){
   bool ans=true;
    for(int i=0; i<=ss.size()/2; i++){
        if(ss[i]!=ss[ss.size()-1-i]) ans=false;
    }
    return ans;
}

int fun(int i,int n,string &s,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1)return dp[i];
    int mina=INT_MAX;
    string temp="";
    for(int j=i; j<n; j++){
        temp+=s[j];
        if(isPalindrom(temp)){
            int x=1+fun(j+1,n,s,dp);
            mina=min(mina,x);
        }
    }
   return dp[i]=mina;
}

public:
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1; i>=0; i--){
                string temp=""; int mina=INT_MAX;
            for(int j=i; j<n; j++){
                temp+=s[j];
              if(isPalindrom(temp)){
               int x=1+dp[j+1];
                 mina=min(mina,x);
                }
            }
       dp[i]=mina;
            }
        return dp[0]-1;
    }
};