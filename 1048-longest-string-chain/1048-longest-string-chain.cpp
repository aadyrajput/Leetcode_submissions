class Solution {
 public:
    static bool comp(string a,string b){
        return a.size()<b.size();
    }

    bool check(string &a,string &b){
        bool flag=false;
        int p1=0; int p2=0;
        int ct=0;
        while(p1<a.size() && p2<b.size()){
            if(a[p1]==b[p2]){p1++; p2++;}
            else{
                ct++; p2++;
                if(ct>=2)return false;
            }
        }
    return true;
    }

    int longestStrChain(vector<string>& words) {
       int n=words.size();
    sort(words.begin(),words.end(),comp);
    vector<int> dp(n,1);
    
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
               string a=words[j], b=words[i];
               int len=b.size()-a.size();
               if(len==1 && check(a,b) && dp[j]+1>dp[i]){
                dp[i]=1+dp[j];
               }
            }
        }

        int maxa=1;
        for(int i=0; i<n; i++) maxa=max(maxa,dp[i]); 
        return maxa;
    }
};
