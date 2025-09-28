class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return abs(nums[0]-nums[1]);
        int ind=-1; long long sum=0, sum1=0,sum2=0,val=0;
        bool flag=false;
        for(auto it:nums)sum+=it;
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                flag=true; 
                ind=i+1;
                sum1+=nums[i];
                break;
            }
            if(nums[i]>nums[i+1]){ind=i; val=nums[i]; break;}
            sum1+=nums[i];
        }
        if(ind==-1){
            long long ans1=sum-nums[n-1];
            long long z= abs(ans1-nums[n-1]);
            return z;
        }
        else{

            for(int i=ind; i<n-1; i++){
                if(nums[i]==nums[i+1])return -1;
            }

        }
         sum2=sum-sum1-val;

        for(int i=ind; i<n-1; i++){
            if(flag && nums[i]==nums[i+1])return -1;
            if(nums[i]<nums[i+1]) return -1;
        }


        long long ans1=abs(sum1+val-sum2);
        long long ans2=abs(sum1-sum2-val);
        return min(ans1,ans2);

        


    }
};