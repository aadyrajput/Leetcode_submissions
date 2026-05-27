class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int mina=INT_MAX;
        for(auto it:nums)mina=min(mina,it);
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==mina){
                ind=i; break;
            }
        }
        vector<int> v;
        for(int i=ind; i<n;i++)v.push_back(nums[i]);
        for(int i=0; i<ind;i++)v.push_back(nums[i]);
        bool flag=false;
        if(is_sorted(v.begin(),v.end()))flag=true;
        for(int i=1;i<=n/2;i++){
            swap(v[i],v[n-i]);
        }
        if(is_sorted(v.begin(),v.end()))flag=true;
        
        if(flag==false)return -1;
        if(is_sorted(nums.begin(),nums.end()))return 0;
        if(ind==0){
            return 2;
        }
        if(ind==n-1){
            if(nums[0]==n-1)return 1;
            if(ind>=3)return 3;
            else return ind;
        }
        if(nums[ind-1]>nums[ind+1]){
            int z=min(ind,n-ind+2);
            return z;
        }
        int z=min(n-ind,ind+2);
        return z;

    }
};