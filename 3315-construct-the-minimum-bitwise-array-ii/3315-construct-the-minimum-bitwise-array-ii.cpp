class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         int n=nums.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            int z=nums[i];
            if(z==2){ans[i]=-1; continue;}
            int ct=0;
            for(int j=0;j<31;j++){
                if(z&(1<<j)) ct++;
                else break;
            }
            int zz=1<<(ct-1);
            if((z&(z+1))==0)ans[i]=zz-1;
           else ans[i]=z-zz;
        }

        return ans;
    }
};