class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=1;j<n;j++)grid[0][j]+=grid[0][j-1];
        for(int j=1;j<m;j++)grid[j][0]+=grid[j-1][0];

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+grid[i][j];
            }
        }

        int ct=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=k)ct++;
            }
        }
        return ct;


    }
};