class Solution {
public:
    bool fun(int mid,vector<int>&v,int k){
        int z=v[mid]-mid-1;
        if(z>=k)return true;
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int z=arr[n-1]-n;
        if(k>z){
            return arr[n-1]+k-z;
        }

        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,arr,k)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }   
        }
        return lo+k;
    }
};