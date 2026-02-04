class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>> st;
        sort(intervals.begin(),intervals.end());
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int a=intervals[i][0]; int b=intervals[i][1];
            int x=st.top().first; int y=st.top().second;
            if(a>y){
                st.push({a,b});
            }
            else{
                st.pop();
                st.push({x,max(y,b)});
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            int a=st.top().first, b=st.top().second;
            st.pop();
            vector<int> v={a,b};
            ans.push_back(v);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};