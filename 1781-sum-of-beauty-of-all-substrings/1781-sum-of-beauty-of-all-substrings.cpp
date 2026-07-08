class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n; i++){
            vector<int> v(26,0);
            for(int j=i; j<n;j++){
                int maxa=0, mina=INT_MAX;
                v[s[j]-'a']++;
                for(int k=0;k<26;k++){
                    maxa=max(maxa,v[k]);
                    if(v[k]!=0)mina=min(mina,v[k]);
                }
                ans+=(maxa-mina);
            }
        }    
    return ans;
    }
};