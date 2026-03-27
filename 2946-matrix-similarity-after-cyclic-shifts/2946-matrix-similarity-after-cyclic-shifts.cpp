class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        k=k%n;
        vector<vector<int>> mat2;
        for(int i=0;i<m;i++){
            vector<int> v;
            if(i%2==0){
            for(int j=k; j<n; j++)v.push_back(mat[i][j]);
            for(int j=0;j<k; j++)v.push_back(mat[i][j]);
            }
            else{
            for(int j=n-k; j<n; j++)v.push_back(mat[i][j]);
            for(int j=0;j<n-k; j++)v.push_back(mat[i][j]);
            }
            mat2.push_back(v);
        }
        if(mat==mat2)return true;
        return false;
    }
};