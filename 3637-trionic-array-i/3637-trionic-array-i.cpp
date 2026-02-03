class Solution {
public:
    bool isTrionic(vector<int>& nums) {
     int n=nums.size();
     if(n==3)return false;
     int ind=0;
     int ct=0;
     while(ind<n-1 && nums[ind]<nums[ind+1]){
        ind++;ct++;
     }
     if(ind==n || ct==0)return false;
     ct=0;
     while(ind<n-1 && nums[ind]>nums[ind+1]){
        ind++; ct++;
     }
     if(ind==n || ct==0)return false;
     ct=0;
     while(ind<n-1 && nums[ind]<nums[ind+1]){
        ind++;ct++;
     }
     if(ct==0) return false;
     if(ind==n-1)return true;
     return false;


    }
};