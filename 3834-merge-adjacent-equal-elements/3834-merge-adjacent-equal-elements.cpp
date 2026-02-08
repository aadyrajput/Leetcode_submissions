class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n=nums.size();
        stack<long long> st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            long long x=nums[i];
            while(!st.empty() && st.top()==x){
                x+=st.top();
                st.pop();
            }
             st.push(x);
        }


        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};