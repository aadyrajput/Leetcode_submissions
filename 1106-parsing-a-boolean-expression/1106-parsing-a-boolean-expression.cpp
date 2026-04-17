class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i=0;i<expression.size(); i++){
            char x=expression[i];
            if(x=='(' || x==',')continue;
            else if(x=='t' || x=='f' || x=='&' || x=='|' || x=='!'){
                st.push(x);
            }
            else if(x==')'){
                bool hastrue=false, hasfalse=false;
                while(st.top()=='t' || st.top()=='f'){
                    if(st.top()=='t')hastrue=true;
                    if(st.top()=='f')hasfalse=true;
                    st.pop();
                }
                char xx=st.top();
                st.pop();
                if(xx=='!'){
                    if(hastrue)st.push('f');
                    else st.push('t');
                }
                else if(xx=='&'){
                    if(hasfalse)st.push('f');
                    else st.push('t');
                }
                else if(xx=='|'){
                    if(hastrue)st.push('t');
                    else st.push('f');
                }
            }
        }

        if(st.top()=='t')return true;
        return false;
    }
};