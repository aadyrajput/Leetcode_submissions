class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     long long prod=1;
     int ans=0;
     int ptr=0;
     if(k<=1)return 0;
    for(int i=0;i<nums.size();i++){
            prod=prod*1ll*nums[i];
            while(prod>=k){
                prod=prod/nums[ptr];
                ptr++;
            }
            ans+=(i-ptr+1);
    }
    return ans;

    }
};