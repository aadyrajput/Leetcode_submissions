class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int n=nums.size();
     for(int i=0;i<n;i++){
        nums[i]=nums[i]%2;
     }
        int ans=0; int sum=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)ans++;
            ans+=m[sum-k];
            m[sum]++;
        }
    return ans;

    }
};