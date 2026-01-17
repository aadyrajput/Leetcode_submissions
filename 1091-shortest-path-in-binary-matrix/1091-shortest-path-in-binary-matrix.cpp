class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==0 && j==0)continue;
                    int nrow=x+i, ncol=y+j;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 
                         && dist[nrow][ncol]>dist[x][y]+1 ){
                            dist[nrow][ncol]=dist[x][y]+1;
                            q.push({nrow,ncol});
                         }
                }
            }
        }

        if(dist[n-1][n-1]==1e9)return -1;
        return dist[n-1][n-1];
    }
};