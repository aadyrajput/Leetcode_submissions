class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int M=1e9+7;
        for(auto it:queries){
            int l=it[0], r=it[1], k=it[2], v=it[3];
            while(l<=r){
                nums[l]=(nums[l]*1ll*v)%M;
                l+=k;
            }
        }
        int xorr=0;
        for(auto it:nums){
            xorr=xorr^it;
        }
        return xorr;


    }
};