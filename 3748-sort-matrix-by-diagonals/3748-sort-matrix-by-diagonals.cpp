class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0; i<n; i++){
         vector<int> v;
        for(int k=0; k<n; k++){
            int ii=i+k; int jj=k;
            if(ii<n && jj<n) v.push_back(grid[ii][jj]);
            else break;
        }
        sort(v.begin(),v.end(),greater<int>()); int pp=0;
        for(int k=0; k<n; k++){
            int ii=i+k; int jj=k;
            if(ii<n && jj<n) {grid[ii][jj]=v[pp]; pp++;}
        }
        }

        for(int j=1; j<n; j++){
         vector<int> v;
        for(int k=0; k<n; k++){
            int jj=j+k; int ii=k;
            if(ii<n && jj<n) v.push_back(grid[ii][jj]);
            else break;
        }
        sort(v.begin(),v.end()); int pp=0;
        for(int k=0; k<n; k++){
            int jj=j+k; int ii=k;
            if(ii<n && jj<n) {grid[ii][jj]=v[pp]; pp++;}
            else break;
        }
        }
    return grid;
    }
};