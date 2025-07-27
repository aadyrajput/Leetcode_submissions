class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> v;
        int last=nums[0];
        v.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==last) continue;
            v.push_back(nums[i]);
            last=nums[i];
        }
        int nn=v.size();
        int ct=0;
        for(int i=0; i<nn; i++){
            if(i+1>=nn || i+2>=nn)continue;
            if(v[i]<v[i+1] && v[i+1]>v[i+2])ct++;
            else if(v[i]>v[i+1] && v[i+1]<v[i+2])ct++;
        }
        return ct;
    }
};