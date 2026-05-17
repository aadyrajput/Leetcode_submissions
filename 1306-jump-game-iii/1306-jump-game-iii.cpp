class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
     int n=arr.size();
     if(arr[start]==0)return true;
     set<int> st;

     queue<int> q;
     q.push(start);
     while(!q.empty()){
        int ind=q.front();
        q.pop();
        if(arr[ind]==0)return true;
        if(st.find(ind)!=st.end())continue;
        st.insert(ind);
        int l=ind-arr[ind], r=ind+arr[ind];
        if(l>=0 && l<n)q.push(l);
        if(r>=0 && r<n)q.push(r);
     }
     return false;

    }
};