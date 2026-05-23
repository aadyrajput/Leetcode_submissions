class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st;
      long long int sum=0;
        for(int i=0;i<nums.size(); i++){
            bool flag=true;
            for(auto itt:st){
                if(nums[i]%itt==0){flag=false; nums[i]=itt; break;}
            }
            if(flag)st.insert(nums[i]);
            sum+=nums[i];
        }
        return sum;

    }
};