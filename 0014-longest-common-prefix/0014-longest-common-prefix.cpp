class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int mina=1e4; 
        for(int i=0; i<strs.size(); i++){
            int x=strs[i].size();
            if(mina>x){
                ans=strs[i];
            }
            mina=min(mina,x);
        }

        int flag=-1;
        for(int j=0; j<mina; j++){
        for(int i=0; i<strs.size(); i++){
            if(strs[i][j]!=ans[j]){
                flag=j; break;
            }
        }
        if(flag!=-1)break;
    }
    if(flag==-1) return ans;
    if(flag==0) return "";
    string res;
    for(int i=0; i<flag; i++){
        res.push_back(ans[i]);
    }
    return res;
    }
};