class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long totsum=0;
        for(auto it:nums)totsum+=it;
        long long first=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])first+=nums[i];
        }
        long long maxa=0;
        for(auto it:nums)if(it>maxa)maxa=it;
        long long last=totsum-maxa-first;
        if(first>last)return 0;
        else if(first<last)return 1;
        return -1;
    }
};