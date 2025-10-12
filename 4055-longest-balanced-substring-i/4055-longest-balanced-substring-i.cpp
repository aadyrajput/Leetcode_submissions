class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size(); i++){
            map<int,int> m;
            for(int j=i; j<s.size(); j++){
                m[s[j]-'a']++;
                int mina=INT_MAX; int maxa=0;
                for(auto it:m){
                    mina=min(mina,it.second);
                    maxa=max(maxa,it.second);
                }
                if(mina==maxa)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};