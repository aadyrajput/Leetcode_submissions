class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a,b; bool flag=false; int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                i++; continue;
            }
            else{
                if(!flag){a=nums[i]; flag=true;}
                else{b=nums[i];}
            }
        }
        if(nums[n-1]!=nums[n-2])b=nums[n-1];
        return {a,b};
    }
};