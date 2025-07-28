class Solution {
private:
int fun(int ind,vector<int>&nums,int orr,int maxorr){
  if(ind==nums.size()){
    if(orr==maxorr)return 1;
    return 0;
  }
  if(orr==maxorr){
    int remain=nums.size()-ind;
    return 1<<remain;
  }
    int take=fun(ind+1,nums,orr|nums[ind],maxorr);
    int nottake=fun(ind+1,nums,orr,maxorr);
    return take+nottake;
}
public:
    int countMaxOrSubsets(vector<int>& nums) {
      int ans=0;
      for(int i=0;i<nums.size();i++)ans=(ans|nums[i]);
    return fun(0,nums,0,ans);

    }
};