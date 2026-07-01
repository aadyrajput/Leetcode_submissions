class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a; int n=nums.size();
        bool flag=false;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2;i++){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                i+=2;
            }
            else{
                a=nums[i]; flag=true; break;
            }
        }
        if(flag==false)a=nums[n-1];
    return a;
    }
};