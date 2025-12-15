class Solution {
    int ct=0;
 void mergesort(int lo,int hi,vector<int>&v){
       if(lo>=hi)return;
       int mid=(lo+hi)/2;
       mergesort(lo,mid,v);
       mergesort(mid+1,hi,v);
       countPairs(lo,mid,hi,v);
       merge(lo,mid,hi,v);
   }
   void countPairs(int lo,int mid,int hi,vector<int>&v){
    int right=mid+1;
    for(int i=lo; i<=mid; i++){
        while(right<=hi && v[i]>2*1ll*v[right])right++;
        ct+=(right-mid-1);
    }
   }   
   void merge(int lo,int mid,int hi,vector<int>&v){
       int left=lo; int right=mid+1;
       vector<int> temp;
       while(left<=mid && right<=hi){
           if(v[left]<=v[right]){
               temp.push_back(v[left]);
            left++;
           }
           else{
               temp.push_back(v[right]);
              right++;
           }
       }
       while(left<=mid){
           temp.push_back(v[left]); left++;
       }
        while(right<=hi){
           temp.push_back(v[right]); right++;
       }
       for(int i=lo; i<=hi; i++){
           v[i]=temp[i-lo];
       }
   }


public:
    int reversePairs(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return ct;     
    }
};