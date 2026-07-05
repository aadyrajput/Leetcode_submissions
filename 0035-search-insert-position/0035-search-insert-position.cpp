class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       vector<int> arr=nums;
       int n=arr.size();
        int lo=0, hi=n-1;
        int ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=target){
                hi=mid-1; ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;   
    }
};