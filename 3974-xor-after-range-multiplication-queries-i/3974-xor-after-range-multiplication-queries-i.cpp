class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int ans=0; int M=1e9+7;
     for(auto it:queries){
        int l=it[0]; int r=it[1]; int k=it[2]; int v=it[3];
        while(l<=r){
            nums[l]=(nums[l]*1ll*v)%M;
            l+=k; 
        }
     }
     for(auto it:nums)ans=ans^it;
    return ans;
    }
};