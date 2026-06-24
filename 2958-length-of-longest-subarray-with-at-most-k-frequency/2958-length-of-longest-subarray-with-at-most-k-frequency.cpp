class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int ptr=0; 
        map<int,int> m;
    for(int i=0;i<n;i++){
        m[nums[i]]++;
        while(m[nums[i]]>k){
            m[nums[ptr]]--;
            ptr++;
        }
        ans=max(ans,i-ptr+1);
    }
    return ans;
    }
};