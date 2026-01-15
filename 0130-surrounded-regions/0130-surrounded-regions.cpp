class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        int m=board.size(); int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0; i<m;i++){
            if(board[i][0]=='O'){q.push({i,0}); vis[i][0]=true;}
            if(board[i][n-1]=='O'){q.push({i,n-1}); vis[i][n-1]=true;}
        }
        for(int i=1; i<n-1;i++){
            if(board[0][i]=='O'){q.push({0,i}); vis[0][i]=true;}
            if(board[m-1][i]=='O'){q.push({m-1,i}); vis[m-1][i]=true;}
        }

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=x+delrow[k];
                int ncol=y+delcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' 
                     && !vis[nrow][ncol]){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }


    }
};