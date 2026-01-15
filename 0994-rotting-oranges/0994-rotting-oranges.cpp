class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size(); 
        int n=grid[0].size();
        int ct=0;
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==2)q.push({{i,j},0});
                if(grid[i][j]==1)ct++;
            }
        } 
        if(q.empty()){
            if(ct==0)return 0;
            return -1;
        }
        int time=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int t=it.second;
            time=max(time,t);
            int x=it.first.first;
            int y=it.first.second;
            for(int i=0;i<4; i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1}); grid[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};