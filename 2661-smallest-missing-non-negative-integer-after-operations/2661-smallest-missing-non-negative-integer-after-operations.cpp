class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        for(int i=0;i<nums.size(); i++){
            if(nums[i]>=0){nums[i]=nums[i]%value; continue;}
            int z=abs(nums[i]/value); z++;
            nums[i]+=(z*value);
            nums[i]=nums[i]%value;
        }
        vector<int> has(value,0);
        for(auto it:nums){
            has[it]++;
        }
        int mina=INT_MAX; int minvalue=0; ;
        for(int i=0; i<has.size(); i++){
            if(has[i]==0)return i;
            if(has[i]<mina){
                mina=has[i]; minvalue=i;
            }
        }
    
        int ans=value*mina;
        return ans+minvalue;
        
        
        

    }
};