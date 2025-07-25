class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int ans=-1;
      int lo=0; int hi=n-1;
      while(lo<=hi){
        int mid= lo+ (hi-lo)/2;
        if(nums[mid]==target)return mid;
        //left is sorted
        if(nums[lo]<=nums[mid]){
            if(nums[lo]<=target && target<=nums[mid]){
                hi=mid-1;
            }
            else lo=mid+1;
          }
        //else right is sorted
        else{
            if(nums[mid]<=target && target<=nums[hi]){
                lo=mid+1;
            }
            else hi=mid-1;
        }
      }
    return ans;
    }
};