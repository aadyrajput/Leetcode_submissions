class Solution {
public:
    const int M=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size(); i++){
            sum=(sum+nums[i]);
        }
        
        long long zz=sum/k;
        if(sum%k!=0)zz++;

        zz--;

        long long a=zz;
        long long b=zz+1;

        if(a%2==0)a/=2;
        else b/=2;

    long long ans=(a%M)*(b%M)%M;
    return ans;
    }
};