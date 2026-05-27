class Solution {
public:
    int passwordStrength(string password) {
        set<char> st;
        for(auto it:password){
            st.insert(it);
        }
        int ans=0;
        for(auto it:st){
           if(it>='a' && it<='z')ans++;
           else if(it>='A' && it<='Z')ans+=2;
           else if(it>='0' && it<='9')ans+=3;
           else ans+=5;
        }
        return ans;
    }
};