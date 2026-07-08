class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="";
        for(auto it:s){
            if(it==' '){
                if(temp.size()>0){st.push(temp); temp="";}
            }
            else temp+=it;
        }
        if(temp.size()>0)st.push(temp);
        string ans="";
        while(!st.empty()){
            if(ans.size()>0)ans+=" ";
            ans+=st.top();
            st.pop();
        }
    return ans;
    }
};