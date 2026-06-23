class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int ptr=0;
        map<char,int> m;
        int maxa=0;

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            maxa=max(maxa,m[s[i]]);
            while((i-ptr+1)-maxa>k){
                m[s[ptr]]--;
                ptr++;
                for(auto it:m) maxa=max(maxa,it.second);
            }
            ans=max(ans,i-ptr+1);
        }
    return ans;
    }
};