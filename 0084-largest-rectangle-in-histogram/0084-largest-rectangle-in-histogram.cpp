class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int area=0;
        for(int i=0;i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ele=heights[st.top()]; st.pop();
                int pse=st.empty()?-1 :st.top();
                int nse=i;
                area=max(area,ele*(nse-pse-1));
            }
        st.push(i);
        }
        while(!st.empty()){
            int ele=heights[st.top()]; st.pop();
            int nse=n;
            int pse=st.empty() ? -1 :st.top();
            area=max(area,ele*(nse-pse-1));
        }

        return area;
    }
};