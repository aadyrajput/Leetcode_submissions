class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> q;
        q.push({0,{0,0}});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!q.empty()){
            int x=q.top().second.first;
            int y=q.top().second.second;
            int d=q.top().first;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int z=max(d,abs(heights[nrow][ncol]-heights[x][y]));
                    if(z<dist[nrow][ncol]){
                        dist[nrow][ncol]=z;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return dist[m-1][n-1];

    }
};