class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int orr=0; int n=nums.size();
        for(auto it:nums)orr=orr|it;
        if(orr<k)return -1;

        vector<int> v(31,0);
        int ans=n;
        int ptr=0; orr=0;

        for(int i=0;i<n;i++){
            orr=orr|nums[i];
            for(int j=0;j<31;j++){
                if((1<<j)&nums[i])v[j]++;
            }
            if(orr<k)continue;
        while(orr>=k && ptr<=i){
                ans=min(ans,i-ptr+1);
            for(int j=0;j<31;j++){
                    if((nums[ptr]>>j)&1)
                    v[j]--;
            }
            int neworr=0;
            for(int j=0;j<31;j++){
                if(v[j]>0)neworr |= (1<<j);
            }
            orr=neworr;
            ptr++;
        }
    }
    return ans;
    }
};