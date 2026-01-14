class Solution {
private:
void fun(int i,int j,vector<vector<char>> &v,vector<vector<int>> &vis){
    int m=v.size(), n=v[0].size();
    if(i<0 || j<0 || i>=m || j>=n || v[i][j]=='0' || vis[i][j])return;
    vis[i][j]=1;
    fun(i-1,j,v,vis);
    fun(i,j-1,v,vis);
    fun(i+1,j,v,vis);
    fun(i,j+1,v,vis);
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