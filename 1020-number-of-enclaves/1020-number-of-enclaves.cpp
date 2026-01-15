class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
          queue<pair<int,int>> q;
          vector<vector<int>> board=grid;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        int m=board.size(); int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0; i<m;i++){
            if(board[i][0]==1){q.push({i,0}); vis[i][0]=true;}
            if(board[i][n-1]==1){q.push({i,n-1}); vis[i][n-1]=true;}
        }
        for(int i=1; i<n-1;i++){
            if(board[0][i]==1){q.push({0,i}); vis[0][i]=true;}
            if(board[m-1][i]==1){q.push({m-1,i}); vis[m-1][i]=true;}
        }

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=x+delrow[k];
                int ncol=y+delcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==1 
                     && !vis[nrow][ncol]){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(board[i][j]==1 && !vis[i][j])ans++;
            }
        }
return ans;

    }
};