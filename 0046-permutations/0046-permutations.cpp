class Solution {
public:
void fun(int n,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans,vector<int>&freq){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==1)continue;
            freq[i]=1;
            v.push_back(nums[i]);
            fun(n,nums,v,ans,freq);
            v.pop_back();
            freq[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n,0);
        vector<int> v;
        vector<vector<int>> ans;
        fun(n,nums,v,ans,freq);
        return ans;
    }
};