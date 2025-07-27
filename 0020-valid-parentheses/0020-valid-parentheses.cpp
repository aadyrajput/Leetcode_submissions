class Solution {
public:
    bool isValid(string s) {
     stack<char> st;
     map<char,int>m;
     m['(']=-1; m[')']=1; m['{']=-2; m['}']=2;m['[']=-3; m[']']=3;
     
    for(int i=0;i<s.size(); i++){
        int x=m[s[i]];
        if(x<0){st.push(x); continue;}
        int xx=(-1*x);
        if(st.empty()) return false;
        if(st.top()==xx){
            st.pop();
        }
        else st.push(x);
     }
     if(st.empty()) return true;
        return false;
    }
};