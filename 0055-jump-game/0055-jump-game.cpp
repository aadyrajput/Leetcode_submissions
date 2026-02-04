class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxa=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxa)return false;
            maxa=max(maxa,i+nums[i]);
        }
        return true;

    }
};