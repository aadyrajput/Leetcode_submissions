class Solution {
private:
static bool comp(string &a,string &b){
    return a.size()<b.size();
}
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string a=words[i]; string b=words[j];
                if(a.size()==b.size()+1 && dp[j]+1>dp[i]){
                    int ct=0; int p1=0; int p2=0; int flag=0;
                    while(p1<a.size() && p2<b.size()){
                        if(a[p1]==b[p2]){p1++; p2++; ct++;}
                        else{
                            if(flag==0){flag=1; p1++;}
                            else break;
                        }
                    }

                if(ct==b.size())dp[i]=1+dp[j];
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
    return ans;
    }
};