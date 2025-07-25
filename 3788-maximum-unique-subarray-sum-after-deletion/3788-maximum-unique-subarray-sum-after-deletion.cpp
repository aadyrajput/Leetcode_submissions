class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int flag=INT_MIN;
        for(auto it:nums){
            if(it>0)s.insert(it);
            else flag=max(flag,it);
        }
        if(s.size()==0){
                return flag;
        }
        int sum=0;
        for(auto it:s)sum+=it;
        return sum;

    }
};