class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        vector<int> ans;
        int ct=0; 
        for(int i=0; i<n; i++){
            if(s[i]=='(') {
                ct++;
            }
            else{
                ct--;
                if(ct==0){ans.push_back(i);}
            }
        }
        for(auto it:ans){
            s[it]='a';
            if(it+1<n) s[it+1]='a';
        }

        s[0]='a';
        s[n-1]='a';
        string res;
        for(auto it:s)if(it!='a') res.push_back(it);
        return res;
    }
};