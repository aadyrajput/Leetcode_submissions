class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool fun(int mid,int row,int col,vector<vector<int>>&cells){
     vector<vector<int>> cango(row,vector<int> (col,0));
     for(int i=0;i<mid;i++){
        cango[cells[i][0]-1][cells[i][1]-1]=1;
     }
    queue<pair<int,int>> q;
    for(int i=0;i<col; i++){
        if(cango[0][i]==0){q.push({0,i}); cango[0][i]=1;} 
    }

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==row-1)return true;
        for(int k=0;k<4;k++){
            int nx=x+dr[k];
            int ny=y+dc[k];
            if(nx>=0 && nx<row && ny>=0 && ny<col && cango[nx][ny]==0){
                cango[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
         int n=cells.size();
         int lo=1, hi=n;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,row,col,cells)){
                ans=mid; lo=mid+1;
            }
            else hi=mid-1;
        }
    return ans;
    }
};