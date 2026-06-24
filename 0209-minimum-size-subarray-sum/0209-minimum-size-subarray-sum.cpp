class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=INT_MAX;
        int ptr=0; int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                len=min(len,i-ptr+1);
                sum-=nums[ptr];
                ptr++;
            }
        }
        if(len==INT_MAX)return 0;
    return len;
    }
};