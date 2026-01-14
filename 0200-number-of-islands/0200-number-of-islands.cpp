class Solution {
private:
void fun(int i,int j,vector<vector<char>> &v,vector<vector<int>> &vis){
    int m=v.size(), n=v[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    while(!q.empty()){
      int x=q.front().first;
      int y=q.front().second;
        q.pop();
     int delrow[4]={-1,0,1,0};
     int delcol[4]={0,-1,0,1};
    for(int k=0;k<4; k++){
        int nrow=x+delrow[k];
        int ncol=y+delcol[k];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && v[nrow][ncol]=='1'){
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
        }
    }
    }
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m; i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                fun(i,j,grid,vis);
                ans++;
              }
           }
        }
    return ans;
    }
};