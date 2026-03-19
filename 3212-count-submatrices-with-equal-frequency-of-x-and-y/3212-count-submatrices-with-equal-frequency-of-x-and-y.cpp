class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,bool>>> has(m,vector<pair<int,bool>>(n,{0,false}));
        if(grid[0][0]=='X')has[0][0]={1,true};
        else if(grid[0][0]=='Y')has[0][0]={-1,false};

        for(int i=1;i<m; i++){
            int z=0; bool flag=false;
            if(grid[i][0]=='X'){z=1; flag=true;}
            else if(grid[i][0]=='Y')z=-1;
            has[i][0].first=has[i-1][0].first+z;
            has[i][0].second=has[i-1][0].second | flag;
        }
         for(int i=1;i<n; i++){
            int z=0; bool flag=false;
            if(grid[0][i]=='X'){z=1; flag=true;}
            else if(grid[0][i]=='Y') z=-1; 
            has[0][i].first=has[0][i-1].first+z;
            has[0][i].second=has[0][i-1].second | flag;
        }

        for(int i=1;i<m;i++){
           for(int j=1;j<n;j++){
                int z=0; bool flag=false;
              if(grid[i][j]=='X') {z=1; flag=true;}
              else if(grid[i][j]=='Y') z=-1;
            has[i][j].first=has[i-1][j].first+has[i][j-1].first-has[i-1][j-1].first+z;
            has[i][j].second=(has[i-1][j].second | has[i][j-1].second) | flag;
            }
        }

        int ans1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(has[i][j].first==0 && has[i][j].second)ans1++;
            }
        }
        return ans1;
    }
};