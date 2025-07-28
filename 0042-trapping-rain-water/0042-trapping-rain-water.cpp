class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> arr=height;
       int l=0;int r=n-1; int lmax=0; int rmax=0; int tot=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lmax>=arr[l]) tot+=(lmax-arr[l]);
                else lmax=arr[l];
                l++;
            }
            else{
                if(rmax>=arr[r])tot+=(rmax-arr[r]);
                else rmax=arr[r];
                r--;

            }
        }

    return tot;
    }
};