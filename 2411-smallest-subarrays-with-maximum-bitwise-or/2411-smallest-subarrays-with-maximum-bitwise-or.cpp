class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int orr=0; int ptr=n-1;

        vector<int> bits(31,0);

        int res=0;
        for(int i=n-1;i>=0;i--){        
            orr=orr|nums[i]; res++;
            for(int j=0;j<31;j++){
                if(nums[i]&(1<<j)) bits[j]++;
            }
            int neworr=orr; vector<int> temp=bits;
            while(neworr==orr && ptr>i){
                for(int j=0;j<31;j++){
                if(nums[ptr]&(1<<j)) temp[j]--;
            }
            neworr=0;
            for(int j=0;j<31;j++){
                if(temp[j]>0)neworr=neworr|(1<<j);
            }
            if(neworr==orr){ptr--; res--; bits=temp;}
            }
          ans[i]=res;
        }
    return ans;
    }
};