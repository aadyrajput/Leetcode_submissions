class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size(); int x=n+n-1;
        for(int  i=0;i<n-1; i++) nums.push_back(nums[i]);
          vector<int> nge(x);
        for(int i=0; i<x; i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                nge[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        vector<int> ans;
        for(int i=0;i<n; i++){
            ans.push_back(nge[i]);
        }
        return ans;
    }
};