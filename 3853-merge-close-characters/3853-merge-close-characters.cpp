class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n=s.size();
        stack<char> st;

      for(int i=0;i<n;i++){
        if(st.empty()){st.push(s[i]); continue;}
        bool flag=false;
        stack<int> temp;
        int ct=0;
        while(!st.empty()){
            ct++;
            if(ct==k+1)break;
            if(st.top()==s[i]){flag=true; break;}
            temp.push(st.top()); st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        if(flag)continue;
        else st.push(s[i]);
      }



    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};