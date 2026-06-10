class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        map<char,int> m={{'(',-1},{')',1},{'[',-2},{']',2},{'{',-3},{'}',3}};

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            int z=m[st.top()];
            int zz=m[s[i]];
            if(z+zz==0 && z<0 && zz>0)st.pop();
            else st.push(s[i]);
        }

        if(st.empty())return true;
        return false;
    }
};