class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n);
        int maxa=nums[0]; pre[0]=nums[0];
        for(int i=1;i<n;i++){
            maxa=max(maxa,nums[i]);
            pre[i]=__gcd(maxa,nums[i]);
        }
    sort(pre.begin(),pre.end());
    int p1=0; int p2=n-1;
    long long sum=0;
    while(p1<p2){
        sum+=__gcd(pre[p1],pre[p2]);
        p1++; p2--;
    }
    return sum;

    }
};