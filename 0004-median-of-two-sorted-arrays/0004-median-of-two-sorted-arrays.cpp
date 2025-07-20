class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m=nums1.size();
        int n=nums2.size();
        if(m==0 && n==0) return 0;
        if(n==0){
            if(m%2!=0) return nums1[m/2];
            int x=m/2;
            double ans=nums1[x-1]+nums1[x];
            ans=ans/2;
            return ans;
        }
        if(m==0){
                if(n%2!=0) return nums2[n/2];
            int x=n/2;
            double ans=nums2[x-1]+nums2[x];
            ans=ans/2;
            return ans;
        }
        int p1=0; int p2=0; int ct=(m+n)/2;
        if((m+n)%2==0) ct++;
        else ct+=2;
        int ctt=0; int ans1=0; int ans2=0;

        while(ctt<ct){
            ctt++;
            if(p1<m && p2<n){
                if(nums1[p1]<nums2[p2]){
                   if(ctt==ct-1) ans1=nums1[p1]; 
                   if(ctt==ct) ans2=nums1[p1];
                   p1++;
                }   
                else{
                    if(ctt==ct-1) ans1=nums2[p2]; 
                   if(ctt==ct) ans2=nums2[p2];
                   p2++;
                }                 
            }
        else{
            if(p1<m){
                if(ctt==ct-1) ans1=nums1[p1]; 
                   if(ctt==ct) ans2=nums1[p1];
                   p1++;
            }
            else{
                  if(ctt==ct-1) ans1=nums2[p2]; 
                   if(ctt==ct) ans2=nums2[p2];
                   p2++;
            }

        }
                
               
                
        }
        if((m+n)%2!=0){
            return ans1;
        }
        else{
            double ans=ans1+ans2;
            ans=ans/2;
            return ans;
        }
          
    }
};