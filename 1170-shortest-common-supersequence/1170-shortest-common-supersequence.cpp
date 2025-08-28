class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1; i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int p1=m; int p2=n; string ans="";
        while(p1>0 && p2>0){
            if(str1[p1-1]==str2[p2-1]){
            ans.push_back(str1[p1-1]);
            p1--; p2--;
            }
            else{
                if(dp[p1-1][p2]>dp[p1][p2-1]){
                    p1--;
                }
                else{
                    p2--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        string res="";
        int p=0;  p1=0; p2=0;
        while(p!=ans.size()){
            for(int i=p1;i<str1.size(); i++){
                if(str1[i]!=ans[p]){res+=str1[i]; }
                else{p1=i+1; break;}
            }
         for(int i=p2; i<str2.size(); i++){
            if(str2[i]!=ans[p]){res+=str2[i]; }
            else{p2=i+1; break;}
         }
        res+=ans[p];
        p++;
        }
        while(p1<m){res+=str1[p1]; p1++;}
        while(p2<n){res+=str2[p2]; p2++;}
    return res;
    }
};