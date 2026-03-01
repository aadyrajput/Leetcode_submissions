class Solution {
public:
    int m,n,z;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    bool fun(int i,int j,int z,vector<vector<char>>& board, string word){
        if(z==word.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || word[z]!=board[i][j])return false;

        char x=board[i][j];
        board[i][j]='#';
        for(int aa=0;aa<4; aa++){
            if(fun(i+delrow[aa],j+delcol[aa],z+1,board,word))return true;
        }
        board[i][j]=x;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        z=word.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(fun(i,j,0,board,word))return true;
                }
            }
        }

        return false;
    }
};