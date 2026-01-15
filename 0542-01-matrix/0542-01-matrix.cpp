class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(mat[i][j]==0){
                    ans[i][j]=0; vis[i][j]=1;
                    q.push({{i,j},0});
            }
        }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int val=it.second;
            for(int i=0;i<4; i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==1 
                          && !vis[nrow][ncol]){
                    ans[nrow][ncol]=min(ans[nrow][ncol],val+1);
                    vis[nrow][ncol]=true;
                    q.push({{nrow,ncol},ans[nrow][ncol]});
                }
            }
        }
        return ans;


    }
};