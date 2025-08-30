class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
            if(board[i][j]=='.')continue;
                if(s.find(board[i][j])!=s.end())return false;
                s.insert(board[i][j]);
            }
            s.clear();
        }
      
       for(int j=0; j<9; j++){
            for(int i=0; i<9; i++){
                if(board[i][j]=='.')continue;
                if(s.find(board[i][j])!=s.end())return false;
                s.insert(board[i][j]);
            }
            s.clear();
        }
        
        vector<set<int>> v(9);
        for(int i=0;i<9; i++){
            for(int j=0;j<9; j++){
                if(board[i][j]=='.')continue;
                int z= (i/3)*3 +(j/3);
                if(v[z].find(board[i][j]-'0')!=v[z].end())return false;
                v[z].insert(board[i][j]-'0');
            }
        }
    return true;
    }
};