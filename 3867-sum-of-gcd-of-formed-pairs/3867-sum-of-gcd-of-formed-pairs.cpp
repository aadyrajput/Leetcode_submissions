class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        int maxa=nums[0];
        for(int i=1;i<n; i++){
            maxa=max(maxa,nums[i]);
            pre[i]=__gcd(maxa,nums[i]);
        }
        long long sum=0;
        sort(pre.begin(),pre.end());
        for(int i=0;i<n/2; i++){
            int gcd=__gcd(pre[i],pre[n-1-i]);
            sum+=gcd;
        }
        return sum;

    }
};