class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums)m[it]++;

        for(auto it:nums){
            if(it%2==0 && m[it]==1)return it;
        }
    return -1;
    }
};