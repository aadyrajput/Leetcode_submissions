class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
     int m=mat.size();
     int n=mat[0].size();
     set<int> row,col;
     for(int i=0;i<m; i++){
        int ct=0;
        for(int j=0;j<n;j++){
            if(mat[i][j]==1)ct++;
        }
        if(ct==1)row.insert(i);
     }

     for(int j=0;j<n; j++){
        int ct=0;
        for(int i=0;i<m;i++){
            if(mat[i][j]==1)ct++;
        }
        if(ct==1)col.insert(j);
     }

     int ans=0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1 && row.find(i)!=row.end() && col.find(j)!=col.end()) ans++;
        }
     }
     return ans;
     

    }
};