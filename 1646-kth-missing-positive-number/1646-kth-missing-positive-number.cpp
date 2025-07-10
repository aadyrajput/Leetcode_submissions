class Solution {
private:
bool check(int mid,vector<int>&arr,int k){
    int x=arr[mid]-mid-1;
    if(x<k)return true;
    return false;
}
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int x=arr[n-1]-n;
        if(k>x){
            k-=x;
            return arr[n-1]+k;
        }
        int lo=0; int hi=n-1;
        while(lo<=hi){
            int mid= lo+ (hi-lo)/2;
            if(check(mid,arr,k)) lo=mid+1;
            else hi=mid-1;
        }
        return lo+k;
    }
};