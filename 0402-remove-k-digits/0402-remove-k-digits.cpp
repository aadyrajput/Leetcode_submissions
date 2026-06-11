class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n=num.size();
        if(k>=n)return "0";

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(num[i]);
                continue;
            }
            while(!st.empty() && st.top()>num[i] && k>0){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            k--; st.pop();
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        string res; bool flag=false;
        for(auto it:ans){
            if(it=='0' && flag==false)continue;
            flag=true; res.push_back(it);
        }
        if(res.empty()) return "0";
        return res;
        

    }
};