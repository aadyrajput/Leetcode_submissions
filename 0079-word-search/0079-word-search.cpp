class Solution {
private:
bool fun(int i,int r,int c,vector<vector<char>>& board, string word){
if(i==word.size())return true;
if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[i]) return false;

char temp=board[r][c]; board[r][c]='#';
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
for(int k=0; k<4; k++){
 int nr=r+dr[k]; int nc=c+dc[k];
  if(fun(i+1,nr,nc,board,word)) return true;
}
board[r][c]=temp;
return false;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> v; char x=word[0];
        for(int i=0;i<board.size(); i++){
            for(int j=0;j<board[0].size(); j++){
                if(board[i][j]==x)v.push_back({i,j});
            }
        }
        if(word.size()==1 && v.size()>0)return true;
        for(int j=0;j<v.size(); j++){
            int r=v[j].first; int c=v[j].second;
           if(fun(0,r,c,board,word)) return true;
        }
        return false;
    }
};