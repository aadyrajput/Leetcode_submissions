class Solution {
public:
    
bool isValid(int row,int col,char c,vector<vector<char>>&board){
    if(c=='.')return true;
    for(int i=0;i<9;i++)if(board[i][col]==c && i!=row)return false;
    for(int i=0;i<9;i++)if(board[row][i]==c && i!=col)return false;

    int z1=3*(row/3); int z2=3*(col/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[z1+i][z2+j]==c &&  (z1+i)!=row && (z2+j)!=col)return false;
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!isValid(i,j,board[i][j],board))return false;
            }
        }
    return true;
    }
};