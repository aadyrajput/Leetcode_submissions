class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }

private:
bool solve(vector<vector<char>>&board,int x,int y){
    if(x>=9)return true;
    if(y>=9)return solve(board,x+1,0);
    if(board[x][y]!='.') return solve(board,x,y+1);

    for(char a='1'; a<='9'; a++){
        if(isValid(x,y,a,board)){
            board[x][y]=a;
            if(solve(board,x,y+1))return true;
            board[x][y]='.';
        }
    }
    return false;
}

bool isValid(int row,int col,char c,vector<vector<char>>&board){
    for(int i=0;i<9;i++)if(board[i][col]==c)return false;
    for(int i=0;i<9;i++)if(board[row][i]==c)return false;

    int z1=3*(row/3); int z2=3*(col/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[z1+i][z2+j]==c)return false;
        }
    }
    return true;
}


};