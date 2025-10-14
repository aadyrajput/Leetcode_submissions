class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        int ct=1;
        if(nums.size()==2)return true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1])ct++;
            else{
                v.push_back(ct);
                ct=1;
            }
        }
       if(ct!=1)v.push_back(ct);
        int maxa=-1;
        for(int i=0;i<v.size(); i++){
            if(v[i]>=k*2) return true;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]>k)v[i]=k;
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==k && v[i+1]==k)return true;
        }
        return false;



    }
};