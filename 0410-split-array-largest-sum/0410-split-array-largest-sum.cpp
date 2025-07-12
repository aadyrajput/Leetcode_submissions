class Solution {
private:
    int solve(int mid,vector<int>&arr,int k){
       int student=0;
       int ans=0;
       for(int i=0;i<arr.size();i++){
           if(ans+arr[i]<=mid){
               ans+=arr[i];
           }
           else{
               student++;
               ans=arr[i];
           }
       }
        if(student>=k) return true;
        return false;
        
    }
public:
    int splitArray(vector<int>& nums, int k) {
       int n=nums.size();
        int sum=0; for(auto it:nums)sum+=it;
        if(k>n){return -1;}
        int lo=*max_element(nums.begin(),nums.end());
        int hi=sum;
        while(lo<=hi){
            int mid=lo+ (hi-lo)/2;
            if(solve(mid,nums,k)){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
         
    }
};