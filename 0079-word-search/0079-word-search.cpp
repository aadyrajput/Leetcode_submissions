class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    bool fun(int i,int j,int z,string word,vector<vector<char>>&board,vector<vector<int>>&vis){
        if(z==word.size()){
            return true;
        } 
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size()|| board[i][j]!=word[z] || vis[i][j]==1)return false;

        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(fun(ni,nj,z+1,word,board,vis)) return true;
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    int z=0;
                    if(fun(i,j,z,word,board,vis))return true;
                }
            }
        }
    return false;
    }
};