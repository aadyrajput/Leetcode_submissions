class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int>  v(26,0);
            for(int j=i;j<s.size();j++){
                v[s[j]-'a']++;
                bool flag=false; int a=0;
                for(int k=0;k<26;k++){
                    if(v[k]==0)continue;
                    if(flag==false){a=v[k]; flag=true;}
                }
                bool flag2=false;
                for(int k=0;k<26;k++){
                    if(v[k]==0 || v[k]==a)continue;
                    else flag2=true;
                }
                if(flag2==false) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};