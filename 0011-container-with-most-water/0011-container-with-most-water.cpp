class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> arr=height;
        int n=arr.size();
        int p1=0; int p2=n-1;
        int ans=0;
        while(p1<p2){
            int x=(p2-p1)*1ll*min(arr[p1],arr[p2]);
            ans=max(ans,x);
            if(arr[p1]<arr[p2])p1++;
            else p2--;
        }
        return ans;
    }
};