class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int lo=1; int hi=n-2;
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            if(arr[mid]<arr[mid-1]) hi=mid-1;
            else lo=mid+1;
        }
    return -1;
    }
};