class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ct=0; int diff;

        for(int i=0;i<n-1;i++){
            diff=nums[i+1]-nums[i];
            for(int j=i+2; j<n;j++){
                if(nums[j]-nums[j-1]==diff) ct++;
                else break;
            }
        }

    return ct;
    }
};