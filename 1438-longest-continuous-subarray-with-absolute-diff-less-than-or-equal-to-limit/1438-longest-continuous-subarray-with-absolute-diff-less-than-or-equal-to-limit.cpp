class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ptr=0; int ans=INT_MIN;
        multiset<int> m;
        for(int i=0;i<n;i++){
            m.insert(nums[i]);
            int maxa=*(--m.end()), mina=*m.begin();
            while(maxa-mina>limit){
                m.erase(m.find(nums[ptr]));
                maxa=*(--m.end()), mina=*m.begin();
                ptr++;
            }
            ans=max(ans,i-ptr+1);
        }
        return ans;

    }
};