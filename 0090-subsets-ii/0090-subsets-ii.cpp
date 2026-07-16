class Solution {
private:
void fun(int ind,int n,vector<int> &nums, set<vector<int>> &st,vector<int> &ds ){
        if(ind==n){
            st.insert(ds);
            if(ds.size()==0)st.insert(ds);
            return;
        }
       ds.push_back(nums[ind]);
       fun(ind+1,n,nums,st,ds);

      ds.pop_back();
      fun(ind+1,n,nums,st,ds);
}


public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n=nums.size();
         vector<int> ds;
         sort(nums.begin(),nums.end());
         set<vector<int>> st;
            fun(0,n,nums,st,ds);
        vector<vector<int>> ans;
        for(auto it:st)ans.push_back(it);
         return ans;
    }
};