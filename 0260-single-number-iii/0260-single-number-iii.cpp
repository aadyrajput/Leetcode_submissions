class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        for(auto it:nums)xorr=xorr^it;
        int bit=0;
        for(int i=0;i<=32; i++){
            if(xorr&(1LL<<i)){
                bit=i; break;
            }
        }

        int num1=0, num2=0;
        for(auto it:nums){
            if(it&(1<<bit))num1=num1^it;
            else num2=num2^it;
        }

        return {num1,num2};
    }
};