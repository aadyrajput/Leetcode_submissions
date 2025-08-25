class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(); int n=mat[0].size();
        vector<vector<int>> v(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<v.size(); i++){
            vector<int> temp=v[i];
            if(i%2==0)reverse(temp.begin(),temp.end());
            for(auto it:temp)ans.push_back(it);
        }
    return ans;
    }
};