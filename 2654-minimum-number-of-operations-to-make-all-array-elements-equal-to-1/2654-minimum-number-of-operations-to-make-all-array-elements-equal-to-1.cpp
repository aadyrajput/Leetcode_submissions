class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ct=0; int n=nums.size();
        int gcdd=0;
        for(auto it:nums){
            if(it==1)ct++;
            gcdd=__gcd(gcdd,it);
        }
        if(ct!=0)return n-ct;
        if(gcdd!=1)return -1;

        int z=INT_MAX;
        for(int i=0;i<n;i++){
            int gcc=nums[i];
            for(int j=i+1;j<n;j++){
                gcc=__gcd(gcc,nums[j]);
                if(gcc==1){
                    z=min(z,j-i); break;
                }
            }
        }
        return z+n-1;
    }
};