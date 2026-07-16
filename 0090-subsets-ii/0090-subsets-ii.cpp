class Solution {
private:
void fun(int ind,vector<int> &nums, vector<vector<int>> &ans,vector<int> &ds ){
            ans.push_back(ds);

        for(int j=ind;j<nums.size();j++){
            if(j>ind && nums[j]==nums[j-1])continue;
            ds.push_back(nums[j]);
            fun(j+1,nums,ans,ds);
             ds.pop_back();
        }
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        fun(0,nums,ans,ds);
        return ans;
    }
};