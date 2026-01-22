class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        if(is_sorted(nums.begin(),nums.end()))return 0;
        int ans=0;
        vector<int> v=nums;
        while(!is_sorted(v.begin(),v.end())){
            int minsum=1e9;
            ans++;
            int ind=-1;
            for(int i=0;i<v.size()-1; i++){
                int z=v[i]+v[i+1];
                if(z<minsum){
                    minsum=z; ind=i;
                }
            }
            v[ind]=minsum;
            v.erase(v.begin()+ind+1);
        }
    return ans;
    }
};