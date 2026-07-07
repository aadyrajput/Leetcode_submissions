class Solution {
public:
    bool fun(long long mid,int ind,long long maxSum,int n){
     int left = ind;
int right = n-ind-1;

long long lsum, rsum;

if(mid > left)
    lsum = (mid + (mid-left)) * 1LL * (left+1) / 2;
else
    lsum = mid*(mid+1LL)/2 + (left-mid+1);

if(mid > right)
    rsum = (mid + (mid-right)) * 1LL * (right+1) / 2;
else
    rsum = mid*(mid+1LL)/2 + (right-mid+1);

return lsum + rsum - mid <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        long long lo=1, hi=maxSum;
        int ans=0;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(fun(mid,index,maxSum,n)){
                ans=mid; lo=mid+1;
            }
            else hi=mid-1;
        }

    return ans;
    }
};