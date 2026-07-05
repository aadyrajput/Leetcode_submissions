class Solution {
public:
    const int M=1e9+7;
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(auto it:nums){
            int z=it;
            for(int j=2;j*j<=z;j++){
                if(z%j==0){
                  st.insert(j);
                  while(z%j==0){ 
                    z=z/j;
                  }
                }
            }
            if(z>1)st.insert(z);
        }
        if(st.empty())st.insert(2);

        long long maxSum=-1e9; int k=2;

        for(auto it:st){
            vector<int> temp(n,0);
            for(int i=0; i<n;i++){
                if(nums[i]%it==0)temp[i]=nums[i];
                else temp[i]= -nums[i];
            }
            long long maxa=-1e9, sum=0;
            for(int j=0;j<n;j++){
                sum+=temp[j];
                maxa=max(maxa,sum);
                if(sum<0) sum=0;
            }
            if(maxa>maxSum){
                maxSum=maxa;
                k=it;
            }
        }
        //return maxSum;

        long long res=(((maxSum%M)+M)*1ll*k)%M;
    return res;
    }
};