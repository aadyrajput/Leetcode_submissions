class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        if(n==0)return "";
        if(rows==1)return encodedText;
        int col=n/rows;
        string ans="";
        vector<vector<char>> mat(rows,vector<char>(col,' '));
        for(int i=0;i<n; i++){
            int z=i/col;
            int zz=i%col;
            mat[z][zz]=encodedText[i];
        }

        for(int j=0;j<col;j++){
            int left=0; int right=j;
            for(int k=0;k<rows;k++){
              int z=left+k; int zz=right+k;
              if(z<rows && zz<col)
              ans+=mat[z][zz];
            }        
        }
        while(ans.back()==' '){
            ans.pop_back();
        }

        return ans;
    }
};