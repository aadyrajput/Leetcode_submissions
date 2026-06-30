class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v(n);
        v[n-1]=nums[n-1]+k; int ans=1; 
        for(int i=n-2; i>=0; i--){
            int maxa=nums[i]+k; int mina=nums[i]-k;
            int z=v[i+1]-1;
            if(maxa<z){v[i]=maxa; ans++;}
            else if(z<mina){v[i]=mina;}
            else {v[i]=z; ans++;}
            } 
    return ans;

    }
};