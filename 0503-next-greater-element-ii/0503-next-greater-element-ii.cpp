class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(0);

    for(int i=1; i<n*2; i++){
        while(!st.empty() && nums[i%n]>nums[st.top()%n]){
            int z=st.top()%n;
            ans[z]=nums[i%n];
            st.pop();
        }
        if(ans[i%n]==-1)st.push(i%n);
    }

    while(!st.empty()){
        ans[st.top()]=-1;
        st.pop();
    }
    return ans;
    }
};