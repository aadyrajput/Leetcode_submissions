class Solution {
void fun(int n,vector<int>&nums,vector<int>&v,set<vector<int>>&st,vector<int>&freq){
        if(v.size()==n){
            st.insert(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==1)continue;
            freq[i]=1;
            v.push_back(nums[i]);
            fun(n,nums,v,st,freq);
            v.pop_back();
            freq[i]=0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          int n=nums.size();
        vector<int> freq(n,0);
        vector<int> v;
        set<vector<int>> st;
        fun(n,nums,v,st,freq);

        vector<vector<int>> ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};