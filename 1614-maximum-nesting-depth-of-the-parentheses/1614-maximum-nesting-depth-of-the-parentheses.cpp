class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(auto it:s){
            if(it=='('){st.push(it); ans=max(ans,(int)st.size());}
            else if(it==')')st.pop();
            else continue;
        }
    return ans;
    }
};