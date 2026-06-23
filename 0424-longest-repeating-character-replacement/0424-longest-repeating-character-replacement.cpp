class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int ptr=0;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            int maxa=-1;
            m[s[i]]++;
            for(auto it:m){
                maxa=max(maxa,it.second);
            }
            int tot_char=i-ptr+1;
            if(tot_char-maxa>k){
                m[s[ptr]]--; ptr++;
            }
            ans=max(ans,i-ptr+1);
        }
    return ans;
    }
};