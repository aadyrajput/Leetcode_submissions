class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)return true;
        int ct=3;
        int m=mat.size(); int n=mat[0].size();
        while(ct--){
            for(int i=0;i<m; i++){
                for(int j=i+1; j<n; j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
          for(int i=0;i<m; i++){
            reverse(mat[i].begin(),mat[i].end());
          }
        if(mat==target)return true;
        }
        return false;
    }
};