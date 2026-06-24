class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    int maxa=0; int n=nums.size();
    for(auto it:nums)maxa=max(maxa,it);
    long long ct=0, ptr=0, ans=0;
    for(int i=0;i<n; i++){
        if(nums[i]==maxa)ct++;
        while(ct>=k){
          if(nums[ptr]==maxa)ct--; 
          ptr++; 
          ans+=(n-i);
        }
    }

    return ans;
    }
};