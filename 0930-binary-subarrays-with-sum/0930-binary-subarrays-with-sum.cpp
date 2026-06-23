class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0; int sum=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==goal)ans++;
            ans+=m[sum-goal];
            m[sum]++;
        }
    return ans;
    }
};