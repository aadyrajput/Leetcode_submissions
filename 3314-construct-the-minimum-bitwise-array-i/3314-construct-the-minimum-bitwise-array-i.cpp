class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
            vector<int> ans;
            for(auto it:nums){
                if(it==2){ans.push_back(-1); continue;}
                bool flag=false;
                for(int i=1; i<it;i++){
                        int j=i+1;
                        int z= i|j;
                        if(z==it){flag=true; ans.push_back(i); break;}
                }
                if(!flag)ans.push_back(-1);
            }
    return ans;
    }
};