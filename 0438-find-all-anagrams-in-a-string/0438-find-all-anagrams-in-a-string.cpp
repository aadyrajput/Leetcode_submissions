class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
         if(p.size()>s.size())return ans;

        vector<int> m2(26,0),m1(26,0);
        for(auto it:p)m2[it-'a']++;
        int ptr=0;
        
        for(int i=0;i<s.size(); i++){
            m1[s[i]-'a']++;
            if(i-ptr+1<p.size())continue;
            if(m1==m2){
                ans.push_back(ptr);
            }
            m1[s[ptr]-'a']--;
            ptr++;
        }
        return ans;
    }
};