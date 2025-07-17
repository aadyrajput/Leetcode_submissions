class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> st;
        for(auto it:intervals){
            int a=it[0]; int b=it[1];
            if(st.empty()) {st.push({a,b}); continue;}
            int x=st.top().first; int y=st.top().second;
            if(a>y){
                st.push({a,b});
            }
            else{
                st.pop();
                st.push({x,max(b,y)});
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            int a=st.top().first; int b=st.top().second;
            vector<int> temp; temp.push_back(a); temp.push_back(b);
            ans.push_back(temp);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};