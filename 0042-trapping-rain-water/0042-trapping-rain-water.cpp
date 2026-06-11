class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n), suff(n);
        pre[0]=height[0], suff[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
         for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],height[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int z=min(pre[i-1],suff[i+1]);
            if(z<=height[i])continue;
            ans+=(z-height[i]);
        }

    return ans;
    }
};