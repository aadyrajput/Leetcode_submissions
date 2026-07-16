class Solution {
public:
    vector<vector<int>> ans;
    void fun(int i,int tar,vector<int>&arr,vector<int>&temp){
      if(tar==0){
        ans.push_back(temp);
        return;
      }
      if(i<0)return;

      if(arr[i]<=tar){
        temp.push_back(arr[i]);
        fun(i,tar-arr[i],arr,temp);
        temp.pop_back();
      }
      fun(i-1,tar,arr,temp);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         int n=candidates.size();
        vector<int> temp;
        fun(n-1,target,candidates,temp);
        return ans;
    }
};