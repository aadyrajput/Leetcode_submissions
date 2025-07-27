class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int> nge;
        stack<int> st;
        for(int i=0;i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>st.top()){
                nge[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            nge[st.top()]=-1; st.pop();
        }
        vector<int> ans;
        for(int i=0;i<nums1.size(); i++){
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    



    }
};