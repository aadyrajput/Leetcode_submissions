class Solution {
public:
    int reverse(int x){
        int ans=0;
        while(x){
            ans=ans*10;
            ans+=(x%10);
            x=x/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int z=reverse(nums[i]);
            if(m.find(z)!=m.end()){
                ans=min(ans,abs(i-m[z]));
            }
            m[nums[i]]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;       
    }
};