class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1; j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        string comm="";
        int p1=m; int p2=n;
        while(p1>0 && p2>0){
            if(str1[p1-1]==str2[p2-1]){
                comm+=str1[p1-1];
                p1--; p2--;
            }
            else{
                if(dp[p1-1][p2]>dp[p1][p2-1])p1--;
                else p2--;
            }
        }
        reverse(comm.begin(),comm.end());
        
        string ans="";
     p1=0, p2=0;
    for(int k=0;k<comm.size(); k++){
        int ct=0;
        for(int i=p1; i<m; i++){
            if(str1[i]!=comm[k]){ans+=str1[i]; ct++;}
            else break;
        }
        p1+=ct;

        ct=0;
        for(int i=p2; i<n; i++){
            if(str2[i]!=comm[k]){ans+=str2[i]; ct++;}
            else break;
        }
        p2+=ct;

        ans+=comm[k];
        p1++; p2++;
    }

    while(p1<m){
        ans+=str1[p1]; p1++;
    }
    while(p2<n){
        ans+=str2[p2]; p2++;
    }

    return ans;
    }
};