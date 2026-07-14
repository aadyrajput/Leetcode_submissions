class Solution {
public:
    const int M=1e9+7;
    long fun(int i,int gcd1,int gcd2,vector<int>&nums,vector<vector<vector<long long>>>&dp){
        if(i<0){
            if(gcd1==0 && gcd2==0)return 0;
            if(gcd1==gcd2)return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];

         long long z=((fun(i-1,gcd1,gcd2,nums,dp)%M)
                    +(fun(i-1,__gcd(gcd1,nums[i]),gcd2,nums,dp)%M)
                    +(fun(i-1,gcd1,__gcd(gcd2,nums[i]),nums,dp)%M)
                    )%M;
    return dp[i][gcd1][gcd2]=z;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxa=-1;
        for(auto it:nums)maxa=max(maxa,it);
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(maxa+1,vector<long long>(maxa+1,-1)));
        int gcd1=0, gcd2=0;
        return fun(n-1,gcd1,gcd2,nums,dp);
    }
};