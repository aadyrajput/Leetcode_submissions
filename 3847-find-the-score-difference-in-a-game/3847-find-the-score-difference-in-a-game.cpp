class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans1=0, ans2=0;
        int act=1;
        for(int i=0; i<nums.size();i++){
            if(i%6==5)act=1-act;
            if(nums[i]%2!=0)act=1-act;
            if(act==1)ans1+=nums[i];
            else ans2+=nums[i];
        }

        return ans1-ans2;
    }
};