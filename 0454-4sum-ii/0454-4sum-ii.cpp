class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ct=0;
        map<int,int> m1,m2;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                    m1[nums1[i]+nums2[j]]++;
            }
        }
          for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                    m2[nums3[i]+nums4[j]]++;
            }
        }

        for(auto it:m1){
            if(m2.count(-it.first)==0)continue;
            ct+=(m2[-it.first]*it.second);
        }
    return ct;
    }
};