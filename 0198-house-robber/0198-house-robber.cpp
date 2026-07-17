class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        int prev2=0;
        int prev=nums[0];
        int curr;

        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>=2)take+=prev2;
            int nottake=prev;

            curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
    return prev;
    }
};