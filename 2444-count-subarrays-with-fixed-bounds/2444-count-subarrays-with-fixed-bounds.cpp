class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n=nums.size();
    int mina=-1, maxa=-1; int ptr=-1;
    long long ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]>maxK || nums[i]<minK){
            ptr=i; mina=-1, maxa=-1;
            continue;
        }
        if(nums[i]==minK)mina=i;
        if(nums[i]==maxK)maxa=i;
        if(mina!=-1 && maxa!=-1) ans+=(min(maxa,mina)-ptr); 
    }

    return ans;
        
    }
};