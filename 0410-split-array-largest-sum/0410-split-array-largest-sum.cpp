class Solution {
public:
    bool fun(long long mid,vector<int>&arr,int k){
       int ct=1;
       long long sum=0;
       for(int i=0;i<arr.size();i++){
           if(sum+arr[i]<=mid){
               sum+=arr[i];
           }
           else{
               sum=arr[i]; 
               ct++;
           }
       }
       if(ct<=k)return true;
       return false;
    }

    int splitArray(vector<int>& nums, int k) {
        vector<int> arr=nums;
         int n=arr.size();
        long long sum=0; int maxa=INT_MIN;
        for(auto it:arr){sum+=it; maxa=max(maxa,it);}
        
        long long lo=maxa, hi=sum;
        long long ans=0;
        
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(fun(mid,arr,k)){
                ans=mid; hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};