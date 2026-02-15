class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> m,mm;
        for(auto it:nums)m[it]++;
        for(auto it:m)mm[it.second]++;
        for(int i=0;i<nums.size();i++){
            int z=m[nums[i]];
            if(mm[z]==1)return nums[i];
        }
    return -1;
    }
};