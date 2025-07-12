class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(); int ind=0;
        for(int i=0;i<n; i++){
            if(nums[i]==0){ind=i; break;}
        }
        int ind2=ind+1;
        while(ind2!=n){
            if(nums[ind2]==0) ind2++;
            else if(nums[ind]==0 && nums[ind2]!=0){
                swap(nums[ind],nums[ind2]);
                ind++; ind2++;
            }
            else ind2++;

        }

    }
};