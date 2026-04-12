class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans(n,0);
        for(auto it:matrix){
            vector<int> v=it;
            for(int i=0; i<v.size();i++){
                ans[i]+=v[i];
            }
        }
        return ans;
    }
};