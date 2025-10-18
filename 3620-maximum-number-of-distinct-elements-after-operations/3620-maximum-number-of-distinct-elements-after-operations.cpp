class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0; int prev=-1e9;
        for(int i=0;i<nums.size(); i++){
            int z=max(nums[i]-k,prev+1);
            if(z<=nums[i]+k){
                prev=z; ans++;
            }
        }
return ans;
    }
};