class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int ans=1;
        int ct=0; set<char> st;
        int p1=0; 
        for(int i=0; i<s.size(); i++){
                while(st.find(s[i])!=st.end()){
                    st.erase(s[p1]);
                    p1++;
                }
                st.insert(s[i]);
            ans=max(ans,i-p1+1);
        }

        return ans;
    }
};