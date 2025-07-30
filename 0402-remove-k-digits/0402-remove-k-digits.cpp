class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(k>=num.size())return "0";
        if(k==0)return num;
        for(int i=0;i<num.size(); i++){
            while(!st.empty() && k!=0 && st.top()>num[i]){
                st.pop(); k--;
            }
            st.push(num[i]);

            if(st.size()==1 && num[i]=='0') st.pop();
        }
        
        while(k && !st.empty()){
            k--; st.pop();
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return "0";
        return ans;      

    }
};