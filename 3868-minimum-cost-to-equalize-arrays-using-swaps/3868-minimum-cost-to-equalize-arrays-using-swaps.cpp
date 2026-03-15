class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m,m1;
        for(auto it:nums1)m[it]++;
        for(auto it:nums2)m[it]++;
        for(auto it:m)if(it.second&1)return -1;

        int ans=0;
        for(auto it:nums1)m1[it]++;

        for(auto it:m){
            int totct=it.second;
            if(m1.find(it.first)==m1.end()) {ans+=(totct/2); continue;}
            int ct1=m1[it.first];
            if(totct==ct1){ans+=(totct/2); continue;}
            totct/=2;
            int z=abs(ct1-totct);
            if(ct1==totct)continue;
            ans+=z;
        }
        return ans/2;

    }
};