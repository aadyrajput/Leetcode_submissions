class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
       int M=1e9+7;
        int m=grid.size();
        int n=grid[0].size();
vector<vector<long long>> dpmax(m,vector<long long>(n,0)),dpmin(m,vector<long long>(n,0));
    dpmax[0][0]=dpmin[0][0]=grid[0][0];
    for(int i=1;i<m; i++){
        dpmax[i][0]=(dpmax[i-1][0]*1ll*grid[i][0])%M;
        dpmin[i][0]=(dpmin[i-1][0]*1ll*grid[i][0])%M;
    }
    for(int i=1;i<n; i++){
        dpmax[0][i]=(dpmax[0][i-1]*1ll*grid[0][i])%M;
        dpmin[0][i]=(dpmin[0][i-1]*1ll*grid[0][i])%M;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            long long a=dpmin[i-1][j]*grid[i][j];
            long long b=dpmax[i-1][j]*grid[i][j];
            long long c=dpmin[i][j-1]*grid[i][j];
            long long d=dpmax[i][j-1]*grid[i][j];
            dpmin[i][j]=min({a,b,c,d});
            dpmax[i][j]=max({a,b,c,d});
        }
    }
    if(dpmax[m-1][n-1]<0)return -1;
    return dpmax[m-1][n-1]%M;

        

    }
};