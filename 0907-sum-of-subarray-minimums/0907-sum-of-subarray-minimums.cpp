class Solution {
public:
    vector<int> next_smaller(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

     vector<int> prev_smaller(vector<int> &arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
     }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev=prev_smaller(arr);
        vector<int> suff=next_smaller(arr);
        
        long long ans=0;
        int M=1e9+7;
        for(int i=0;i<n;i++){
            int z=i-prev[i];
            int zz=suff[i]-i;
            long long sum=(long long)arr[i]*1ll*z*1ll*zz;
            ans=(ans+(sum%M))%M;
        }
        return ans;
    }
};