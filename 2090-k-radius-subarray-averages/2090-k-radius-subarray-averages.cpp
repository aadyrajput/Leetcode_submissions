class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        int z=k*2+1;
        if(n<z){
            for(int i=0;i<n;i++)ans.push_back(-1);
            return ans;
        }
        for(int i=0;i<k;i++)ans.push_back(-1);

        int ptr=0; long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i<z){
                if(i==z-1){
                    ans.push_back(sum/z);
                }continue;
            }
            sum-=nums[ptr]; ptr++;
            ans.push_back(sum/z);
        } 
    
        for(int i=0;i<k;i++)ans.push_back(-1);
        return ans;
    }
};