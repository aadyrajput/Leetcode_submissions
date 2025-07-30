class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int> st;
     int n=asteroids.size();
     vector<int> ans;
     for(int i=0;i<n; i++){
        if(asteroids[i]<0 && st.empty()){
            ans.push_back(asteroids[i]); continue;
        }
        if(asteroids[i]<0){
            bool flag=false;
        while(!st.empty() && abs(asteroids[i])>=st.top()){
            if(abs(asteroids[i])==st.top()){st.pop(); flag=true; break;}
            st.pop();
        }
        if(st.empty()){
            if(flag)continue;
            ans.push_back(asteroids[i]);
        }
        }
        else{
            st.push(asteroids[i]);
        }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());st.pop();
        }
        reverse(v.begin(),v.end());
        for(auto it:v)ans.push_back(it);
        return ans;
    }
};