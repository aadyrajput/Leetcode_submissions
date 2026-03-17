class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
         int n=nums.size();
         vector<int>left(n),right(n);
         left[0]=1;right[n-1]=1;left[1]=2;right[n-2]=2;
         int ans=3;
         for(int i=2;i<n;i++){
               if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                   left[i]=left[i-1]+1;
               }
               else left[i]=2;
          }
          for(int i=n-3;i>=0;i--){
              if(nums[i]-nums[i+1]==nums[i+1]-nums[i+2]){
                  right[i]=right[i+1]+1;
              }
              else right[i]=2;
          }
         for(int i=1;i<n-1;i++){
             if(i>1){
                 int diff=nums[i-2]-nums[i-1];
                 int val=nums[i-1]-diff;
                 int len=left[i-1]+1;
                 if(i+1<n && val-nums[i+1]==diff){
                     len++;
                     if(i+2<n && nums[i+1]-nums[i+2]==diff)len+=right[i+1]-1;
                 }
                 ans=max(ans,len);
             }   
             if(i<n-2){
                 int diff=nums[i+1]-nums[i+2];
                 int val=nums[i+1]+diff;
                 int len=right[i+1]+1;
                 if(i-1>=0 &&nums[i-1]-val==diff){
                     len++;
                     if(i-2>=0 && nums[i-2]-nums[i-1]==diff){
                         len+=left[i-1]-1;
                     }
                 }
                 ans=max(ans,len);
             }
         }
         ans=max(ans,right[1]+1);
         ans=max(ans,left[n-2]+1);
        return ans;
    }
};