class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto it:asteroids){
            if(st.empty()){
                if(it<0)ans.push_back(it);
                else st.push(it);
                continue;
            }
            if(it>0){
                st.push(it);
                continue;
            }
            bool flag=false;

            while(!st.empty() && abs(it)>=st.top()){
                int z=st.top();
                st.pop();
                if(abs(it)==z){
                    flag=true; break;
                }
            }
            if(flag)continue;
            if(st.empty()) ans.push_back(it);
        }

        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(auto it:v)ans.push_back(it);
        
        return ans;
    }
};