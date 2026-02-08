class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n=nums.size();
        stack<long long> st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            long long x=nums[i];
            if(!st.empty()){
               if(st.top()==x){
                st.pop(); st.push(x*2);
               }
               else st.push(x); 
               long long a=st.top(); st.pop();
               while(!st.empty() && st.top()==a){
                  st.pop(); st.push(a*1ll*2);
                  a=st.top(); st.pop();
               }
               st.push(a);
            }
            else st.push(nums[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};