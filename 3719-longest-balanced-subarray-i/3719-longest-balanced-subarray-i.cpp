class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n; i++){
            int z=0;
            set<int> cto,cte;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)cte.insert(nums[j]);
                else cto.insert(nums[j]);
                if(cto.size()==cte.size())z=(j-i+1);
            }
            ans=max(ans,z);
        }


        return ans;

    }
};