class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int sum=0; int ans=0; int left=0;
        for(int i=0;i<nums.size(); i++){
            while(s.find(nums[i])!=s.end()){
                sum-=nums[left];
                s.erase(nums[left]);
                left++;
            }
            sum+=nums[i];
            ans=max(ans,sum);
            s.insert(nums[i]);
        }
        

        return ans;
    }
};