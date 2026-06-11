class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size(), n2=nums2.size();
     stack<int> st;
    map<int,int> m;

    st.push(nums2[0]);
    for(int i=0;i<n2;i++){
        while(!st.empty() && nums2[i]>st.top()){
            m[st.top()]=nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }
    while(!st.empty()){
        m[st.top()]=-1;
        st.pop();
    }

    vector<int> ans;
    for(auto it:nums1){
        ans.push_back(m[it]);
    }

    return ans;
    }
};