class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(auto it:nums){
            if(it%k==0)st.insert(it/k);
        }
        int ct=1;
        for(auto it:st){
            if(it!=ct)return ct*k;
            else ct++;
        }
        return ct*k;

    }
};