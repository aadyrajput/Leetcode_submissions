class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ctt=0;
        for(auto it:nums)if(it==1)ctt++;
        for(int i=0;i<n;i++)nums.push_back(nums[i]);
        int ct=0;
        int ans=INT_MAX; int ptr=0;
    for(int i=0;i<nums.size(); i++){
        if(nums[i]==0)ct++;
        if(i<ctt){
            if(i==ctt-1)ans=min(ans,ct);
            continue;
        }
        if(nums[ptr]==0)ct--;
        ptr++;
        ans=min(ans,ct);
    }
    return ans;
    }
};