class Solution {
public:
    set<vector<int>> ans;
    void fun(int i,int tar,vector<int>&arr,vector<int>&temp){
      if(tar==0){
        ans.insert(temp);
        return;
      }
      if(i==arr.size())return;

      for(int j=i; j<arr.size();j++){
         if(j>i && arr[j]==arr[j-1]) continue;
         if(arr[j]>tar)continue;
         temp.push_back(arr[j]);
         fun(j+1,tar-arr[j],arr,temp);
         temp.pop_back();
      }
  }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         int n=candidates.size();
        vector<int> temp;
        fun(0,target,candidates,temp);

        vector<vector<int>> res;
        for(auto it:ans)res.push_back(it);
        return res;
    }
};