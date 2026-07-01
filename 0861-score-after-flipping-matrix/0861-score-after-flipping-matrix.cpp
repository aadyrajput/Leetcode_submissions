class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)continue;
            for(int j=0;j<n; j++)grid[i][j]=1^grid[i][j];
        }
        long long ans=0;
        for(int j=0;j<n;j++){
            int ct=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)ct++;
            }
            ct=max(ct,m-ct);
            ans+=(ct*(1<<(n-1-j)));
        }

    return ans;

    }
};