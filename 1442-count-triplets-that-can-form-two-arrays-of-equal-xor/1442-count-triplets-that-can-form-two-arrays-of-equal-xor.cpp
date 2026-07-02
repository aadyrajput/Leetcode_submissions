class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
                int xorr1=0;
            for(int j=i+1;j<n;j++){
                xorr1=xorr1^arr[j-1];
                int xorr2=arr[j];
                if(xorr1==xorr2)ans++;
                for(int k=j+1; k<n;k++){
                    xorr2=xorr2^arr[k];
                    if(xorr1==xorr2) ans++;
                }
            }
        }
    return ans;
    }
};