class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int z1=nums1.size(), z2=nums2.size();
        if(z1%2!=0){
            for(auto it:nums2)ans=ans^it;
        }
        if(z2%2!=0){
            for(auto it:nums1)ans=ans^it;
        }
        return ans;
    }
};