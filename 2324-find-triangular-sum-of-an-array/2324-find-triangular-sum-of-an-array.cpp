class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        while(nums.size()!=1){
            vector<int> v;
            for(int i=0; i<nums.size()-1; i++){
                v.push_back((nums[i+1]+nums[i])%10);
            }
            nums=v;
        }
        return nums[0];

    }
};