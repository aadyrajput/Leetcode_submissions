class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int m=order.size(); int n=s.size();
        set<int> st;
        st.insert(-1); st.insert(n);
        for(int i=0;i<m; i++){
           int ind=order[i];
           auto it=st.lower_bound(ind);
           int r=*it; int l=*(--it);
           k-=(long long)(ind-l)*(r-ind);
           st.insert(ind);
           if(k<=0)return i;
        }
    return -1;
    }
};