class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1,v2;
        for(int i=0;i<n;i++){
            if(nums[i]==1)v1.push_back(i);
            else if(nums[i]==2)v2.push_back(i);
        }
        if(v1.size()==0 || v2.size()==0)return -1;
        int ans=1e9;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            ans=min(ans,abs(v1[i]-v2[j]));
        }
    }

    return ans;
    }
};