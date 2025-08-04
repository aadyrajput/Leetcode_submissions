class Solution {
private:
int fun(vector<int>&nums,int goal){         // number of subaray with sum les than or equal to goal;
 int ans=0;
 int sum=0; int left=0;
 for(int i=0;i<nums.size(); i++){
    if(goal<0)return 0;
    sum+=nums[i];
    while(sum>goal){
        sum-=nums[left];
        left++;
    }
    ans+=(i-left+1);
 }
return ans;
}
public:
    int numberOfSubarrays(vector<int>& nums, int k){

     for(int i=0;i<nums.size(); i++){
        if(nums[i]%2==0) nums[i]=0;
        else nums[i]=1;
     }
     return fun(nums,k)-fun(nums,k-1);

    }
};